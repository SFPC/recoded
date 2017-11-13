#pragma once

#include "ofMain.h"
#include "baseScene.h"

class niklasMolnar : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d);
    
    ofParameter<int> grid;
    float gridW;
    float gridH;
    float framePad;
    float gridUnitW;
    float gridUnitH;
    ofParameter<int> rectCopy;
    float rectCopyScaleX;
    float rectCopyScaleY;
    float scale;
    float rectSizeX;
    float rectSizeY;
    
    ofParameter<float> randMin;
    ofParameter<float> randMax;
    int random;
    
    float timeStamp;
    
    
    
};
