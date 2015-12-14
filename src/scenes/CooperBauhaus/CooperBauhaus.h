#pragma once

#include "ofMain.h"
#include "baseScene.h"

class CooperBauhaus : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    ofParameter<float> displacement;
    
    void fontSizeChanged(float &f);
    vector<ofColor> colors;
    
    ofTrueTypeFont font;
    
    string text;
    
};
