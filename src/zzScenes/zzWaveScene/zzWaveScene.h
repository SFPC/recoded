#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzWaveScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> heightScale;
    ofParameter<float> movementScale;
    
    
     float adders[8];
//    ofParameter<float> param;
};
