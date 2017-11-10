#pragma once

#include "ofMain.h"
#include "baseScene.h"

class hyojinVeraMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    int width = dimensions.width;
    int height = dimensions.height;

    int gutter = 10;
    int recNum = 5;
    int gap = 3;
    int recW = (width - gutter*2 - gap*(recNum-1))/recNum;
    int recH = (height - gutter*2 - gap*(recNum-1))/recNum;
    
    ofParameter<float>  hue;
    ofParameter<float>  saturation;
    ofParameter<float>  random;

};
