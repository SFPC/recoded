#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yosukeVeraSansTitre : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    float rectWidth = 10;
    float rectHeight = 30;
    float spacingX;
    float spacingY;
    float gridLeft;
    float gridTop;
    
    ofPoint centerOfmostTopLeftRect;
    ofPoint topLeftOfmostTopLeftRect;

    ofParameter<float> displacementCoef, displacementZ;
    ofParameter<int> row;
    ofParameter<int> colmn;
    ofParameter<float> spacingPercentX;
    ofParameter<float> spacingPercentY;
    ofParameter<float> lineWidth;
};
