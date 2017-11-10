#pragma once

#include "ofMain.h"
#include "baseScene.h"

class niklasWhitneySineWave : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter< int >  xElements;
    ofParameter< int >  yElements;

    float drawElement(float xIn, float yIn, float hIn, float scaleIn);
    ofRectangle containerElement;
    
    float drawYElements(float xIn, float yIn, float wIn, float hIn, float scaleIn);
    ofRectangle containerYElements;
    
    float x[500];
    float w[500];
    float scale[500];
    float totalWidth;
    
    float frame;
    float frameWidth;
    float frameHeight;
    
};
