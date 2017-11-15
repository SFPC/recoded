#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxSvgLoader.h"


class zzNomScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofxSvgLoader svg;
    
    vector < ofPolyline > lines;
    
    vector < ofPath > paths;
    
    
    ofParameter<float> wavyAmt;
};
