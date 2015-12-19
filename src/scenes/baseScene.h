
#pragma once

#include "ofMain.h"
#include "appConstants.h"

#ifdef USE_MIDI_RECORDING
#include "ofxMidiRecorder.h"
#endif


class baseScene {
    
public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual void reset(){resetTiming();}          // this is for scenes that change over time....
    
    baseScene(){};
    ~baseScene(){}
    
    void loadCode( string fileName );
    void setAuthor(string author);
    void setOriginalArtist(string originalArtist);
    
    ofParameterGroup parameters;    // this is the parameters of your sketch...

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

    float sceneDuration = 25.0f;
    bool isSceneDone();
    void setSceneEnd();
    bool bHasEndSet;
    bool isEndSet(){return bHasEndSet;}
    
};