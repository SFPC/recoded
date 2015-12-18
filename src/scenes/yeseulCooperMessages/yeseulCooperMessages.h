#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yeseulCooperMessages : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawText();
    void animateText(ofRectangle rec1, ofRectangle rec2);
    void tensionEffect(ofRectangle rec1, ofRectangle rec2);
    void resetPosition();
    
    ofTrueTypeFont font;
    ofBlendMode blend;
    ofImage texture;
    
    string text1, text2;
    
    float redMove = 0;
    float greenMove = 0;
    float purpleMove = 0;
    int margin = 150;
    
    ofParameter<float> redTextSpeed, greenTextSpeed, purpleTextSpeed, rotation;
};
