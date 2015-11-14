

#pragma once 

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGui.h"
#include "appConstants.h"


enum drawMode {
    DRAW_SIDE_BY_SIDE, DRAW_SINGLE
};

// I take care of scenes.

class sceneManager {
    
public:
    

    vector < baseScene * > scenes;
    int currentScene;
    
    void setup();
    void update();
    void draw();
    
    void advanceScene();
    
    ofFbo sceneFbo;
    ofFbo codeFbo;
    ofxPanel * panel;
    
    drawMode mode;
    
};