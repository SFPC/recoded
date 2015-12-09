//
//  janVantommeScene.h
//  d4nSFPCRunner
//
//  Created by Jan Vantomme on 07/12/15.
//
//
#pragma once

#include "ofMain.h"
#include "baseScene.h"

class janVantommeScene : public baseScene {

private:
    int numBlocksHorizontal;
    int numBlocksVertical;
    
    float blockSize;
    
    int h1;
    int h2;
    int h3;
    
    int probability;
    
    bool redrawScene;

    ofFbo sceneFBO;
    
    int startTime;
    int elapsedTime;
    ofParameter<int> triggerTime;
    int triggerRedraw;

public:
    void setup();
    void update();
    void draw();
    
};