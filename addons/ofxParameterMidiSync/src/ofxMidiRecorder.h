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
};

static void saveMidi(const vector<ofxMidiRecordingEvent>& data, string path){
    cout << __PRETTY_FUNCTION__ << endl;
    ofXml xml;
    xml.addChild("Midi");
    xml.setTo("Midi");
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
        //x.setToParent();
        xml.addXml(x);
    }
   // xml.setToParent();
    if(xml.save(path)){
        cout << "save midi to  " << path << endl;
    }else{
        cout << "couldnt save xml" << endl;
    }
}
static void loadMidi(vector<ofxMidiRecordingEvent>& data, string path){
    cout << "loadMidi " << path << endl;
    ofXml xml;
    xml.load(path);
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
