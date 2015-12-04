#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraFscene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> scale;
    
    void drawf();
    void drawf2();
};
