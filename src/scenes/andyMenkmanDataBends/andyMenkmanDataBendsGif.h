#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxDataBender.h"

class andyMenkmanDataBendsGif : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    ofxDataBender bender;

    ofParameter<int> numberOfLines;
    ofParameter<int> startLine;
};
