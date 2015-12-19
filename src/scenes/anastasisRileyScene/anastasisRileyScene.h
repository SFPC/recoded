#pragma once

#include "ofMain.h"
#include "baseScene.h"

class anastasisRileyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> param;
    ofParameter<int>   numberOfLines;
};
