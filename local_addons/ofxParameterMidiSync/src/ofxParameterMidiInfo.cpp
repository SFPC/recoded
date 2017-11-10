//
//  ofxParameterMidiInfo.cpp
//  d4nSFPCRunner
//
//  Created by Roy Macdonald on 18-12-15.
//
//

#include "ofxParameterMidiInfo.h"
void mapMidiInfoToParameter(ofParameterMidiInfo& info, float value, int control){
    //     cout << __PRETTY_FUNCTION__ << endl;
    //     cout << "dims " << info.dims << "  midiMsg.control "<< midiMsg.control<<endl;
    int mx = 127;
    
    ofAbstractParameter * param = info.param;
    if (param) {
        if (info.dims > 1 ) {
            int ind = control - info.controlNum;
            if (info.dims > ind) {
                if (info.multiDimType == 2) {
                    ofVec2f v = param->cast<ofVec2f>();
                    float mp = ofMap(value, 0, mx, param->cast<ofVec2f>().getMin()[ind], param->cast<ofVec2f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec2f>() = v;
                    }
                }else if (info.multiDimType == 3) {
                    ofVec3f v = param->cast<ofVec3f>();
                    float mp = ofMap(value, 0, mx, param->cast<ofVec3f>().getMin()[ind], param->cast<ofVec3f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec3f>() = v;
                    }
                }else if (info.multiDimType == 4) {
                    ofVec4f v = param->cast<ofVec4f>();
                    float mp = ofMap(value, 0, mx, param->cast<ofVec4f>().getMin()[ind], param->cast<ofVec4f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec4f>() = v;
                    }
                }else if (info.multiDimType == 8) {
                    ofColor v = param->cast<ofColor>();
                    unsigned char mp = ofMap(value, 0, mx, param->cast<ofColor>().getMin()[ind], param->cast<ofColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofColor>() = v;
                    }
                }else if (info.multiDimType == 16) {
                    ofShortColor v = param->cast<ofShortColor>();
                    unsigned short mp = ofMap(value, 0, mx, param->cast<ofShortColor>().getMin()[ind], param->cast<ofShortColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofShortColor>() = v;
                    }
                }else if (info.multiDimType == 32 ) {
                    ofFloatColor v = param->cast<ofFloatColor>();
                    float mp = ofMap(value, 0, mx, param->cast<ofFloatColor>().getMin()[ind], param->cast<ofFloatColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofFloatColor>() = v;
                    }
                }
            }
        }else{
            if(param->type()==typeid(ofParameter<int>).name()){
                
                int mp = ofMap(value, 0, mx, param->cast<int>().getMin(), param->cast<int>().getMax());
                if (param->cast<int>() != mp) {
                    param->cast<int>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<float>).name()){
                
                float mp = ofMap(value, 0, mx, param->cast<float>().getMin(), param->cast<float>().getMax());
                
                if (param->cast<float>() != mp) {
                    param->cast<float>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<double>).name()){
                
                double mp = ofMap(value, 0, mx, param->cast<double>().getMin(), param->cast<double>().getMax());
                if (param->cast<double>() != mp) {
                    param->cast<double>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<bool>).name()){
                
                bool bVal = value != 0;
                if (param->cast<bool>() != bVal) {
                    param->cast<bool>() = bVal;
                }
            }
        }
    }
}

ofParameterMidiInfo::ofParameterMidiInfo(ofAbstractParameter* p):ofParameterMidiInfo(p, 1, false, false, 0, 0){}
ofParameterMidiInfo::ofParameterMidiInfo(ofAbstractParameter* p, int d, bool bCol, bool bVec, int cNum, int mdType):dims(d), bIsColor(bCol), bIsVec(bVec), controlNum(cNum),multiDimType(mdType), bNeedSmoothing(false){
    param = p;
}
void ofParameterMidiInfo::updateSmoothing(float smoothFactor){
    if (bNeedSmoothing) {
        smoothValue = smoothValue* smoothFactor + lastValue*(1 - smoothFactor);
        if (fabs(lastValue - smoothValue) < 0.01 ) {
            smoothValue = lastValue;
            bNeedSmoothing = false;
        }
        mapMidiInfoToParameter(*this, smoothValue, controlNum);
    }
}
void ofParameterMidiInfo::setNewValue(int value){
    if(lastValue != value){
        bNeedSmoothing = true;
        lastValue = value;
    }
}
void ofParameterMidiInfo::saveToXml(ofXml& xml){
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
void ofParameterMidiInfo::loadFromXml(ofXml& xml){}