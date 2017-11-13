#pragma once

#include "ofMain.h"
#include "baseScene.h"

class fernandoWhitney2 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
    ofVideoPlayer player;
};
