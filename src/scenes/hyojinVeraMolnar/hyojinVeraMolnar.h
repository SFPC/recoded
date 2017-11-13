#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hyojinVeraMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    int width;
    int height;
    
    int gutter;
    int recNum;
    int gap;
    int recW;
    int recH;
    
    ofParameter<float>  hue;
    ofParameter<float>  saturation;
    ofParameter<float>  random;
};
