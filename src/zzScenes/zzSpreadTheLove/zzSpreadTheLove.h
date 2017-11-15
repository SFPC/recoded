#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxSvgLoader.h"

class zzSpreadTheLove : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxSvgLoader svg;
    
    
    vector < ofPath > paths;
    
    ofPoint midPt;
    ofColor c;
    ofEasyCam cam;
    
    
    
    ofParameter<float> spreadRotation;
};
