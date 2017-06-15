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
    
//<<<<<<< HEAD
//    ofParameter<int> unitSize, shapeMode, contrast;
//    ofFbo frame;
//=======
    //ofParameter<int> unitSize, x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7;
    ofParameter<int> unitSize; 
    ofFbo frame;
    bool bNeedRedraw;
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
};
