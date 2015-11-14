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

class triangleScene : public baseScene {
    
    void setup();
    void update();
    void draw();
    
    ofParameter<int> numTriangles;
    
};