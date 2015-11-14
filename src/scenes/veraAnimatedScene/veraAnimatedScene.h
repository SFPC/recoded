#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraAnimatedScene : public baseScene {
    
public:

    
    
    veraAnimatedScene(){};
    void setup();
    void update();
    void draw();
    void drawCode();
    
    ofParameter<float> smile;
};
