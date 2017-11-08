#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "HexagonTrack.h"

class yingTanWhitneyMatrix : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    HexagonTrack1 *hexagonTrack1;
    HexagonTrack1 *hexagonTrack2;
    HexagonTrack1 *hexagonTrack3;

    ofParameter<float> time_scale;
    ofParameter<float> spacing;

    float time;
};
