#pragma once

#include "ofMain.h"
#include "baseScene.h"

class johnWhitneyShader02 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void reset();

    ofShader shader;
    ofFbo fbo;
    
    float integratedTime;
    float lastTime;
    
    ofParameter<float> speed;
    ofParameter<float> thickness;
};
