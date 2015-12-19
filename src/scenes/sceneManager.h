

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
#endif

#ifdef USE_SCENE_TRANSITIONS
#include "ofxTween.h"
#endif

#define FADE_DELAY_MIN 1.5
#define FADE_DELAY_MAX 1.77

#define SCENE_PRE_TRANSITION_FADE   0.3
#define SCENE_PRE_TRANSITION_CURSOR 0.35

// I take care of scenes.

class sceneManager {

private:

	void nextScene(bool forward);
    
public:
    
    ~sceneManager();
    vector < baseScene * > scenes;
    int currentScene;
    
    void setup();
    void update();
    void draw();
    
    void advanceScene();
    void regressScene();
    void screenGrab();
    
    float motion;
    ofPoint centroid, lastCentroid;
    ofPixels lastFrame, currFrame;
    void computeMotion(ofFbo &fbo);
    
    void startScene(int whichScene);
  
    ofFbo transitionFbo;
    ofFbo sceneFbo;
    ofFbo codeFbo;
    ofxPanel * panel;
    
    ofParameter<float> codeEnergyDecayRate, codeEnergyPerFrame;
    ofxPanel codeControls;
    

    ofTrueTypeFont font;
    
    typographyManager TM;
    
    int lettersLastFrame;
    long long lastPlayTime;

    bool isTransitioning, fadingOut, introCursor;
    float preTransitionPct;
    float preTransitionStart;
    
    float pctDelay;
    bool shouldDrawScene, shouldDrawCode;
    
    float maxLetterX, lastLetterY;
    
    bool fadingIn;
    
    ofxPanel gui;
    ofParameter<bool>bAutoPlay, bSceneWaitForCode, bFadeOut, bAutoAdvance, drawScenePanel;
    ofParameter<float> autoadvanceDelay, ofSmoothing;
    float lastAutoadvanceTime;
    
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
    ofParameter<float> sceneTweenDuration, codeTweenDuration;
#endif
    
    ofRectangle screenRect;
    bool bShowCursor;
    
    void setAdvanceCurrentScene();
    
    
};
