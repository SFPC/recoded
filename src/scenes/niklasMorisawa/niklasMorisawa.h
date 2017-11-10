#pragma once

#include "ofMain.h"
#include "baseScene.h"

#define SPEED 0.3

class textSqueez{
    
public:
    
    void setup();
    void update();
    void draw(int counterIn);
    
    ofTrueTypeFont myType;
    ofRectangle bound1;
    ofRectangle bound2;
    float diffW1to2;
    
    float startTime;
    float durationP;
    float durationS;
    int counter;
    int counter2;
    
    float widthA;
    float widthB;
    float scaleA1;
    float scaleA2;
    float scaleB1;
    float scaleB2;
    
    vector <ofMesh> word1;
    vector <ofMesh> word2;
};

class niklasMorisawa : public baseScene {

public:
    
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont myFont;
    ofParameter<int> pattern;
    ofParameter<int> remainder;


//    ofParameter<int> numElements;
    
    ofRectangle myRect;
    textSqueez myText;
    
    
    
};
