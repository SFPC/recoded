//
//  ofxMidiRecorder.h
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 16-12-15.
//
//
#pragma once
#include "ofMain.h"
#include "ofxMidi.h"
#include "nanoKontrolConstants.h"
class ofxMidiNanoKontrolButtons{
public:
    ~ofxMidiNanoKontrolButtons(){
        if(bIsSetup)midi.closePort();
    }
    ofxMidiOut midi;
    bool bIsSetup;
    void setup(int device){
        bIsSetup = midi.openPort(device);
    }
    void setRec(bool on = true){
        if(bIsSetup)
            midi.sendControlChange(1, NANO_KONTROL_KEY_REC, on?127:0);
    }
    void setStop(bool on = true){
        if(bIsSetup)
            midi.sendControlChange(1, NANO_KONTROL_KEY_STOP, on?127:0);
    }
    void setPlay(bool on = true){
        if(bIsSetup)
            midi.sendControlChange(1, NANO_KONTROL_KEY_PLAY, on?127:0);
    }
    void setRew(bool on = true){
        if(bIsSetup)
            midi.sendControlChange(1, NANO_KONTROL_KEY_REW, on?127:0);
    }
    void setFfw(bool on = true){
        if(bIsSetup)
            midi.sendControlChange(1, NANO_KONTROL_KEY_FFW, on?127:0);
    }
};

///--------RECORDING & PLAYBACK
class ofxMidiRecordingEvent{
public:
    
    ofxMidiRecordingEvent(){
        time = 0;
    }
    ofxMidiRecordingEvent(const ofxMidiMessage& from, uint64_t time){
        this->time = time;
        this->message = from;
    }
    ofxMidiRecordingEvent(const ofxMidiRecordingEvent& from){
        this->time = from.getTime();
        this->message = from.getMessage();
    }
    ofxMidiRecordingEvent& operator=(const ofxMidiRecordingEvent& from){
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
    void record();
    void stop();
    void clear();
    bool isRecording(){return bRecording;}
    
    void newMidiMessage(ofxMidiMessage& msg);
    
    const vector<ofxMidiRecordingEvent>& getData(){return recData;}
    
    vector<ofxMidiRecordingEvent> recData;
    bool bRecording;
    uint64_t recordingStartTime;
    ofEvent<void> recStartE, recEndE;
    shared_ptr<ofxMidiNanoKontrolButtons> kontrolButtons;
};
class ofxMidiPlayer: public ofxMidiListener{
public:
    ofxMidiPlayer();
    ~ofxMidiPlayer();
    void setup(ofxMidiListener *l);
    void update(ofEventArgs& e);
    void play();
    void stop();
    void clear();
    void setData(const vector<ofxMidiRecordingEvent>& data);
    vector<ofxMidiRecordingEvent> data;
    ofxMidiListener* listener;
    bool bPlaying, bLoopPlayback;
    uint64_t  playingStartTime, playbackIndex;
    ofEvent<void> playE, stopE;
    
    void newMidiMessage(ofxMidiMessage& msg);
    shared_ptr<ofxMidiNanoKontrolButtons> kontrolButtons;
};

static void saveMidi(const vector<ofxMidiRecordingEvent>& data, float duration, string path){
    cout << __PRETTY_FUNCTION__ << endl;
    ofXml xml;
    xml.addChild("Midi");
    xml.setTo("Midi");

    ofXml meta;
    meta.addChild("Meta");
    meta.setTo("Meta");
    meta.addValue("duration", duration);
    xml.addXml(meta);

    for (int i =0; i < data.size(); i++) {
        ofXml x;
        x.addChild("midiEvent");
        x.setTo("midiEvent");
        x.addValue("time", data[i].time);
        x.addValue("control", data[i].message.control);
        x.addValue("value", data[i].message.value);
        x.addValue("deltatime", data[i].message.deltatime);
        x.addValue("status", (int)data[i].message.status);
        x.addValue("channel", data[i].message.channel);
        x.addValue("pitch", data[i].message.pitch);
        x.addValue("velocity", data[i].message.velocity);
        xml.addXml(x);
    }
    if(xml.save(path)){
        cout << "save midi to  " << path << endl;
    }else{
        cout << "couldnt save xml" << endl;
    }
}
static void loadMidi(vector<ofxMidiRecordingEvent>& data, float *duration, string path){
    cout << "loadMidi " << path << endl;
    ofXml xml;
    xml.load(path);
    if(xml.exists("Meta")) {
        xml.setTo("Meta");
        *duration = xml.getFloatValue("duration");
        xml.setToParent();
    }
    if(xml.exists("midiEvent")){
        xml.setTo("midiEvent[0]");
        do {
            if(xml.getName() == "midiEvent"){
                ofxMidiRecordingEvent e;
                e.time = xml.getIntValue("time");
                e.message.control = xml.getIntValue("control");
                e.message.value = xml.getIntValue("value");
                e.message.status = MidiStatus(xml.getIntValue("status"));
                e.message.channel = xml.getIntValue("channel");
                e.message.pitch = xml.getIntValue("pitch");
                e.message.velocity = xml.getIntValue("velocity");
                e.message.deltatime = xml.getFloatValue("deltatime");
           //     cout << "New Midi Event: " << e.time << " control: " << e.message.control << " value: " << e.message.value << endl;
                data.push_back(e);
            }
        }
        while( xml.setToSibling() ); // go to the next STROKE
    }
}
