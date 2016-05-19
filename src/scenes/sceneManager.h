

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

#define FADE_DELAY_MIN 1.4
#define FADE_DELAY_MAX 1.67

#define SCENE_PRE_TRANSITION_FADE   0.4
//#define SCENE_PRE_TRANSITION_SOUND 0.32
#define SCENE_PRE_TRANSITION_CURSOR 0.5

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
    void drawType();
    
    void advanceScene();
    void regressScene();
    void screenGrab();
    
  //    float motion, frameBrightness;
  //    ofPoint centroid, lastCentroid;
      ofPixels lastFrame, currFrame;
  //void computeMotion(ofFbo &fbo);
    
    void startScene(int whichScene);
  
    ofFbo transitionFbo;
    ofFbo sceneFbo;
  //ofFbo dimmedSceneFbo;
    ofFbo codeFbo;
  //ofShader dimmerShader;
    ofxPanel * panel;
    
    ofParameter<float> codeEnergyDecayRate, codeEnergyPerFrame;
    ofxPanel codeControls;
    
    //----------------------------------------
    // sound
    
    ofSoundPlayer sceneChangeSound;
    ofSoundPlayer cursorBlinkSound;
    ofSoundPlayer animationStartSound;
    ofSoundPlayer parameterChangeSound;
    bool hasTriggeredCursorSound;
    bool hasTriggeredSceneChangeSound;
    
    void loadSounds();
    

    ofTrueTypeFont font;
    
    typographyManager TM;
    
    int lettersLastFrame;
    long long lastPlayTime;

    bool isTransitioning, fadingOut, introCursor;
    float preTransitionPct;
    float preTransitionStart;
    
    float pctDelay;
    bool shouldDrawScene, shouldDrawCode, shouldPlaySceneChangeSound;
    
    float maxLetterX, lastLetterY;
    
    bool fadingIn;
    
    ofxPanel gui;
    ofParameter<bool>bAutoPlay, bSceneWaitForCode, bFadeOut, bAutoAdvance, drawScenePanel, enableMidiUpdate, enableParameterSounds;
    ofParameter<float> autoadvanceDelay, ofSmoothing;
    float lastAutoadvanceTime;
    
#ifdef USE_MIDI_PARAM_SYNC
    bool isMidiConnected;
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
    
    void triggerCursorSound();
    void toggleParameterSounds(bool &i);
    
    
};
