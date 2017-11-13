#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aprilMenkman : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;

    ofParameter<float> stretch;
    ofParameter<int> textSize;
    
     ofParameter<int> Ooo;
    
    
    
//    ofParameter<float> param;
};
