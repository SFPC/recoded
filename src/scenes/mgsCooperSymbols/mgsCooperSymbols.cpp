
#include "mgsCooperSymbols.h"

void mgsCooperSymbols::setup() {
  parameters.add(gridSize.set("Grid Size", 16, 1, 128));
  gridSize.addListener(this, &mgsCooperSymbols::redraw);

  parameters.add(numberOfShapes.set("Number of Shapes", 3, 1, 3));
  numberOfShapes.addListener(this, &mgsCooperSymbols::redraw);

  parameters.add(red.set("Red Amount", 255, 1, 255));
  parameters.add(green.set("Green Amount", 255, 1, 255));
  parameters.add(blue.set("Blue Amount", 255, 1, 255));
  
  red.addListener(this, &mgsCooperSymbols::redraw);
  green.addListener(this, &mgsCooperSymbols::redraw);
  blue.addListener(this, &mgsCooperSymbols::redraw);
  
  parameters.add(thickness.set("Line Width", 0.1, 0.1, 10.0));
  thickness.addListener(this, &mgsCooperSymbols::redrawFloat);

  parameters.add(randomStrokeP.set("Random Colored Stroke", false));
  randomStrokeP.addListener(this, &mgsCooperSymbols::redrawBool);

  parameters.add(singleShapesP.set("Single Shapes Mode", false));
  singleShapesP.addListener(this, &mgsCooperSymbols::redrawBool);

  parameters.add(animated.set("Animated", true));
  animated.addListener(this, &mgsCooperSymbols::redrawBool);

  parameters.add(debug.set("Debug", false));
  debug.addListener(this, &mgsCooperSymbols::redrawBool);

  ofSetCircleResolution(100);
  loadCode("mgsCooperSymbols/exampleCode.cpp");

  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
  fadeBands = false;
  
  frame.allocate(dimensions.width, dimensions.height);
  frame.begin();
  ofClear(0);
  frame.end();
  drawFullScene();
  drawScene();
}

void mgsCooperSymbols::update(){
  if(fadeBands){
    alpha = sin(ofGetElapsedTimef())*100+130;
  } else {
    alpha = 255;
  }
}

void mgsCooperSymbols::draw(){
  if(animated){
    drawScene();
  }
  frame.draw(0,0);
}

void mgsCooperSymbols::redraw(int& i){
  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
  frame.begin();
  ofClear(0);
  frame.end();
  drawFullScene();
  if(animated){
    drawScene();
  }
}

void mgsCooperSymbols::redrawBool(bool& i){
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
  drawFullScene();
}

void mgsCooperSymbols::redrawFloat(float& i){
  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsCooperSymbols::drawScene(){
  frame.begin();
  glLineWidth(thickness);
  if(randomStrokeP){
    ofSetColor(ofRandom(red),ofRandom(green),ofRandom(blue),ofRandom(alpha));
    ofNoFill();
  } else {
    ofSetColor(255);
    ofNoFill();
  }
  drawGrid(0,0);
  incrementCursor();
  frame.end();
}

void mgsCooperSymbols::drawFullScene(){
  frame.begin();
  glLineWidth(thickness);
  if(randomStrokeP){
    ofSetColor(ofRandom(red),ofRandom(green),ofRandom(blue),ofRandom(alpha));
    ofNoFill();
  } else {
    ofSetColor(255);
    ofNoFill();
  }
  rowCounter = 0;
  shiftCounter = 0;
  drawFullGrid(0,0);
  frame.end();
}

bool mgsCooperSymbols::randomBool() {
  if (ofRandom(2) > 1) {
    return true;
  } else {
    return false;
  }
}

void mgsCooperSymbols::drawSquare(float x, float y, float s) {;
  if (randomStrokeP) {
    randomStroke();
  } else {
    ofSetColor(red,green,blue,alpha);
    ofNoFill();
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x, y, x+s, y);
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x+s, y, x+s, y+s);
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x+s, y+s, x, y+s);
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x, y+s, x, y);
  }
}

void mgsCooperSymbols::drawTri(float x, float y, float s) {
  if (randomStrokeP) {
    randomStroke();
  } else {
    ofSetColor(red,green,blue,alpha);
    ofNoFill();
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x+s/2, y, x+s, y+s);
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x, y+s, x+s, y+s);
  }
  if (randomBool()) {
    if (randomStrokeP) {
      randomStroke();
    }
    ofDrawLine(x, y+s, x+s/2, y);
  }
}

