#pragma once

#include "ofMain.h"
#include "baseScene.h"

class EstherMolnarScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

	ofParameter<float> color, size, move;

	ofBlendMode blendMode;
};
