

#pragma once 

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGui.h"
#include "appConstants.h"
#include "typographyManager.hpp"

#ifdef USE_MIDI_PARAM_SYNC
#include "ofxParameterMidiSync.h"
#endif

#ifdef USE_EXTERNAL_SOUNDS
#include "ofxOsc.h"
#define HOST "localhost"
#define PORT 12345 // listen on port 12345
#endif

#ifdef USE_SCENE_TRANSITIONS
#include "ofxTween.h"
#endif


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
    

    ofSoundPlayer loop;
    
    
    ofTrueTypeFont font;
    
    typographyManager TM;
    
    int lettersLastFrame;
    long long lastPlayTime;
    bool shouldDrawScene;
    
    float maxLetterX, lastLetterY;
    
    bool didTriggerCodeFinishedAnimatingEvent;
    
    ofxPanel gui;
    ofParameter<bool>bAutoPlay;
    
#ifdef USE_MIDI_PARAM_SYNC
    ofxParameterMidiSync sync;
    void recordingStart();
    void recordingEnd();
    void startPlaying();
    void stopPlaying();
#endif
    
#ifdef USE_EXTERNAL_SOUNDS
    ofxOscSender oscSender;
    ofxOscMessage oscMessage;
#endif

#ifdef USE_SCENE_TRANSITIONS
    ofxTween sceneTween, codeTween;
    ofxEasingExpo easing;
    void tweenEnd(int& i);
    ofParameter<int> sceneTweenDuration, codeTweenDuration;
#endif
    
};
