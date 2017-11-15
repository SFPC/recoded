#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxSvgLoader.h"


class zzEatRepeatScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofxSvgLoader svg;
    
    
    vector < ofPath > paths;
    
    ofPoint midPt;
    ofColor c;
    ofEasyCam cam;
    
    float timeAdder;
    float timeAdderY;
    float timeAdderZ;
    
    ofParameter<float> amtRotateZ;
    ofParameter<float> amtRotateX;
    ofParameter<float> amtRotateY;
};
