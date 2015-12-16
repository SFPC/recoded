#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraFscene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> frequency, margin, lineWidth, zoom;
    float sizeOfF, lastValue, offset;
    float numberOfF;
    
    void drawf();
    void drawf2();
};