void mgsCooperSymbols::drawCircle(float x, float y, float s) {
  if (randomStrokeP) {
    randomStroke();
  } else {
    ofSetColor(red,green,blue,alpha);
    ofNoFill();
  }
  if (randomBool()) {
    ofDrawCircle(x, y, s/1.13);
  }
}

void mgsCooperSymbols::randomFill() {
  float r = ofRandom(red);
  float g = ofRandom(green);
  float b = ofRandom(blue);
  float a = ofRandom(alpha);
  ofSetColor(r, g, b, a);
  ofFill();
}

 void mgsCooperSymbols::randomStroke() {
   float r = ofRandom(red);
   float g = ofRandom(green); 
   float b = ofRandom(blue);
   float a = alpha;
   ofSetColor(r, g, b, a);
   ofNoFill();
}

void mgsCooperSymbols::drawGrid(float x, float y) {
  // y+=1;
  if(debug){
    ofSetColor(0,255,255,255);
    ofNoFill();
    if(animated){
      ofDrawRectangle(shiftCounter,rowCounter,gw,gh);
    }
    ofSetColor(255,0,0,255);
    ofFill();
    if(animated){
      ofDrawRectangle(shiftCounter,rowCounter,gw,gh);
    }
  }
  if(animated){
    if(gridSize >= 16){
      if(gw <= dimensions.width){
        ofSetColor(0,0,blue,80);
        ofFill();
        ofDrawRectangle(shiftCounter+gw,rowCounter,gw,gh);
      }
    } 
  }
  if(animated){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(shiftCounter,rowCounter,gw,gh);
  }
  ofSetColor(255);
  if(randomStrokeP){
    randomStroke();
  }
  ofNoFill();
  //y-=1;
  if (!singleShapesP) {
    switch((int)ofRandom(1, numberOfShapes+1)) {
    case 1:
      drawSquare(x+shiftCounter, y+rowCounter, gw);
      break;
    case 2:
      drawTri(x+shiftCounter, y+rowCounter, gw);
      break;
    case 3:
      drawCircle(x+shiftCounter+gw/2, y+rowCounter+gh/2, gw/2);
      break;
    }
  } else {
    switch(numberOfShapes) {
    case 1:
      drawSquare(x+shiftCounter, y+rowCounter, gw);
      break;
    case 2:
      drawTri(x+shiftCounter, y+rowCounter, gw);
      break;
    case 3:
      drawCircle(x+shiftCounter+gw/2, y+rowCounter+gw/2, gw/2);
      break;
    }
  }
}

void mgsCooperSymbols::drawFullGrid(float x, float y) {
  ofSetColor(0);
  ofFill();
  ofDrawRectangle(x,y,dimensions.width,dimensions.height);
  ofSetColor(255);
  if(randomStrokeP){
    randomStroke();
  }
  ofNoFill();
  for(float x = 0; x < dimensions.width+gw; x += gw){
    for(float y = 0; y < dimensions.width+gh; y += gh){
   
      if (!singleShapesP) {
        switch((int)ofRandom(1, numberOfShapes+1)) {
        case 1:
          drawSquare(x+shiftCounter, y+rowCounter, gw);
          break;
        case 2:
          drawTri(x+shiftCounter, y+rowCounter, gw);
          break;
        case 3:
          drawCircle(x+shiftCounter+gw/2, y+rowCounter+gh/2, gw/2);
          break;
        }
      } else {
        switch(numberOfShapes) {
        case 1:
          drawSquare(x+shiftCounter, y+rowCounter, gw);
          break;
        case 2:
          drawTri(x+shiftCounter, y+rowCounter, gw);
          break;
        case 3:
          drawCircle(x+shiftCounter+gw/2, y+rowCounter+gh/2, gw/2);
          break;
        }
      }
    }
  }
}

void mgsCooperSymbols::incrementCursor(){
  if(shiftCounter < dimensions.width-gw) {
    if(shiftCounter>0){
      shiftCounter += gw;
    } else {
      shiftCounter += gw;
    }
  } else {
    if(rowCounter < dimensions.height-gh){
      shiftCounter = 0;
      if(rowCounter > 0){
        rowCounter += gw;
      } else {
        rowCounter += gh;
      }
    } else {
      shiftCounter = 0;
      rowCounter = 0;
    }
  }
}
