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



struct ofParameterMidiInfo {
    ofParameterMidiInfo(ofAbstractParameter* p = NULL):ofParameterMidiInfo(p, 1, false, false, 0, 0){}
    ofParameterMidiInfo(ofAbstractParameter* p, int d, bool bCol, bool bVec, int cNum, int mdType):dims(d), bIsColor(bCol), bIsVec(bVec), controlNum(cNum),multiDimType(mdType){
        param = p;
    }
    int dims;
    int controlNum;
    bool bIsColor;
    bool bIsVec;
    int multiDimType;
    ofAbstractParameter * param;
    void saveToXml(ofXml& xml){
        if(param){
            ofXml x;
            x.addChild("ofParameterMidiInfo");
            x.setTo("ofParameterMidiInfo");
            x.addValue("groupHierarchyNames", joinStrings(param->getGroupHierarchyNames(), "/"));
            x.addValue("dims", dims);
            x.addValue("controlNum", controlNum);
            x.addValue("bIsColor", bIsColor);
            x.addValue("bIsVec", bIsVec);
            x.addValue("multiDimType", multiDimType);
            xml.addXml(x);
        }
    }
    void loadFromXml(ofXml& xml){
    }
    string joinStrings(vector<string> s, string delim){
        string r = "";
        for(int i = 0; i < s.size(); i++){
            r += s[i];
            if (i < s.size() -1) {
                r += delim;
            }
        }
        return r;
    }
};

class ofxParameterMidiSync:  public ofxMidiListener {
public:
    ofxParameterMidiSync();
    ~ofxParameterMidiSync();
    void setup(int portNum);
    void setup(int portNum, ofAbstractParameter & parameters, bool bAutoLink);
    void setup(int portNum, ofParameterGroup & parameters, bool bAutoLink);
    void setSyncGroup( ofAbstractParameter & parameters, bool bAutoLink);
    void setSyncGroup( ofParameterGroup & parameters, bool bAutoLink);
    void enableMidi(bool b = true);

    
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
    
};
