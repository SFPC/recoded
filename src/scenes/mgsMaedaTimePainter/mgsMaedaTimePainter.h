#pragma once

#include "ofMain.h"
#include "baseScene.h"

class TimePainter {
 public:
  float startx, xpos, starty, ypos, startAngle, angle, speed, lineWidth;
  int startLongevity, longevity, startSize, size, newSize;
  ofColor stroke, fill;
  ofPolyline path;
  
  TimePainter (float s, int l, int z, int lw) {
    lineWidth = lw;
    xpos = ofRandom(25,75);
    startx = xpos;
    ypos = ofRandom(25,75);
    starty = ypos;
    angle = ofRadToDeg(60);
    startAngle = angle;
    speed = s;
    longevity = ofRandom(l*.4,l*1.0);
    startLongevity = l;
    stroke = ofColor::fromHsb(ofRandom(0,255),ofRandom(200,255),ofRandom(200,255));
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
    path.clear();
  }
  
  void update(int currentPainter, int av) { 
    if (longevity < 500) {
      if (ofRandom(10) > 7) {
        angle += ofDegToRad((int)ofRandom(-av, av));
      }
    }
    xpos += cos(angle) / speed;
    ypos += sin(angle) / speed;
    longevity--;
    ofSetColor(stroke);
    ofFill();
    glLineWidth(lineWidth);
    path.begin();
    path.addVertex(ofPoint(xpos, ypos));
    path.end();
    path.draw();
    
    //ofDrawEllipse(xpos, ypos, lineWidth, lineWidth);
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
    void redrawBool(bool& i);
    void drawScene();
    void clearScreen(bool& i);
    void pause(bool& i);
    
    
    ofFbo frame;
    ofParameter<float> paintSpeed, lineWeight;
    ofParameter<int> baseLongevity, angleVariance;
    ofParameter<bool> fadeWhenDead, clearScreenP, animated;
    bool paused = false;
    bool bNeedsRedraw, bNeedClearScreen;
    
};
