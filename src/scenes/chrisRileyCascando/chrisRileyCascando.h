#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"

typedef enum diamondType {
    straight,
    moreBlack,
    moreWhite
} diamondType;

class chrisRileyCascando : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void reset();
    
    ofParameter<float> triScale, noiseScale, pStraight, animSpeed;

    float integratedTime;
    float lastTime;
    
    ofPath diamondStraightBlack, diamondStraightWhite, diamondArcBlack, diamondArcWhite;
};