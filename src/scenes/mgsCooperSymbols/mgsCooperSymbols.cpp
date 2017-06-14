
#include "mgsCooperSymbols.h"

//<<<<<<< HEAD
//void mgsCooperSymbols::setup() {
//  //parameters.add(fadeLength.set("Fade Length", 10, 1, 255));
//  parameters.add(size.set("Grid Size", 3, 1, 128));
//  parameters.add(numberOfShapes.set("Number of Shapes", 3, 1, 3));
//  //fadeLength.addListener(this, &mgsCooperSymbols::redraw);
//  size.addListener(this, &mgsCooperSymbols::redraw);
//  numberOfShapes.addListener(this, &mgsCooperSymbols::redraw);
//  
//  parameters.add(red.set("Red", 255, 1, 255));
//  parameters.add(green.set("Green", 255, 1, 255));
//  parameters.add(blue.set("Blue", 255, 1, 255));
//  parameters.add(alpha.set("Alpha", 255, 1, 255));
//  
//  red.addListener(this, &mgsCooperSymbols::redraw);
//  green.addListener(this, &mgsCooperSymbols::redraw);
//  blue.addListener(this, &mgsCooperSymbols::redraw);
//  alpha.addListener(this, &mgsCooperSymbols::redraw);
//
//  parameters.add(thickness.set("Line Thickness", 0.1, 0.1, 10.0));
//  thickness.addListener(this, &mgsCooperSymbols::redrawFloat);
//  
//  //parameters.add(arcInsteadOfCircleP.set("Arc Instead Of Circle", false));
//  //arcInsteadOfCircleP.addListener(this, &mgsCooperSymbols::redrawBool);
//
//  parameters.add(randomStrokeP.set("Random Stroke", true));
//  randomStrokeP.addListener(this, &mgsCooperSymbols::redrawBool);
//
//  parameters.add(randomShapesP.set("Random Shape", true));
//  randomShapesP.addListener(this, &mgsCooperSymbols::redrawBool);
//  
//  //parameters.add(secondGridP.set("Second Grid", false));
//  //secondGridP.addListener(this, &mgsCooperSymbols::redrawBool);
//  //ofEnableSmoothing();
//
//  ofSetCircleResolution(100);
//  //path.setCircleResolution(100);
//  loadCode("mgsCooperSymbols/exampleCode.cpp");
//  
//=======
void mgsCooperSymbols::setupParameters(){
  gridSize.set("Grid Size", 32, 1, 96);
  //gridSize.addListener(this, &mgsCooperSymbols::redrawGrid);
  
  parameters.add(numberOfShapes.set("Number of Shapes", 3, 1, 3));
  numberOfShapes.addListener(this, &mgsCooperSymbols::redraw);
  
  parameters.add(red.set("Red Amount", 255, 1, 255));
  red.addListener(this, &mgsCooperSymbols::redraw);
  
  parameters.add(green.set("Green Amount", 255, 1, 255));
  green.addListener(this, &mgsCooperSymbols::redraw);
  
  parameters.add(blue.set("Blue Amount", 255, 1, 255));
  blue.addListener(this, &mgsCooperSymbols::redraw);
  
  parameters.add(thickness.set("Line Width", 0.1, 0.1, 10.0));
  thickness.addListener(this, &mgsCooperSymbols::redrawFloat);
  
  parameters.add(randomStrokeP.set("Random Colored Stroke", false));
  randomStrokeP.addListener(this, &mgsCooperSymbols::redrawBool);
  
  parameters.add(singleShapesP.set("Single Shapes Mode", false));
  singleShapesP.addListener(this, &mgsCooperSymbols::redrawBool);
  
  animated.set("Animated", true);
  //animated.addListener(this, &mgsCooperSymbols::redrawBool);
  
  debug.set("Debug", false);
  //debug.addListener(this, &mgsCooperSymbols::redrawBool);
}

