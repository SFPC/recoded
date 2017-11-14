#pragma once

#include "ofMain.h"
#include "baseScene.h"


class Bacon {
    
public:
    void setup();
    void update();
    void draw(float amp);
    
    float width;
    float height;
};


class zzBaconScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    Bacon bacon;
    
    float startTime;
    float elapsedTime;
    float duration;
    float pct;
    
    float posA;
    float posB;
    float pos;
    
    ofParameter<float> sineAmp;
    
//    ofParameter<float> param;
};
