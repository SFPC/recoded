#pragma once

#include "ofMain.h"
#include "baseScene.h"

// based off http://sfpc.streiten.org/post/131178427582/hello-john-whitney-hello-of

class alexLissamojiWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void drawLissaous();
    
    ofImage bckgImg,eyesImg,emojiSheet;

    ofParameterGroup paramsGroup;
    ofParameter<float> pAmp;
    ofParameter<float> pFreq;
    ofParameter<float> pPhase;
    ofParameter<float> pDensity;
    ofParameter<float> pImgScale;
    ofParameter<float> pAnimSpeed;
    ofParameter<float> plissajouRatioX;
    ofParameter<float> plissajouRatioY;

    vector<int> images;
    
    float anim[2];
    int animSpeed[2];
    
    unsigned long int timerLastTime;
        
    ofPoint center;

};
