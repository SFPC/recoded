//
//  ofxParameterMidiSync.h
//  emptyExample
//
//  Created by Roy Macdonald on 18-08-15.
//
//


#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxMidiRecorder.h"
#include "ofxParameterMidiInfo.h"
#include "nanoKontrolConstants.h"

class ofxParameterMidiSync:  public ofxMidiListener {
public:
    ofxParameterMidiSync();
    ~ofxParameterMidiSync();
    void setup(int portNum);
    void setup(int portNum, ofAbstractParameter & parameters, bool bAutoLink);
    void setup(int portNum, ofParameterGroup & parameters, bool bAutoLink);
    void setSyncGroup( ofAbstractParameter & parameters, bool bAutoLink);
    void setSyncGroup( ofParameterGroup & parameters, bool bAutoLink);
    bool enableMidi(bool b = true);

    void update();
    
    bool linkMidiToOfParameter(int controlNum, ofAbstractParameter& param);
    bool linkMidiToOfParameter(ofxMidiMessage& msg, ofAbstractParameter& param);
    
    void learn(bool bLearn = true);
    void unlearn(bool bUnlearn = true);
    
    bool load(string path = "ofxParameterMidiSyncSettings.xml");
    void save(string path = "ofxParameterMidiSyncSettings.xml");
    
    void reset();
    
    void drawDebug();
    
    bool isLearning(){return bLearning;}
    bool isUnlearning(){return bUnlearning;}
    
    ofxMidiRecorder recorder;
    ofxMidiPlayer player;
    ofParameter<float> smoothing;

    ofEvent<void>ffwKeyPressed;
    
protected:
    void newMidiMessage(ofxMidiMessage& eventArgs);

    bool linkMidiToOfParameter(int controlNum, ofAbstractParameter* param);
    bool linkMidiToOfParameter(ofxMidiMessage& msg, ofAbstractParameter* param);

    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;

    void parameterChanged( ofAbstractParameter & parameter );
    ofParameterGroup syncGroup;
    map<int, shared_ptr<ofParameterMidiInfo> > synced;
    bool bLearning, bUnlearning;
    int portNum;
    bool bMidiEnabled;
    bool bIsSetup;
    bool bParameterGroupSetup;
    ofAbstractParameter * learningParameter;
   
    shared_ptr<ofxMidiNanoKontrolButtons> kontrolButtons;
    
    
};