void mgsCooperSymbols::setup() {
  setAuthor("Michael Simpson");
  setOriginalArtist("Muriel Cooper");
  // - 'A Primer Of Visual Literacy' Book Cover - 1973
  setupParameters();
  ofSetCircleResolution(100);
  loadCode("scenes/mgsCooperSymbols/exampleCode.cpp");
  
  cursorColor = ofColor(0,0,255,1);
  clearColor = ofColor(0,0,0,255);
  symbolColor = ofColor(255,255,255,255);
  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
  bNeedsRedraw = bNeedRedrawFullScene = true;
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.allocate(dimensions.width, dimensions.height);
  frame.begin();
  ofClear(0);
  frame.end();
//<<<<<<< HEAD
//  drawScene();
//}
//
//void mgsCooperSymbols::update(){
//    
//=======
  drawFullScene();
  drawScene();
}

void mgsCooperSymbols::reset(){
  cursorColor = ofColor(0,0,255,1);
  clearColor = ofColor(0,0,0,255);
  symbolColor = ofColor(255,255,255,255);
  //drawFullScene();
  //drawScene();
}

void mgsCooperSymbols::update(){
  if (bNeedRedrawFullScene) {
    frame.begin();
    ofClear(0);
    frame.end();
  }
  if(bNeedsRedraw){
    if(animated){
      drawScene();
      incrementCursor();
    } else {
      bNeedsRedraw = false;
    }
  }
  if (bNeedRedrawFullScene) {
    drawFullScene();
    bNeedRedrawFullScene = false;
  }
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
}

void mgsCooperSymbols::draw(){
  frame.draw(0,0);
}

void mgsCooperSymbols::redraw(int& i){
//<<<<<<< HEAD
//  drawScene();
//}
//
//void mgsCooperSymbols::redrawBool(bool& i){
//  drawScene();
//}
//
//void mgsCooperSymbols::redrawFloat(float& i){
//  drawScene();
//=======
  symbolColor = ofColor(red, green, blue);
  //bNeedRedrawFullScene = true;
//  if(animated){
//    bNeedsRedraw = true;
//  }
}

void mgsCooperSymbols::redrawGrid(int& i){
  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
  symbolColor = ofColor(red, green, blue);
  //bNeedRedrawFullScene = true;
//  if(animated){
//    bNeedsRedraw = true;
//  }
}

void mgsCooperSymbols::redrawBool(bool& i){
  //bNeedsRedraw = true;
  //bNeedRedrawFullScene = true;
}

void mgsCooperSymbols::redrawFloat(float& i){
  gw = dimensions.width/gridSize;
  gh = dimensions.height/gridSize;
//  bNeedsRedraw = true;
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
}

void mgsCooperSymbols::drawScene(){
  frame.begin();
// <<<<<<< HEAD
//  glLineWidth(thickness);
//  // if(fadeCount >= fadeLength) {
//  //   ofSetColor(0, fadeLength);
//  //   ofFill();
//  //   ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
//  //   fadeCount = 0;
//  // } else {
//  //ofSetColor(0);
//  //ofFill();
//  //ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
//  //ofSetColor(255, 10);
//  ofClear(0);
//  if(!randomStrokeP){
//    ofSetColor(red,green,blue,alpha);
//    ofNoFill();
//  }
//  drawGrid(0, 0);
//    // if (secondGridP) {
//    //   drawGrid(20, 20);
//    //   drawGrid(40, 20);
//    //   drawGrid(20, 40);
//    //   drawGrid(40, 40);        
//    // }
//    // fadeCount++;
//    // }
//=======
  drawGrid(0,0);
  frame.end();
//  bNeedsRedraw = true;
}

void mgsCooperSymbols::drawFullScene(){
  frame.begin();
  ofClear(0);
  rowCounter = 0;
  shiftCounter = 0;
  drawFullGrid(0,0);
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.end();
}

