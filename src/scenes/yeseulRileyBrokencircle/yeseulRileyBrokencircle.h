#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yeseulRileyBrokencircle : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawShape();
    void resetSpeedVal(int& i);
    
    ofParameter<float> size, speed, rotation;
    ofParameter<int> numberOfPatterns;
};
