#pragma once

#include "ofMain.h"
#include "baseScene.h"

class runchalMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
	
	ofPolyline line;
    ofPolyline slopeLine;
    ofParameter<float> emotion, height, width, length;
	
};
