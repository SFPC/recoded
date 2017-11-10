#pragma once

#include "ofMain.h"
#include "baseScene.h"

class diegoScene_01 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    int posX;
    int posY;
    int radius;
    float time;
    float size;
    
    float rot1, rot2, rot3;
};
