#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mgsRileyEllipsesAndSquares : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void redraw(int& i);
    void drawScene();
    
    //ofParameter<int> unitSize, x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7;
    ofParameter<int> unitSize; 
    ofFbo frame;
    bool bNeedRedraw;
};
