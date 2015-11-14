
#pragma once

#include "ofMain.h"
#include "baseScene.h"

class exampleScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> angle;
    ofParameter<float> width;
    
    
};