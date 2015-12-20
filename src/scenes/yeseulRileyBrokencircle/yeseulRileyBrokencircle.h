#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yeseulRileyBrokencircle : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawShape();
    void resetSpeedVal();
    
    float speedVal = 0;
    bool bDirection = true;
    int oldNumberOfPatterns;
    
    ofVec2f circle1, circle2, circle3, circle4;

    ofParameter<float> size, speed, rotation;
    ofParameter<int> numberOfPatterns;
};
