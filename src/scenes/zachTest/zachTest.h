#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zachTest : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> radius;
    ofParameter<float> xPos;
    ofParameter<float> yPos;
};
