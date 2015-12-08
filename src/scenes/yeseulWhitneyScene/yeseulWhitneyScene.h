
#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yeseulWhitneyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawPattern(int x, int y);
    
    int columnCount, rowCount;
    
    ofParameter<float> angle;
    ofParameter<int> numberOfPattern, color;
    
    
};