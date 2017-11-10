#pragma once

#include "ofMain.h"
#include "baseScene.h"

class weiMolnar_01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> xOffset;
    ofParameter<float> yOffset;
	ofParameter<float> speed;
};
