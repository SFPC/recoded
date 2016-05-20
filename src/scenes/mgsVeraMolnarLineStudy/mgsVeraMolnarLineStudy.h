#pragma once

#include "ofMain.h"
#include "baseScene.h"

class MolnarPainter {
 public:
  float xOffset, yOffset, x, y, startx, starty, lastx, lasty, angle, speed, thickness;
  bool connectedLines, invertColor, useColor;
  ofColor lineColor;
  float size, space, lineMax, lineCounter,shiftCounter,rowCounter, gridWidth, gridHeight;
  ofColor stroke;
  
  void update() {
    glLineWidth(thickness);
    if(lineCounter < lineMax){
      float newx = space+ofRandom(startx+shiftCounter*(size+space), startx+shiftCounter*(size+space)+size);
      float newy = space+ofRandom(starty+rowCounter*(size+space), starty+rowCounter*(size+space)+size);
      if(lineCounter == 0){
        ofSetColor(0);
      }
//      } else if (!useColor){
//        if(connectedLines){
//          ofSetColor(255);
//        } else {
//          ofSetColor(255);
//        }
//      } else {
//        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
//      }
      ofNoFill();
      ofDrawLine(x, y, newx, newy);
      x = newx;
      y = newy;
      lineCounter++;
    } else {
      lineCounter = 0;
      if(shiftCounter < floor(gridWidth)-1) {
        shiftCounter++;
        lastx = x;
        lasty = y;
        x = xOffset+startx+shiftCounter*(size+space);
        y = yOffset+starty+rowCounter*(size+space);
        if(connectedLines){
          if(!useColor){
            ofSetColor(255);
          } else {
            ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
          }
          ofNoFill();
          ofDrawLine(lastx, lasty, x, y);
        }
      } else {
        if(rowCounter < floor(gridHeight)-1){
          shiftCounter = 0;
          rowCounter++;
          lastx = x;
          lasty = y;
          //x = xOffset+startx+shiftCounter*(size+space);
          //y = yOffset+starty+rowCounter*(size+space);
          x = xOffset+startx+shiftCounter*(size+space);
          y = yOffset+starty+rowCounter*(size+space);
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
          x = startx+xOffset;
          y = starty+yOffset;
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
    void clearScreen(bool& i);
    void reset();
  
    ofFbo frame;
    ofParameter<int> numOfLines;
    ofParameter<float> squareSize, gridSpace, lineWidth;
    ofParameter<bool> connectedLinesP, useColorP, animated, clearScreenBool;
};
