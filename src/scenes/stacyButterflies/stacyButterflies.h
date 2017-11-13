#pragma once

#include "ofMain.h"
#include "baseScene.h"

class Butterfly {
    public:
        void setup(float width, float height);
        void draw();
    
        ofPoint loc;
        ofColor color;
        float angle;
        float speed;
        ofTrueTypeFont font;
};


class stacyButterflies : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
	ofEasyCam easycam;
    vector<Butterfly> butterflies;
//    ofParameter<float> param;
};