bool mgsCooperSymbols::randomBool() {
  if (ofRandom(2) > 1) {
    return true;
  } else {
    return false;
  }
}

//<<<<<<< HEAD
//void mgsCooperSymbols::drawSquare(int x, int y, int s) {
//  if (randomStrokeP) {
//    randomStroke();
//  } else {
//    ofSetColor(red,green,blue,alpha);
//    ofNoFill();
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x, y, x+s, y);
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x+s, y, x+s, y+s);
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x+s, y+s, x, y+s);
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x, y+s, x, y);
//  }
//}
//
//void mgsCooperSymbols::drawTri(int x, int y, int s) {
//  if (randomStrokeP) {
//    randomStroke();
//  } else {
//    ofSetColor(red,green,blue,alpha);
//    ofNoFill();
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x+s/2, y, x+s, y+s);
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x+s, y+s, x, y+s);
//  }
//  if (randomBool()) {
//    if (randomStrokeP) {
//      randomStroke();
//    }
//    ofDrawLine(x, y+s, x+s/2, y);
//  }
//}
//
//void mgsCooperSymbols::drawCircle(int x, int y, int s) {
//  ofNoFill();
//  if (randomBool()) {
//    ofDrawCircle(x, y, s);
//  }
//}
//
//void mgsCooperSymbols::randomFill() {
//  int r = (int)ofRandom(red);
//  int g = (int)ofRandom(green);
//  int b = (int)ofRandom(blue);
//  int a = (int)ofRandom(alpha);
//  ofSetColor(r, g, b, a);
//  ofFill();
//}
//
//void mgsCooperSymbols::randomStroke() {
//  int r = ofRandom(red);
//  int g = ofRandom(green); 
//  int b = ofRandom(blue);
//  int a = alpha;
//  ofSetColor(r, g, b, a);
//  ofNoFill();
//}
//
//void mgsCooperSymbols::drawArc(int x, int y, int s) {
//  ofSetColor(red,green,blue,alpha);
//  ofNoFill();
//  //path.moveTo(x,y);
//  if (randomBool()) {
//    curve.begin();
//    curve.arc(ofPoint(x,y), s, s, 0, HALF_PI);
//    curve.end();
//  }
//  if (randomBool()) {
//    curve.begin();
//    curve.arc(ofPoint(x,y), s, s, HALF_PI, PI);
//    curve.end();
//  }
//  if (randomBool()) {
//    curve.begin();
//    curve.arc(ofPoint(x,y), s, s, PI, PI+HALF_PI);
//    curve.end();
//  }
//  if (randomBool()) {
//    curve.begin();
//    curve.arc(ofPoint(x, y), s, s, PI+HALF_PI, TWO_PI);
//    curve.end();
//  }
//  curve.draw();
//}
//
//void mgsCooperSymbols::drawGrid(int x, int y) {
//  float w = dimensions.width/size;
//  float h = dimensions.height/size;
//  
//  for (float c = 0; c < dimensions.width; c+=w) {
//    for (float r = 0; r < dimensions.height; r+=h) {
//      if (randomShapesP) {
//        switch((int)ofRandom(numberOfShapes)) {
//        case 0:
//          drawSquare(c, r, w);
//          break;
//        case 1:
//          drawTri(c, r, w);
//          break;
//        case 2:
//          //if (arcInsteadOfCircleP) {
//          //drawArc(c, r, w);
//            //} else {
//              drawCircle(c+w/2, r+h/2, w/2);
//            //}
//          break;
//        }
//      } else {
//        switch(numberOfShapes) {
//        case 1:
//          drawSquare(c, r, w);
//          break;
//        case 2:
//          drawTri(c, r, w);
//          break;
//        case 3:
//          //if (arcInsteadOfCircleP) {
//          //drawArc(c, r, w);
//            //} else {
//            drawCircle(c+w/2, r+h/2, w/2);
//            //}
//          break;
//=======
void mgsCooperSymbols::drawSquare(float x, float y, float s) {
  ofPushStyle();
  ofSetColor(symbolColor);
  ofNoFill();
  glLineWidth(thickness);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x, y, x+s, y);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x+s, y, x+s, y+s);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x+s, y+s, x, y+s);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x, y+s, x, y);
  if (randomStrokeP) randomStroke();
  ofPopStyle();
}

