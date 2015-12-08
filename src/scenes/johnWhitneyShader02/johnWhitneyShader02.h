#pragma once

#include "ofMain.h"
#include "baseScene.h"

class johnWhitneyShader02 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofShader shader;
    ofFbo fbo;
    
    ofParameter<float> time;
};