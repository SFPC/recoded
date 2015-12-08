//recoding Bridget Riley's Cantus Firmus (1972–3)

#pragma once

#include "ofMain.h"
#include "baseScene.h"


class stripe{
public:
    ofColor c;
    float width;
    int x;
};

class cantusFirmusRiley : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> posNoiseSpeed, zoomNoiseSpeed, range;
    
    stripe y,b,p,k,w,g,r;
    vector<stripe> stripes;
    int size;
    float zoomNoise, posNoise, prevZoomNoise, prevPosNoise;
};
