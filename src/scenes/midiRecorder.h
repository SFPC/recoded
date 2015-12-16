//
//  midiRecorder.h
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//

#pragma once
#include "ofMain.h"

#include "ofxMidiMessage.h"

class recordingEvent{
public:

    recordingEvent(){
        time = 0;
    }
    recordingEvent(const recordingEvent& from, uint64_t time){
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

class midiRecorder: public ofxMidiListener{
public:
    
    void newMidiMessage(ofxMidiMessage& msg);

    bool bRecording, bPlaying;
    uint64_t recordingStartTime;
    
    vector<recordingEvent> data;
    
    void setup();

    void record(uint64_t time);
    void play();
    void stop();
    void clear();
    
    
};