void mgsCooperSymbols::drawTri(float x, float y, float s) {
  ofPushStyle();
  ofSetColor(symbolColor);
  ofNoFill();
  glLineWidth(thickness);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x+s/2, y, x+s, y+s);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x, y+s, x+s, y+s);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawLine(x, y+s, x+s/2, y);
  ofPopStyle();
}

void mgsCooperSymbols::drawCircle(float x, float y, float s) {
  ofPushStyle();
  ofSetColor(symbolColor);
  ofNoFill();
  glLineWidth(thickness);
  if (randomStrokeP) randomStroke();
  if (randomBool()) ofDrawCircle(x, y, s/1.13);
  ofPopStyle();
}

void mgsCooperSymbols::randomStroke() {
  ofSetColor(ofRandom(red), ofRandom(green), ofRandom(blue), 255);
  ofNoFill();
}

void mgsCooperSymbols::clearCell(float x, float y, float w, float h){
  ofPushStyle();
  ofFill();
  ofSetColor(clearColor);
  ofDrawRectangle(x,y,w,h);
  ofPopStyle();
}

void mgsCooperSymbols::debugGrid(){
  if(debug && animated) {
   clearCell(shiftCounter-1, rowCounter, gw+1, gh);
  }
}

void mgsCooperSymbols::drawCursor(){
  ofPushStyle();
  if(gridSize >= 8){
    if(gw <= dimensions.width){
      ofSetColor(cursorColor);
      ofFill();
      glLineWidth(thickness);
      if(shiftCounter == 0) {
        ofDrawRectangle(shiftCounter,rowCounter,gw,gh);
      } else {
        ofDrawRectangle(shiftCounter+1,rowCounter,gw,gh);
      }
    }
  }
  ofPopStyle();
}

void mgsCooperSymbols::drawGrid(float x, float y) {
  ofPushStyle();
  clearCell(shiftCounter-1,rowCounter,gw+2,gh);
  drawCursor();
  ofSetColor(symbolColor);
  ofNoFill();
  if(randomStrokeP) randomStroke();
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
  ofPopStyle();
}

void mgsCooperSymbols::clearScreen(int r, int g, int b, int a){
  ofPushStyle();
  ofSetColor(r,g,b,a);
  ofFill();
  frame.begin();
  ofDrawRectangle(0,0,dimensions.width,dimensions.height);
  frame.end();
  ofPopStyle();
}

void mgsCooperSymbols::drawFullGrid(float x, float y) {
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
            //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
        }
      }
    }
  }
}

//<<<<<<< HEAD
//void mgsCooperSymbols::drawShape(int x, int y, int s, int mode) {
//  switch(mode) {
//  case 0:
//    drawSquare(x, y, size);
//    break;
//  case 1:
//    drawTri(x, y, size);
//    break;
//  case 2:
//    //if (arcInsteadOfCircleP) {
//    //drawArc(x, y, size);
//    //} else {
//    //drawCircle(x, y, size);
//    drawCircle(x+s/2, x+s/2, s/2);
//      //}
//    break;
//  }
//}
//=======
void mgsCooperSymbols::incrementCursor(){
  if(shiftCounter < dimensions.width-gw) {
      shiftCounter += gw;
  } else {
    if(rowCounter < dimensions.height-gh){
      shiftCounter = 0;
      rowCounter += gh;
    } else {
      shiftCounter = 0;
      rowCounter = 0;
    }
  }
  bNeedsRedraw = true;
}
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
