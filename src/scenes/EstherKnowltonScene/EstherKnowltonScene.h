#pragma once

#include "ofMain.h"
#include "baseScene.h"

class EstherKnowltonScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
	
	ofImage img;

	ofParameter<float> posX1, rotation, alpha;

};
