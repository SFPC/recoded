
#pragma once

#include "ofMain.h"
#include "appConstants.h"
#include "ofxXmlSettings.h"
#ifdef USE_MIDI_RECORDING
#include "ofxMidiRecorder.h"
#endif


void reportKnobs(string f);
class baseScene {
    
public:


  virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual void reset(){resetTiming();}          // this is for scenes that change over time....
    
    baseScene(){};
    ~baseScene(){}
    
    void enableMidi();
    void updateMidiParams();
    vector<char> paramTypes;
    
    void loadCode( string fileName );
    void setAuthor(string author);
    void setOriginalArtist(string originalArtist);


  int horribleKnobCounter = 0;
  ofParameterGroup parameters;    // this is the parameters of your sketch...
    vector<ofParameter<bool>> boolParams;
    vector<ofParameter<int>> intParams;
    vector<ofParameter<float>> floatParams;
  map<int,int> paramMap;
    ofParameterGroup midiParameters;

    string code;                // this is the code we show
    string author, originalArtist; // for scene transitions
    
    ofRectangle dimensions;     // this is the dimensions of
                                // the surface you are drawing into.
#ifdef USE_MIDI_RECORDING
    vector<ofxMidiRecordingEvent> recData;
    string dataPath;
    void setRecData(const vector<ofxMidiRecordingEvent>& data);
    const vector<ofxMidiRecordingEvent>& getRecData();
    bool hasRecData();
#endif
    //----------------------------------------
    // scene timing and frames.
    uint64_t startTime;
    uint64_t startFrame;
    float getElapsedTimef();
    uint64_t getFrameNum();
    void resetTiming();
    //----------------------------------------

    bool bIsSceneDone;
    float sceneDuration = 25.0f;
    static float smoothingSpeed;
    bool isSceneDone();
    void setSceneEnd();
    void setSceneEnd(float time);
    bool bHasEndSet;
    bool isEndSet(){return bHasEndSet;}
    
    bool bAnimateScene;
    
    bool bUpdateParamFromRecording = true;
    void updateInteractiveParams(float valChangeAsPct, int param);
    
    
    
};
