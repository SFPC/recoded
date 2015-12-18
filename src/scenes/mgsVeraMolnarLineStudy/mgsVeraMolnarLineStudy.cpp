#include "mgsVeraMolnarLineStudy.h"

MolnarPainter painter;
int maxLineCount, currentLineCount;

void mgsVeraMolnarLineStudy::setup(){
  parameters.add(squareSize.set("Square Size", 59.0, 1, 100));
  squareSize.addListener(this, &mgsVeraMolnarLineStudy::redrawF);

  parameters.add(numOfLines.set("Number of Lines", 15, 1, 50));
  numOfLines.addListener(this, &mgsVeraMolnarLineStudy::redraw);

  parameters.add(gridSpace.set("Grid Spacing", 10.0, 1, 50));
  gridSpace.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  

  parameters.add(lineWidth.set("Line Width", 1.0, 0.1, 10.0));
  lineWidth.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  
  parameters.add(connectedLinesP.set("Connect Lines?", false));
  connectedLinesP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
  
  parameters.add(useColorP.set("Use Color", false));
  useColorP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  
  parameters.add(animated.set("Animated", true));
  animated.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  parameters.add(clearScreenBool.set("Clear Screen", false));
  clearScreenBool.addListener(this, &mgsVeraMolnarLineStudy::clearScreen);

  painter.thickness = lineWidth;
  painter.useColor = false;

  painter.xOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;
  painter.yOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;


  painter.stroke = ofColor(255);

  setAuthor("Michael Simpson");
  setOriginalArtist("Vera Molnar");

  loadCode("scenes/mgsVeraMolnarLineStudy/exampleCode.cpp");

  freshPaint();
  frame.allocate(dimensions.width, dimensions.height, GL_RGBA32F_ARB);
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsVeraMolnarLineStudy::update(){
  if(animated){
    drawScene();
  }
}

void mgsVeraMolnarLineStudy::draw(){
  frame.begin();
  if(getFrameNum() % 2 == 0){
    ofSetColor(0,1);
    ofDrawRectangle(0,0, dimensions.width, dimensions.height);
  }
  frame.end();
  frame.draw(painter.xOffset, painter.yOffset);
}

void mgsVeraMolnarLineStudy::clearScreen(bool& i){
  clearScreenBool = !clearScreenBool;
  frame.begin();
  ofClear(0);
  frame.end();
}

void mgsVeraMolnarLineStudy::redraw(int& i){
  frame.begin();
  ofClear(0);
  frame.end();
  freshPaint();
  drawScene();
}

void mgsVeraMolnarLineStudy::redrawB(bool& i){
  painter.useColor = useColorP;
  painter.connectedLines = connectedLinesP;
  if(animated){
      drawScene();
  }
}

void mgsVeraMolnarLineStudy::redrawF(float& i){
  painter.xOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;
  painter.yOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;
  freshPaint();
}

void mgsVeraMolnarLineStudy::freshPaint(){
  painter.useColor = useColorP;
  painter.connectedLines = connectedLinesP;
  painter.thickness = lineWidth;
  painter.x = ofRandom(painter.startx,painter.startx+squareSize);
  painter.y = ofRandom(painter.starty,painter.starty+squareSize);
  painter.lastx = painter.startx;
  painter.lasty = painter.starty;
  painter.size = squareSize;
  painter.lineMax = numOfLines;
  painter.gridWidth = dimensions.width/(squareSize+gridSpace);
  painter.gridHeight = dimensions.height/(squareSize+gridSpace);
  painter.space = gridSpace;
}

void mgsVeraMolnarLineStudy::drawScene(){
  frame.begin();
  for(int i = numOfLines; i < numOfLines+1; i++){
    painter.update();
  }
  frame.end();
}
