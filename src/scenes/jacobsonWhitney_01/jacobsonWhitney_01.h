#pragma once

#include "ofMain.h"
#include "baseScene.h"

class jacobsonWhitney_01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofImage img;
    
    ofParameter<float> imageSize;
    ofParameter<float> rotationSpeed;
    ofParameter<float> phaseShift;
    
};
