#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zzSushiScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;

    ofTrueTypeFont font;
    ofPoint center;
    ofRectangle bounds;
    vector<ofTTFCharacter> characters;
    ofImage sushiImage;

    float sushiScale;
    float scale;

    static int const imageCount = 14;
    ofImage images[imageCount];

    ofParameter <float> imageScale;
    ofParameter <float> widthScale;
    ofParameter <int> drawEvery;

    void drawAlongLine(ofPolyline &polyline);
};
