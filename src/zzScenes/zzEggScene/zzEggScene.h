#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzEggScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofImage yolk, orig, mouth;
    float WW, HH;
    
    float curTime;
    float curSpeed;
    
    float deg_;
    
   
    ofParameter<float>move, deg;
    
//    ofParameter<float> param;
};
