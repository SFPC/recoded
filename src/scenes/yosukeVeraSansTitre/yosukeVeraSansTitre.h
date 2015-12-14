#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yosukeVeraSansTitre : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    const int row = 9;
    const int col = 37;
    const float rectWidth = 10;
    const float rectHeight = 30;
//    float margin = 5;

    ofParameter<float> displacementCoef;
    ofParameter<float> margin;
    ofParameter<float> transx;
    ofParameter<float> transy;
};
