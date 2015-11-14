#pragma once

#include "ofMain.h"
#include "baseScene.h"

#include <vector>

struct ShapePosition {
    ofVec2f topLeft;
    ofVec2f topRight;
    ofVec2f bottomRight;
    ofVec2f bottomLeft;
};

class veraAnimatedScene : public baseScene {
    
public:
    
    veraAnimatedScene(){};
    void setup();
    void update();
    void draw();
    void drawCode();
    
    vector<vector<vector<ShapePosition>>> pos;
    
    ofParameter<float> size;
    ofParameter<float> smoothing;
    ofParameter<float> opacity;
    vector<float> vols;
};
