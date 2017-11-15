#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzDonutScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofDirectory dir;
    vector < ofImage > images;
    
    ofImage bg;
    
    
    ofParameter<float> xSpeed;
    ofParameter<float> ySpeed;
    ofParameter<float> donutScale;
    
//    ofParameter<float> param;
};
