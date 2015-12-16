

#pragma once 

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGui.h"
#include "appConstants.h"
#include "typographyManager.hpp"



// I take care of scenes.

class sceneManager {

private:

	void nextScene(bool forward);
    
public:
    

    vector < baseScene * > scenes;
    int currentScene;
    
    void setup();
    void update();
    void draw();
    
    void advanceScene();
	void regressScene();
    void screenGrab();
    
    void startScene(int whichScene);
    
    ofFbo sceneFbo;
    ofFbo codeFbo;
    ofxPanel * panel;
    

    
    ofTrueTypeFont font;
    
    typographyManager TM;
    
    int lettersLastFrame;
    long long lastPlayTime;
    
    float lastLetterHeight;
    
    
};
