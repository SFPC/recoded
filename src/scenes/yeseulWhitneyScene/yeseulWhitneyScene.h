
#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"

class circlesDiffusion{
public:
    circlesDiffusion(float t, float diffSize):diffusionSize(diffSize),bKill(false), startTime(t){}
    
    void draw(float time){
        
        ofPushMatrix();
        
        float y = (time-startTime)*10;
        for (int a=0; a<360; a+=10) {
            ofRotate(10);
            ofDrawCircle(0, y, diffusionSize);
        }
        
        if(y >= VISUALS_WIDTH/2){
            bKill = true;
        }
        
        ofPopMatrix();
    }
    
    float startTime;
    bool bKill;
    float diffusionSize;
};

class yeseulWhitneyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawPattern();
    void diffusion();
    void reset(){
        lastTimeBg = 0;
        lastTimeFg = 0;
        //integratedTime = 0;
        diffs.clear();
        lastDiffusionTime = 0;
    }
    
    
    
    int columnCount, rowCount;
    
    ofParameter<float> diffusionInterval, diffusionSize, spinSpeed;
    vector<circlesDiffusion> diffs;
    
    float lastDiffusionTime;
    float integratedTime, integratedFgTime;
    float lastTimeBg, lastTimeFg;
    
    
};
