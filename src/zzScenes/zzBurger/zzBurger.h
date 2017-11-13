#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzBurger : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> xAmp;
    ofParameter<float> yAmp;
    ofParameter<float> xFreq;
    ofParameter<float> yFreq;
    
    vector<ofImage> assets;
    float xTime;
    float yTime;
};
