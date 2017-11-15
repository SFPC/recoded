#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "emoji.hpp"

class zzCloudyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    // emoji rain
    ofImage cookie;
    ofImage cupcake;
    ofImage donut;
    ofImage popsicle;
    ofImage strawberry;
    
    vector < ofImage > icons;
    
    //ofImage icons[5];
    
    int total_emojis = 0;
    
    float lastCreationTime;
    float creationDelay = .5;
    
    vector < Emoji > my_emojis;
    
    //ofxPanel panel;
    //ofParameterGroup group;
    
    ofParameter < float > cloud_size;
    ofParameter < float > emojiSpeed;
    ofParameter < float > jiggle;
    
    float time;
    float y_fall;
//    ofParameter<float> param;
};
