#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yingKnowlton : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    int res;
    ofVideoPlayer vidPlayer;
    ofImage sourceImage;
    ofImage originalImage;
    ofImage targetImage;
    ofPoint center;
    float screenScale;
    unsigned char * targetScores;
    float targetScore;

    unsigned char * getSubImage(ofImage &image,
                                int x,
                                int y,
                                int maskSize);
    void setSubImage(ofImage &image,
                     int x,
                     int y,
                     int maskSize,
                     unsigned char * subImage);
    float distance(unsigned char * pixel1,
                   unsigned char * pixel2);
    float getTargetScore();

    void playVideo(int index);


    int current;
    ofParameter < float > mixRatio;
    ofParameter < int > videoNum;
    ofParameter < int > iterations;
    ofDirectory directory;
};
