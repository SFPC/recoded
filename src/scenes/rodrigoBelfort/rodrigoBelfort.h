#pragma once

// Recoding of "Untitled 7" by Belfort Group, 1976
// Original processing code by Rodrigo Carvalho
//   (available in bin/data/rodrigoBelfort/)
// Translated to openFrameworks by Chris Anderson

#include "ofMain.h"
#include "baseScene.h"

#define BELFORT_COLS        75
#define BELFORT_ROWS        47

class rodrigoBelfort : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void reset();
    
    float rectSize, paddingSizeX, paddingSizeY;
    
    int dots[BELFORT_ROWS][BELFORT_COLS];
    
    ofParameter<float> pNewLine;
    
    ofParameter<float> timeBtwnLines;
    float lastLineTime;
};