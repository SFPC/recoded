#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzWatermelonScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofImage bg;
    ofImage imgs[6];
    
//    ofParameter<float> param;
};
