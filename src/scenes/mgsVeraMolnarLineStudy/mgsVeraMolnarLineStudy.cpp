#include "mgsVeraMolnarLineStudy.h"

MolnarPainter painter;
//<<<<<<< HEAD
//
//void mgsVeraMolnarLineStudy::setup(){
//  
//  // setup pramaters
//  //    param.set("param", 5, 0, 100);
//  //    parameters.add(param);
//  parameters.add(squareSize.set("Square Size", 62, 1, 100));
//  parameters.add(numOfLines.set("Number of Lines", 12, 1, 50));
//  parameters.add(gridHigh.set("Grid Height", 6, 1, 50));
//  parameters.add(gridWide.set("Grid Width", 6, 1, 50));
//  parameters.add(gridSpace.set("Grid Spacing", 10, 1, 50));
//  parameters.add(lineWidth.set("Line Width", 1.0, 0.1, 10.0));
//  parameters.add(connectedLinesP.set("Connect Lines?", false));
//  parameters.add(invertedColor.set("Invert Color", false));
//  parameters.add(useColorP.set("Use Color", false));
//
//  squareSize.addListener(this, &mgsVeraMolnarLineStudy::redraw);
//  numOfLines.addListener(this, &mgsVeraMolnarLineStudy::redraw);
//  gridHigh.addListener(this, &mgsVeraMolnarLineStudy::redraw);
//  gridWide.addListener(this, &mgsVeraMolnarLineStudy::redraw);
//  gridSpace.addListener(this, &mgsVeraMolnarLineStudy::redraw);
//  connectedLinesP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
//  lineWidth.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
//  invertedColor.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
//
//  painter.thickness = lineWidth;
//  painter.invertColor = false;
//  painter.useColor = false;
//  painter.startx = 5;
//  painter.starty = 5;
//  painter.x = 5;
//  painter.y = 5;
//  painter.gridHeight = gridHigh;
//  painter.gridWidth = gridWide;
//  painter.size = squareSize;
//  painter.lineMax = numOfLines;
//  painter.shiftCounter = 0;
//  painter.rowCounter = 0;
//  painter.angle = 60;
//  //painter.stroke = ofColor(abs(painter.backgroundCounter-255));
//
//  loadCode("mgsVeraMolnarLineStudy/exampleCode.cpp");
//  //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
//  freshPaint();
//  frame.allocate(dimensions.width, dimensions.height);
//  frame.begin();
//  ofClear(0);
//  frame.end();
//=======
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
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  drawScene();
}

void mgsVeraMolnarLineStudy::update(){
//<<<<<<< HEAD
//  drawScene();
//}
//
//void mgsVeraMolnarLineStudy::draw(){
//  frame.draw(0,0);
//}
//
//void mgsVeraMolnarLineStudy::redraw(int& i){
//  frame.begin();
//  ofClear(0);
//  frame.end();
//  freshPaint();
//  drawScene();
//}
//
//void mgsVeraMolnarLineStudy::redrawB(bool& i){
//  frame.begin();
//  ofClear(0);
//  frame.end();
//  freshPaint();
//  drawScene();
//}
//
//void mgsVeraMolnarLineStudy::redrawF(float& i){
//  frame.begin();
//  ofClear(0);
//  frame.end();
//  freshPaint();
//  drawScene();
//}
//
//void mgsVeraMolnarLineStudy::freshPaint(){
//  painter.useColor = useColorP;
//  painter.connectedLines = connectedLinesP;
//  painter.thickness = lineWidth;
//  painter.shiftCounter = 0;
//  painter.rowCounter = 0;
//  painter.lineCounter = 0;
//  painter.x = ofRandom(painter.startx,painter.startx+squareSize);
//  painter.y = ofRandom(painter.startx,painter.startx+squareSize);
//  painter.lastx = painter.startx;
//  painter.lasty = painter.starty;
//  painter.size = squareSize;
//  painter.lineMax = numOfLines;
//  painter.gridWidth = gridWide;
//  painter.gridHeight = gridHigh;
//=======
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
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  painter.space = gridSpace;
}

void mgsVeraMolnarLineStudy::drawScene(){
//<<<<<<< HEAD
//  if(painter.backgroundCounter < 255){
//    painter.backgroundCounter+=30;
//  } else {
//    painter.backgroundCounter = 0;
//  }
//  glLineWidth(painter.backgroundCounter*lineWidth/100);
//  frame.begin();
//  painter.update();
//=======
  frame.begin();
  for(int i = numOfLines; i < numOfLines+1; i++){
    painter.update();
  }
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.end();
}
