//
//  triangleScene.hpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class robbyMenkmanScene : public baseScene {
    
    void setup();
    void update();
    void draw();
    
    ofImage image;
    ofBuffer buffer;
    ofBuffer originalBuffer;
    
    unsigned long nextGlitchMoment;
    unsigned long lastBufferLoad;
    
    ofParameter<int> speedParameter;
    ofParameter<int> chunkParameter;
    
    void loadImageBuffer();
    void glitchImage();

};