#pragma once

#include "ofMain.h"
#include "baseScene.h"

class olegVeraV : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> thicknessMultiplier;
    ofParameter<float> curveHeight;
    ofParameter<int> elementsAmount;
    ofParameter<float> thickness;
};