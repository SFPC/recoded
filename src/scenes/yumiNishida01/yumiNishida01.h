#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yumiNishida01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    int x;
    int line_number;
    vector <ofMesh> lines;
    
    //Gui
//    ofxPanel gui;
    ofParameter<float> x_, y_, color, lineWidth;
    
    void reset();
};
