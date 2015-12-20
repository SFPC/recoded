#include "mgsVeraMolnarLineStudy.h"

MolnarPainter painter;
int maxLineCount, currentLineCount;

void mgsVeraMolnarLineStudy::setup(){
  squareSize.set("Square Size", 49.7925, 1, 49.7925);
  //squareSize.addListener(this, &mgsVeraMolnarLineStudy::redrawF);

  parameters.add(numOfLines.set("Number of Lines", 8, 1, 50));
  numOfLines.addListener(this, &mgsVeraMolnarLineStudy::redraw);

  gridSpace.set("Grid Spacing", 10.0, 1, 50);
  //gridSpace.addListener(this, &mgsVeraMolnarLineStudy::redrawF);

  parameters.add(lineWidth.set("Line Width", 1.0, 0.1, 10.0));
  lineWidth.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  
  connectedLinesP.set("Connect Lines?", false);
//  connectedLinesP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
  
  parameters.add(useColorP.set("Use Color", false));
  useColorP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
  
  animated.set("Animated", true);
//  animated.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  clearScreenBool.set("Clear Screen", false);
//  clearScreenBool.addListener(this, &mgsVeraMolnarLineStudy::clearScreen);

  painter.thickness = lineWidth;
  painter.useColor = false;

  painter.xOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;
  painter.yOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;


  painter.stroke = ofColor(255);

  setAuthor("Michael Simpson");
  setOriginalArtist("Vera Molnar");

  loadCode("scenes/mgsVeraMolnarLineStudy/exampleCode.cpp");

  frame.allocate(dimensions.width, dimensions.height, GL_RGBA32F_ARB);
  frame.begin();
  ofClear(0);
  frame.end();
  freshPaint();
  drawScene();
}

void mgsVeraMolnarLineStudy::update(){
  if(animated){
    drawScene();
  }
}

void mgsVeraMolnarLineStudy::draw(){
  frame.begin();
//  if(clearScreenBool) {
//    frame.begin();
//    ofClear(0);
//    frame.end();
//  }
  if(getFrameNum() % 2 == 0){
    ofSetColor(0,1);
    ofDrawRectangle(0,0, dimensions.width, dimensions.height);
  }
  frame.end();
  frame.draw(0, 0);
}

void mgsVeraMolnarLineStudy::clearScreen(bool& i){
  //clearScreenBool = !clearScreenBool;
}

void mgsVeraMolnarLineStudy::redraw(int& i){
  freshPaint();
}

void mgsVeraMolnarLineStudy::reset(){
  //  freshPaint();
}

void mgsVeraMolnarLineStudy::redrawB(bool& i){
  painter.useColor = useColorP;
  painter.connectedLines = connectedLinesP;
}

void mgsVeraMolnarLineStudy::redrawF(float& i){
  painter.xOffset = (dimensions.width - floor(dimensions.width/squareSize)*squareSize)/2;
  painter.yOffset = (dimensions.height - floor(dimensions.height/squareSize)*squareSize)/2;
  freshPaint();
}

void mgsVeraMolnarLineStudy::freshPaint(){
  painter.thickness = lineWidth;
  painter.useColor = useColorP;
  painter.connectedLines = connectedLinesP;
  painter.thickness = lineWidth;
//  painter.x = ofRandom(painter.lastx,painter.lastx+squareSize);
//  painter.y = ofRandom(painter.lasty,painter.lasty+squareSize);
//  painter.lastx = painter.startx;
//  painter.lasty = painter.starty;
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
