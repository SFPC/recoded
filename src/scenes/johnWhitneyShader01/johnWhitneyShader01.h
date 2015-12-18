#pragma once

#include "ofMain.h"
#include "baseScene.h"

class johnWhitneyShader01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofShader shader;
    ofFbo fbo;
    
    float integratedTime;
    float lastTime;
    
    ofParameter<float> speed;
    
    ofParameter<float> redScale, greenScale, blueScale;
    ofParameter<float> redOffset, greenOffset, blueOffset;
};