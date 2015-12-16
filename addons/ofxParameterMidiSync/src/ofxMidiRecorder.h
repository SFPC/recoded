//
//  ofxMidiRecorder.h
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//

#include "ofMain.h"
#include "ofxMidi.h"

///--------RECORDING & PLAYBACK
class recordingEvent{
public:
    
    recordingEvent(){
        time = 0;
    }
    recordingEvent(const ofxMidiMessage& from, uint64_t time){
        this->time = time;
        this->message = from;
    }
    recordingEvent(const recordingEvent& from){
        this->time = from.getTime();
        this->message = from.getMessage();
    }
    recordingEvent& operator=(const recordingEvent& from){
        this->time = from.getTime();
        this->message = from.getMessage();
    }
    
    uint64_t getTime() const{return time;}
    const ofxMidiMessage& getMessage() const {return message;}
    //    ofxMidiMessage getMessage;
    //protected:
    uint64_t time;
    ofxMidiMessage message;
};

class ofxMidiRecorder: public ofxMidiListener{
public:
    ofxMidiRecorder();
    void setup(ofxMidiListener *l);
    void update(ofEventArgs& e);
    void record();
    void play();
    void stop();
    void clear();
    void newMidiMessage(ofxMidiMessage& msg);
    
    vector<recordingEvent> recData;
    ofxMidiListener* listener;
bool bRecording, bPlaying, bLoopPlayback;
uint64_t recordingStartTime, playingStartTime, playbackIndex;

};
