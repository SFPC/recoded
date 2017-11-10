#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxDelaunay.h"
#include "ofxPoissonDiskSampling.h"

class jacobsonMolnar_01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
    float framePad;
    float density;
    
    ofPoint origin;
    ofPoint center;
    
    ofxDelaunay triangulation;
    
    ofParameter<float> stepSizeMin;
    ofParameter<float> stepSizeMax;
    ofParameter<float> noiseResolution;
    ofParameter<float> timeScale;
    
};
