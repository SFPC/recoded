#pragma once

#include "ofMain.h"
#include "baseScene.h"

class MolnarPainter {
 public:
  float x, y, startx, starty, lastx, lasty, angle, speed, thickness;
  bool connectedLines, invertColor, useColor;
  ofColor lineColor;
  int size, space, lineMax, lineCounter,shiftCounter,rowCounter, gridWidth, gridHeight, backgroundCounter;
  ofColor stroke;
  
  void update() {
    glLineWidth(thickness);
    if(lineCounter < lineMax){
      int newx = ofRandom(startx+shiftCounter*(size+space), startx+shiftCounter*(size+space)+size);
      int newy = ofRandom(starty+rowCounter*(size+space), starty+rowCounter*(size+space)+size);
      if(!useColor){
        if(connectedLines){
          ofSetColor(255);
        } else {
          ofSetColor(backgroundCounter);
        }
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
      if(shiftCounter < gridWidth) {
        shiftCounter++;
        lastx = x;
        lasty = y;
        x = startx+shiftCounter*(size+space);
        y = starty+rowCounter*(size+space);
        backgroundCounter = 0;
        if(connectedLines){
          if(!useColor){
            ofSetColor(255);
          } else {
            ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
          }
          ofNoFill();
          ofDrawLine(lastx, lasty, x, y);
        }
        backgroundCounter = 0;
      } else {
        if(rowCounter < gridHeight){
          shiftCounter = 0;
          rowCounter++;
          lastx = x;
          lasty = y;
          x = startx+shiftCounter*(size+space);
          y = starty+rowCounter*(size+space);
          backgroundCounter = 0;
          if(connectedLines){
            if(useColor){
              ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
            } else {
              ofSetColor(255);
            }
            ofNoFill();
            ofDrawLine(lastx, lasty, x, y);
          }
        } else {
          shiftCounter = 0;
          rowCounter = 0;
          lastx = x;
          lasty = y;
          x = startx;
          y = starty;
          if(connectedLines){
            if(!useColor){
              ofSetColor(255);
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
    
    ofFbo frame;
    ofParameter<int> squareSize,numOfLines,gridHigh,gridWide,gridSpace;
    ofParameter<float> lineWidth;
    ofParameter<bool> connectedLinesP, invertedColor, useColorP, animated;
};
