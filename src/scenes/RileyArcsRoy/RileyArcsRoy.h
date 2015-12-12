#pragma once

#include "ofMain.h"
#include "baseScene.h"

class RileyArcsRoy : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    


    
    ofParameter<float> thinWideRatio;//, speed, oscMax;
    float minWidth, minSpacing, initTime;
};
