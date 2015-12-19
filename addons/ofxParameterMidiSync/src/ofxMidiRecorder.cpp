//
//  ofxMidiRecorder.cpp
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//

#include "ofxMidiRecorder.h"
#include "nanoKontrolConstants.h"
ofxMidiRecorder::ofxMidiRecorder():bRecording(false){}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::record(){
    if (!bRecording) {
        bRecording = true;
        recordingStartTime = ofGetElapsedTimeMillis();
        ofNotifyEvent(recStartE, this);
        kontrolButtons->setRec();
    }else{
        //ofNotifyEvent(recEndE, this);
    }
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::stop(){
    if (bRecording) {
        bRecording = false;
        ofNotifyEvent(recEndE, this);
        kontrolButtons->setRec(false);
    }
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::newMidiMessage(ofxMidiMessage& msg) {
    
    if (msg.status == MIDI_CONTROL_CHANGE) {
        if (msg.control == NANO_KONTROL_KEY_FFW) {
        }else if(msg.control == NANO_KONTROL_KEY_REW) {
        }else if(msg.control == NANO_KONTROL_KEY_STOP) {
            stop();
        }else if(msg.control == NANO_KONTROL_KEY_PLAY) {
            if (isRecording()) {
                stop();
            }
        }else if(msg.control == NANO_KONTROL_KEY_REC) {
            record();
        }else{
            if (bRecording) {
                recData.push_back(ofxMidiRecordingEvent(msg,ofGetElapsedTimeMillis() - recordingStartTime));
            }
        }
    }
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
ofxMidiPlayer::ofxMidiPlayer():bPlaying(false), bLoopPlayback(true), listener(nullptr){}
// -----------------------------------------------------------------------------
ofxMidiPlayer::~ofxMidiPlayer(){
    listener = nullptr;
    if (bPlaying) {
        ofRemoveListener(ofEvents().update, this, &ofxMidiPlayer::update);
        bPlaying = false;
    }
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::setup(ofxMidiListener *l){
    listener = l;
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::update(ofEventArgs& e){
    if (bPlaying && listener != nullptr) {
        //       cout << "update" <<endl;
        uint64_t t = ofGetElapsedTimeMillis()- playingStartTime;
        for (int i = playbackIndex; i <data.size(); i++) {
            if(data[i].time<=t){
                listener->newMidiMessage(data[i].message);
                playbackIndex = i+1;
            }
        }
        if (playbackIndex >= data.size()){
            if(bLoopPlayback) {
                playbackIndex = 0;
                playingStartTime = ofGetElapsedTimeMillis();
            }else{
                stop();
            }
        }
    }
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::play(){
    if(!bPlaying && data.size() > 0){
        
        ofAddListener(ofEvents().update, this, &ofxMidiPlayer::update);
        bPlaying = true;
        playbackIndex = 0;
        playingStartTime = ofGetElapsedTimeMillis();
    }
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::stop(){
    if (bPlaying) {
        ofRemoveListener(ofEvents().update, this, &ofxMidiPlayer::update);
        bPlaying = false;
        ofNotifyEvent(stopE, this);
        kontrolButtons->setPlay(false);
    }
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::setData(const vector<ofxMidiRecordingEvent>& data){
    clear();
    this->data = data;
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::clear(){
    stop();
    this->data.clear();
}
// -----------------------------------------------------------------------------
void ofxMidiPlayer::newMidiMessage(ofxMidiMessage& msg) {
    if (msg.status == MIDI_CONTROL_CHANGE) {
        if (msg.control == NANO_KONTROL_KEY_FFW) {
        }else if(msg.control == NANO_KONTROL_KEY_REW) {
        }else if(msg.control == NANO_KONTROL_KEY_STOP) {
            stop();
        }else if(msg.control == NANO_KONTROL_KEY_PLAY) {
            ofNotifyEvent(playE, this);
            kontrolButtons->setPlay();
        }else if(msg.control == NANO_KONTROL_KEY_REC) {
        }
    }
}



