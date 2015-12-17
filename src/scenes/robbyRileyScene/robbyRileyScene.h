#pragma once

#include "ofMain.h"
#include "baseScene.h"

class robbyRileyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawCode();
    
    ofParameter<float> dent, time, scale;
};