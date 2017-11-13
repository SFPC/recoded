#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzPixelBurger : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> chaos;
    
    vector<ofColor> burgerColors;
    vector<float> burgerHeights;
    vector<ofRectangle> burgerLayers;
};
