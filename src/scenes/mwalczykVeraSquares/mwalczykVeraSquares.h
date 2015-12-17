#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mwalczykVeraSquares : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void addPointBetween(ofPoint &a, ofPoint &b, int numToAdd, ofPolyline &polyLine);
    
    
    //--------------------------------------------------------------
    // These parameters can be animated / adjusted
    ofParameter<float> PCT_JITTER;// =          0.90f;      // Looks good for most values between 0 and 1
    ofParameter<float> MAX_OFFSET;// =          8.0f;       // Looks good between ~ 0 and 8
    ofParameter<float>   MAX_TRANSLATION;// =       10;         // Looks good between ~ 0 and 10
    //--------------------------------------------------------------
    
    ofParameter<float> jitterNoiseZ, translationNoiseZ;
    
    
    const int NUM_SQUARES =             40;
    const int MAX_SUBDIVISIONS =        10;
    vector<ofPolyline>                  mSquares;
    ofColor                             mSquareColor;
    ofFbo                               mSquareFbo;
    //ofImage                             mPaperTexture;
    
};