#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mgsRileyDiamonds : public baseScene {
    
public:
    void setup();
    void update();
    void draw();
    void redraw(int& i);
    void redrawFloat(float& i);
    void redrawBool(bool& i);
    void drawRiley();
    void drawFullRiley();
    
    //    ofParameter<float> param;
    ofParameter<float> height, width;
    ofParameter<int> red, green, blue, alpha;
    ofParameter<bool> grayscale, animated, discoMode;
    /* sequentialShading */
    ofFbo frame;
    float gh, gw;
    int counter = 0;
    vector<float> colorArray;
    float shiftCounter = 0;
    float rowCounter = 0;
    float diamondCounter = 0;
    
    bool bNeedRedraw, bNeedsFullRedraw, bNeedRedrawFloat;
};
