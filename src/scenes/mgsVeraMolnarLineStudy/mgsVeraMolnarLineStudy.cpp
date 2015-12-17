#include "mgsVeraMolnarLineStudy.h"

MolnarPainter painter;

void mgsVeraMolnarLineStudy::setup(){
  
  // setup pramaters
  //    param.set("param", 5, 0, 100);
  //    parameters.add(param);
  parameters.add(squareSize.set("Square Size", 62.0, 1, 100));
  parameters.add(numOfLines.set("Number of Lines", 15, 1, 50));
  parameters.add(gridSpace.set("Grid Spacing", 10.0, 1, 50));
  parameters.add(lineWidth.set("Line Width", 1.0, 0.1, 10.0));
  parameters.add(connectedLinesP.set("Connect Lines?", false));
  //  parameters.add(invertedColor.set("Invert Color", false));
  parameters.add(useColorP.set("Use Color", false));
  useColorP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  parameters.add(animated.set("Animated", true));
  animated.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  squareSize.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  numOfLines.addListener(this, &mgsVeraMolnarLineStudy::redraw);
  gridSpace.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  connectedLinesP.addListener(this, &mgsVeraMolnarLineStudy::redrawB);
  lineWidth.addListener(this, &mgsVeraMolnarLineStudy::redrawF);
  //invertedColor.addListener(this, &mgsVeraMolnarLineStudy::redrawB);

  painter.thickness = lineWidth;
  painter.invertColor = false;
  painter.useColor = false;
  painter.startx = 5;
  painter.starty = 5;
  painter.x = 5;
  painter.y = 5;
  painter.gridWidth = dimensions.width/squareSize - 1;
  painter.gridHeight = dimensions.height/squareSize - 1;
  painter.size = squareSize;
  painter.lineMax = numOfLines;
  painter.shiftCounter = 0;
  painter.rowCounter = 0;
  painter.angle = 60;
  //painter.stroke = ofColor(abs(painter.backgroundCounter-255));

  setAuthor("Michael Simpson");
  setOriginalArtist("Vera Molnar");

  loadCode("scenes/mgsVeraMolnarLineStudy/exampleCode.cpp");
  //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
  freshPaint();
  frame.allocate(dimensions.width, dimensions.height);
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsVeraMolnarLineStudy::update(){
  
}

void mgsVeraMolnarLineStudy::draw(){
  if(animated){
    drawScene();
  }
  frame.draw(0,0);
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
  frame.begin();
  ofClear(0);
  frame.end();
  freshPaint();
  drawScene();
}

void mgsVeraMolnarLineStudy::freshPaint(){
  painter.useColor = useColorP;
  painter.connectedLines = connectedLinesP;
  painter.thickness = lineWidth;
  painter.shiftCounter = 0;
  painter.rowCounter = 0;
  painter.lineCounter = 0;
  painter.x = ofRandom(painter.startx,painter.startx+squareSize);
  painter.y = ofRandom(painter.startx,painter.startx+squareSize);
  painter.lastx = painter.startx;
  painter.lasty = painter.starty;
  painter.size = squareSize;
  painter.lineMax = numOfLines;
  painter.gridWidth = dimensions.width/(squareSize+gridSpace) - 1;
  painter.gridHeight = dimensions.height/(squareSize+gridSpace) - 1;
  painter.space = gridSpace;
}

void mgsVeraMolnarLineStudy::drawScene(){
  if(painter.backgroundCounter < 255){
    painter.backgroundCounter += 20;
  } else {
    painter.backgroundCounter = 0;
  }
  glLineWidth(painter.backgroundCounter*lineWidth/100);
  frame.begin();
  for(int i = numOfLines; i < numOfLines+1; i++){
    painter.update();
  }
  frame.end();
}
