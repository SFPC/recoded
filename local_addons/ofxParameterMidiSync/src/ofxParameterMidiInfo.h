//
//  ofxParameterMidiInfo.h
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 18-12-15.
//
//

#pragma once
#include "ofMain.h"
#include "ofxMidi.h"

class ofParameterMidiInfo {
public:
    ofParameterMidiInfo(ofAbstractParameter* p = NULL);
    ofParameterMidiInfo(ofAbstractParameter* p, int d, bool bCol, bool bVec, int cNum, int mdType);
    int dims;
    int controlNum;
    bool bIsColor;
    bool bIsVec;
    int multiDimType;
    ofAbstractParameter * param;
    float smoothValue;
    bool bNeedSmoothing;
    int lastValue;

    void setNewValue(int value);
    void updateSmoothing(float smoothFactor);
    void saveToXml(ofXml& xml);
    void loadFromXml(ofXml& xml);
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