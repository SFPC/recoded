//
//  midiRecorder.cpp
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//

#include "midiRecorder.h"
// -----------------------------------------------------------------------------
void midiRecorder::newMidiMessage(ofxMidiMessage& msg){
    if (bRecording) {
        
        }
}
// -----------------------------------------------------------------------------
void midiRecorder::record(uint64_t time){
    bRecording = true;
    bPlaying = false;
    recordingStartTime = ofGetElapsedTimeMillis();
}
// -----------------------------------------------------------------------------
void midiRecorder::play(){

    
}
// -----------------------------------------------------------------------------
void midiRecorder::stop(){

    
}
