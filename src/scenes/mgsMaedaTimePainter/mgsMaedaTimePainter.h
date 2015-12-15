#pragma once

#include "ofMain.h"
#include "baseScene.h"

class TimePainter {
 public:
  float startx, xpos, starty, ypos, startAngle, angle, speed, lineWidth;
  int startLongevity, longevity, startSize, size, newSize;
  ofColor stroke, fill;
  
  TimePainter (float s, int l, int z, int lw) {
    lineWidth = lw;
    xpos = ofRandom(50,200);
    startx = xpos;
    ypos = ofRandom(10,100);
    starty = ypos;
    angle = ofRadToDeg(60);
    startAngle = angle;
    speed = s;
    longevity = l;
    startLongevity = l;
    stroke = ofColor(ofRandom(33,255),ofRandom(33,255),ofRandom(33,255));
    size = z;
    startSize = z;
    newSize = z+5;
  }
  
  void reset() {
    xpos = startx;
    ypos = starty;
    angle = startAngle;
    longevity = startLongevity;
    size = startSize;
  }
  
  void update(int currentPainter) { 
    if (longevity < 500) {
      if ((int)ofRandom(10) >= 4) {
        angle += ofDegToRad((int)ofRandom(-2, 2));
      }
    }
    xpos += cos(angle) / speed;
    ypos += sin(angle) / speed;
    longevity--;
    ofSetColor(stroke);
    ofFill();
    glLineWidth(lineWidth);
    //ofDrawRectangle(xpos, ypos, lineWidth, lineWidth);
    ofDrawEllipse(xpos, ypos, lineWidth, lineWidth);
    if (longevity == 0) {
      ofDrawEllipse(xpos, ypos, size*2, size*2);
    }
    //if (longevity == 0) {
    //  ;
    //}
  }
};

class mgsMaedaTimePainter : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void redraw(int& i);
    void redrawInt(int& i);
    void redrawFloat(float& i);
    void drawScene();
    
    ofFbo frame;
    ofParameter<float> paintSpeed, lineWeight;
    ofParameter<int> baseLongevity, size;
};
