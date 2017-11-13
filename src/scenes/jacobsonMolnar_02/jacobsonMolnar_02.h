#pragma once

#include "ofMain.h"
#include "baseScene.h"

class jacobsonMolnar_02 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
    
    ofPath getLineFill(ofPolyline _p, float _s, float _t);
    
    float framePad;
    int countBoxes;
    vector<ofPath> grid;
    
    ofParameter<float> stepSize;
    ofParameter<float> rotationSpeed;
};
