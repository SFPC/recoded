//
//  ofxMidiRecorder.cpp
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//

#include "ofxMidiRecorder.h"
#include "nanoKontrolConstants.h"
ofxMidiRecorder::ofxMidiRecorder():bRecording(false), bPlaying(false), bLoopPlayback(true), listener(nullptr){}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::setup(ofxMidiListener* l){
    listener = l;
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::update(ofEventArgs& e){
    if (bPlaying && listener != nullptr) {
 //       cout << "update" <<endl;
        uint64_t t = ofGetElapsedTimeMillis()- playingStartTime;
        for (int i = playbackIndex; i <recData.size(); i++) {
            if(recData[i].time<=t){
                listener->newMidiMessage(recData[i].message);
                playbackIndex = i+1;
            }
        }
        if (playbackIndex >= recData.size()){
            if(bLoopPlayback) {
                playbackIndex = 0;
                playingStartTime = ofGetElapsedTimeMillis();
//                cout << "reset loop " << playbackIndex << "  ;  "<< recData.size()<< endl;
            }else{
                stop();
            }
        }
    }
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::record(){
    if (!bRecording) {
        bRecording = true;
        bPlaying = false;
        recordingStartTime = ofGetElapsedTimeMillis();
    }
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::play(){
    if(!bPlaying){
        ofAddListener(ofEvents().update, this, &ofxMidiRecorder::update);
        bPlaying = true;
        bRecording = false;
        playbackIndex = 0;
        playingStartTime = ofGetElapsedTimeMillis();
    }
}
// -----------------------------------------------------------------------------
void ofxMidiRecorder::stop(){
    bRecording = false;
    if (bPlaying) {
        ofRemoveListener(ofEvents().update, this, &ofxMidiRecorder::update);
        bPlaying = false;
    }
}
void ofxMidiRecorder::newMidiMessage(ofxMidiMessage& msg) {
    
        if (msg.status == MIDI_CONTROL_CHANGE) {
            if (msg.control == NANO_KONTROL_KEY_FFW) {
            }else if(msg.control == NANO_KONTROL_KEY_REW) {
            }else if(msg.control == NANO_KONTROL_KEY_STOP) {
                stop();
            }else if(msg.control == NANO_KONTROL_KEY_PLAY) {
                play();
            }else if(msg.control == NANO_KONTROL_KEY_REC) {
                record();
            }else{
                if (bRecording) {
                    recData.push_back(recordingEvent(msg,ofGetElapsedTimeMillis() - recordingStartTime));
            }
        }
    }
}