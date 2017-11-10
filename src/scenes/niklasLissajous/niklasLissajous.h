#pragma once

#include "ofMain.h"
#include "baseScene.h"

class niklasLissajous : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    //layout
    float frame;
    ofParameter<int> numElement;
    ofParameter<float> rotationSpeed;
    ofParameter<float> sinAdder;
    ofParameter<int> innerCopys;
    float scaleElement;
    ofRectangle container;
    float width;
    float height;
    
    //issajous
    void lissajous(float xIn, float yIn, float widthIn, float heightIn, float angleIn);
    ofPolyline myLine;
    float radius;
    float speed;
    float adder;
    float xOrigin;
    float yOrigin;
    float sinAngle;
    float cosAngle;
    float numCopys;
    
};
