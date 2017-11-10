#pragma once

#include "ofMain.h"
#include "baseScene.h"

class diegoScene_01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    

    float time;
    float size;
    
    ofParameter<float> speed, rot2Inc, rot3Inc, noiseScale;
	
};
