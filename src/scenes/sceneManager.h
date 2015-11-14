

#pragma once 

#include "ofMain.h"
#include "baseScene.h"

// I take care of scenes.

class sceneManager {
    
public:
    
    vector < baseScene * > scenes;
    int currentScene;
    
    void setup();
    void update();
    void draw();
    
    void advanceScene();

};