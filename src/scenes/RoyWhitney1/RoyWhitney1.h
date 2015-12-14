#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"
class RoyWhitney1 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void drawCircles(ofVec3f center, float radius, float time, float size, int numCircles, int currentIteration = 0);
    ofParameter<float> radius0, size0, multiplier, speed, lineWidth;//, currentTime, currentSize;
    ofParameter<int> circles, opacity;
    int iterations;

};
