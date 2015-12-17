#pragma once

#include "ofMain.h"
#include "baseScene.h"

class sarahgpRileyCircle : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofPoint center;
    ofPath weeArc;
    
    // dynamic options
    ofParameter<int> numCircles;
    ofParameter<bool> shift;
    ofParameter<int> blue;
    ofParameter<float> angle;
};