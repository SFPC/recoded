#pragma once

#include "ofMain.h"
#include "baseScene.h"

class rachelScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofShader shader;
    
    ofParameter<float> posX, posY, time;
};
