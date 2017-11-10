#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hyojinJohnWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    float time;
    float cirSize;
    float cosVal;
    float sinVal;
    int keyCounter;
    float breath;
    
    ofParameter<float> amount;
    ofParameter<float> speed;
    ofParameter<float> cosine;
};
