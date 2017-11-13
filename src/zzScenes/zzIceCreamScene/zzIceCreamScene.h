#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzIceCreamScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofParameter < float > nPts;
    ofParameter < float > minSize;
    ofParameter < float > maxSize;
    
    vector < ofImage > iceCreams;

    typedef struct {
        ofPoint pt;
        int index;
    } iceCreamPoint;
    
    vector < iceCreamPoint > pts;

//    ofParameter<float> param;
};
