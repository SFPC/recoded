#pragma once

#include "ofMain.h"
#include "baseScene.h"

class alexLissamojiWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void drawLissaous();
    
    ofImage bckgImg,eyesImg;

    ofParameterGroup paramsGroup;
    ofParameter<float> pAmp;
    ofParameter<float> pFreq;
    ofParameter<float> pPhase;
    ofParameter<int> pDensity;
    ofParameter<float> pImgScale;
    ofParameter<int> pAnimSpeed;
    ofParameter<int> plissajouRatioX;
    ofParameter<int> plissajouRatioY;

    
    float anim[2];
    int animSpeed[2];
    
    unsigned long int timerLastTime;
        
    ofPoint center;

};
