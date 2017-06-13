#pragma once

#include "ofMain.h"
#include "baseScene.h"

class MolnarPainter {
 public:
//<<<<<<< HEAD
//  float x, y, startx, starty, lastx, lasty, angle, speed, thickness;
//  bool connectedLines, invertColor, useColor;
//  ofColor lineColor;
//  int size, space, lineMax, lineCounter,shiftCounter,rowCounter, gridWidth, gridHeight, backgroundCounter;
//=======
  float xOffset, yOffset, x, y, startx, starty, lastx, lasty, angle, speed, thickness;
  bool connectedLines, invertColor, useColor;
  ofColor lineColor;
  float size, space, lineMax, lineCounter,shiftCounter,rowCounter, gridWidth, gridHeight;
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  ofColor stroke;
  
  void update() {
    glLineWidth(thickness);
    if(lineCounter < lineMax){
//<<<<<<< HEAD
//      int newx = ofRandom(startx+shiftCounter*(size+space), startx+shiftCounter*(size+space)+size);
//      int newy = ofRandom(starty+rowCounter*(size+space), starty+rowCounter*(size+space)+size);
//      /* if(invertColor){ */
//      /*   ofClear(255); */
//      /*   ofSetColor(0); */
//      /*   ofNoFill(); */
//      /* } else { */
//      /*   ofClear(255); */
//      /*   ofSetColor(0); */
//      /*   ofNoFill(); */
//      /*   ofSetColor(255); */
//      /* } */
//      if(!useColor){
//        ofSetColor(backgroundCounter);
//=======
      float newx = space+ofRandom(startx+shiftCounter*(size+space), startx+shiftCounter*(size+space)+size);
      float newy = space+ofRandom(starty+rowCounter*(size+space), starty+rowCounter*(size+space)+size);
      if(lineCounter == 0){
        ofSetColor(0);
      } else if (!useColor){
        if(connectedLines){
          ofSetColor(255);
        } else {
          ofSetColor(255);
        }
        //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
      } else {
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
      }
      ofNoFill();
      ofDrawLine(x, y, newx, newy);
      x = newx;
      y = newy;
      lineCounter++;
    } else {
      lineCounter = 0;
//<<<<<<< HEAD
//      if(shiftCounter < gridWidth) {
//        shiftCounter++;
//        lastx = x;
//        lasty = y;
//        x = startx+shiftCounter*(size+space);
//        y = starty+rowCounter*(size+space);
//        backgroundCounter = 0;
//        if(connectedLines){
//          if(!useColor){
//            ofSetColor(255-backgroundCounter);
//=======
      if(shiftCounter < floor(gridWidth)-1) {
        shiftCounter++;
        lastx = x;
        lasty = y;
        x = xOffset+startx+shiftCounter*(size+space);
        y = yOffset+starty+rowCounter*(size+space);
        if(connectedLines){
          if(!useColor){
            ofSetColor(255);
            //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
          } else {
            ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
          }
          ofNoFill();
          ofDrawLine(lastx, lasty, x, y);
        }
//<<<<<<< HEAD
//        backgroundCounter = 0;
//      } else {
//        if(rowCounter < gridHeight){
//=======
      } else {
        if(rowCounter < floor(gridHeight)-1){
          //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
          shiftCounter = 0;
          rowCounter++;
          lastx = x;
          lasty = y;
//<<<<<<< HEAD
//          x = startx+shiftCounter*(size+space);
//          y = starty+rowCounter*(size+space);
//          backgroundCounter = 0;
//          if(connectedLines){
//            if(!useColor){
//              ofSetColor(255-backgroundCounter);
//            } else {
//              ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
//=======
          //x = xOffset+startx+shiftCounter*(size+space);
          //y = yOffset+starty+rowCounter*(size+space);
          x = xOffset+startx+shiftCounter*(size+space);
          y = yOffset+starty+rowCounter*(size+space);
          if(connectedLines){
            if(useColor){
              ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
            } else {
              ofSetColor(255);
              //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
            }
            ofNoFill();
            ofDrawLine(lastx, lasty, x, y);
          }
        } else {
          shiftCounter = 0;
          rowCounter = 0;
          lastx = x;
          lasty = y;
//<<<<<<< HEAD
//          x = startx;
//          y = starty;
//          if(connectedLines){
//            if(!useColor){
//              ofSetColor(255-backgroundCounter);
//=======
          x = startx+xOffset;
          y = starty+yOffset;
          if(connectedLines){
            if(!useColor){
              ofSetColor(255);
              //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
            } else {
              ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
            }
            ofNoFill();
            ofDrawLine(lastx, lasty, x, y);
          }
        }
      }
    }
  }
};

class mgsVeraMolnarLineStudy : public baseScene {    
public:
    void setup();
    void update();
    void draw();
    void redraw(int& i);
    void redrawB(bool& i);
    void redrawF(float& i);
    void drawScene();
    void freshPaint();
//<<<<<<< HEAD
//    
//    ofFbo frame;
//    ofParameter<int> squareSize,numOfLines,gridHigh,gridWide,gridSpace;
//    ofParameter<float> lineWidth;
//    ofParameter<bool> connectedLinesP, invertedColor, useColorP;
//=======
    void clearScreen(bool& i);
    void reset();
  
    ofFbo frame;
    ofParameter<int> numOfLines;
    ofParameter<float> squareSize, gridSpace, lineWidth;
    ofParameter<bool> connectedLinesP, useColorP, animated, clearScreenBool;
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
};
