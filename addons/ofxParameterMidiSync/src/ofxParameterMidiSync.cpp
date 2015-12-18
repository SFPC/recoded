//
//  ofxParameterMidiSync.cpp
//  emptyExample
//
//  Created by Roy Macdonald on 18-08-15.
//
//

#include "ofxParameterMidiSync.h"

//-----------------------------------------------------
void mapMidiInfoToParameter(ofParameterMidiInfo& info, ofxMidiMessage& midiMsg, bool bIs10Bit = false){
    //     cout << __PRETTY_FUNCTION__ << endl;
    //     cout << "dims " << info.dims << "  midiMsg.control "<< midiMsg.control<<endl;
    int mx = bIs10Bit?1024:127;
    int midiVal = midiMsg.value;
    ofAbstractParameter * param = info.param;
    if (param) {
        if (info.dims > 1 ) {
            int ind = midiMsg.control - info.controlNum;
            if (info.dims > ind) {
                if (info.multiDimType == 2) {
                    ofVec2f v = param->cast<ofVec2f>();
                    float mp = ofMap(midiMsg.value, 0, mx, param->cast<ofVec2f>().getMin()[ind], param->cast<ofVec2f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec2f>() = v;
                    }
                }else if (info.multiDimType == 3) {
                    ofVec3f v = param->cast<ofVec3f>();
                    float mp = ofMap(midiMsg.value, 0, mx, param->cast<ofVec3f>().getMin()[ind], param->cast<ofVec3f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec3f>() = v;
                    }
                }else if (info.multiDimType == 4) {
                    ofVec4f v = param->cast<ofVec4f>();
                    float mp = ofMap(midiMsg.value, 0, mx, param->cast<ofVec4f>().getMin()[ind], param->cast<ofVec4f>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofVec4f>() = v;
                    }
                }else if (info.multiDimType == 8) {
                    ofColor v = param->cast<ofColor>();
                    unsigned char mp = ofMap(midiMsg.value, 0, mx, param->cast<ofColor>().getMin()[ind], param->cast<ofColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofColor>() = v;
                    }
                }else if (info.multiDimType == 16) {
                    ofShortColor v = param->cast<ofShortColor>();
                    unsigned short mp = ofMap(midiMsg.value, 0, mx, param->cast<ofShortColor>().getMin()[ind], param->cast<ofShortColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofShortColor>() = v;
                    }
                }else if (info.multiDimType == 32 ) {
                    ofFloatColor v = param->cast<ofFloatColor>();
                    float mp = ofMap(midiMsg.value, 0, mx, param->cast<ofFloatColor>().getMin()[ind], param->cast<ofFloatColor>().getMax()[ind]);
                    if (v[ind] != mp) {
                        v[ind] = mp;
                        param->cast<ofFloatColor>() = v;
                    }
                }
            }
        }else{
            if(param->type()==typeid(ofParameter<int>).name()){
                
                int mp = ofMap(midiVal, 0, mx, param->cast<int>().getMin(), param->cast<int>().getMax());
                if (param->cast<int>() != mp) {
                    param->cast<int>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<float>).name()){
                
                float mp = ofMap(midiVal, 0, mx, param->cast<float>().getMin(), param->cast<float>().getMax());
                
                if (param->cast<float>() != mp) {
                    param->cast<float>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<double>).name()){
                
                double mp = ofMap(midiVal, 0, mx, param->cast<double>().getMin(), param->cast<double>().getMax());
                if (param->cast<double>() != mp) {
                    param->cast<double>() = mp;
                }
            }else if(param->type()==typeid(ofParameter<bool>).name()){
                
                bool bVal = midiVal != 0;
                if (param->cast<bool>() != bVal) {
                    param->cast<bool>() = bVal;
                }
            }
        }
    }
}
//-----------------------------------------------------
int isVecParam(ofAbstractParameter* param){
    int ret = 0;
    if (param->type()==typeid(ofParameter<ofVec2f>).name()) {
        ret = 2;
    }else if (param->type()==typeid(ofParameter<ofVec3f>).name()) {
        ret = 3;
    }else if (param->type()==typeid(ofParameter<ofVec4f>).name()) {
        ret = 4;
    }
    return  ret;
}
//-----------------------------------------------------
int isColorParam(ofAbstractParameter* param){
    int ret = 0;
    if (param->type()==typeid(ofParameter<ofColor>).name()){
        ret = 8;
    }else if(param->type()==typeid(ofParameter<ofShortColor>).name()){
        ret = 16;
    }else if(param->type()==typeid(ofParameter<ofFloatColor>).name()) {
        ret = 32;
    }
    return  ret;
}
//-----------------------------------------------------
ofxParameterMidiSync::ofxParameterMidiSync():bMidiEnabled(false), portNum(-1), bLearning(false), learningParameter(NULL), bIsSetup(false), bUnlearning(false), bParameterGroupSetup(false){
}
//-----------------------------------------------------
ofxParameterMidiSync::~ofxParameterMidiSync(){
    enableMidi(false);
    learningParameter = NULL;
}
//-----------------------------------------------------
void ofxParameterMidiSync::setup(int portNum, ofAbstractParameter & parameters, bool bAutoLink){
    setup(portNum, static_cast<ofParameterGroup&>(parameters), bAutoLink);
}
//-----------------------------------------------------
void ofxParameterMidiSync::setup(int portNum, ofParameterGroup & parameters, bool bAutoLink){
    setSyncGroup(parameters, bAutoLink);
    setup(portNum);
}
//-----------------------------------------------------
void ofxParameterMidiSync::setup(int portNum){
    bIsSetup = true;
    this->portNum = portNum;
    enableMidi(true);
    player.setup(this);
}
//-----------------------------------------------------
void ofxParameterMidiSync::setSyncGroup( ofAbstractParameter & parameters, bool bAutoLink){
    setSyncGroup(static_cast<ofParameterGroup&>(parameters), bAutoLink);
}
//-----------------------------------------------------
void ofxParameterMidiSync::setSyncGroup( ofParameterGroup & parameters, bool bAutoLink){
    syncGroup = parameters;
    bParameterGroupSetup = true;
    if (bAutoLink) {
        synced.clear();
        for (int i = 0; i < parameters.size(); i++) {
            linkMidiToOfParameter(i, parameters.get(i));
        }
    }
}
//-----------------------------------------------------
void ofxParameterMidiSync::reset(){
    enableMidi(false);
    synced.clear();
   // syncGroup.clear();
    bParameterGroupSetup = false;
  //  bIsSetup = false;
    bLearning = false;
    bUnlearning = false;
    learningParameter = NULL;
}
//-----------------------------------------------------
void ofxParameterMidiSync::enableMidi(bool b){
    if (bIsSetup && bParameterGroupSetup) {
        if (b != bMidiEnabled) {
            if (b) {
                midiIn.listPorts();
                midiIn.openPort(portNum);
                midiIn.ignoreTypes(true, true, false);
                midiIn.addListener(this);
                ofAddListener(syncGroup.parameterChangedE(),this,&ofxParameterMidiSync::parameterChanged);
                midiIn.addListener(&recorder);
                midiIn.addListener(&player);
            }else{
                midiIn.closePort();
                midiIn.removeListener(this);
                midiIn.removeListener(&recorder);
                midiIn.removeListener(&player);
                ofRemoveListener(syncGroup.parameterChangedE(),this,&ofxParameterMidiSync::parameterChanged);
            }
            bMidiEnabled = b;
        }
    }
}
//-----------------------------------------------------
void ofxParameterMidiSync::learn(bool bLearn){
    if ( bIsSetup ) {
        if (bLearning != bLearn) {
            bLearning = bLearn;
            bUnlearning = false;
        }
    }
}
//-----------------------------------------------------
void ofxParameterMidiSync::unlearn(bool bUnlearn){
    if ( bIsSetup ) {
        if (bUnlearning != bUnlearn) {
            if (bLearning) {
                learningParameter = NULL;
            }
            bLearning = false;
            bUnlearning = bUnlearn;
        }
    }
}
//-----------------------------------------------------
void ofxParameterMidiSync::parameterChanged( ofAbstractParameter & parameter ){
    if (bLearning ) {
        learningParameter = &parameter;
    }else if(bUnlearning){
        //        for (map<int, shared_ptr<ofParameterMidiInfo> >::iterator it = synced.begin(); it!=synced.end(); ++it){
        //            if (it->second->param == &parameter) {
        //                synced.erase(it);
        //                bUnlearning = false;
        //
        //                cout << "unlearned " << endl;
        //               // break;
        //            }
        //        }
    }
}
//--------------------------------------------------------------
bool ofxParameterMidiSync::linkMidiToOfParameter(int controlNum, ofAbstractParameter& param){
    linkMidiToOfParameter(controlNum, &param);
}
//--------------------------------------------------------------
bool ofxParameterMidiSync::linkMidiToOfParameter(ofxMidiMessage& msg, ofAbstractParameter& param){
    linkMidiToOfParameter(msg, &param);
}
//--------------------------------------------------------------
bool ofxParameterMidiSync::linkMidiToOfParameter(ofxMidiMessage& msg, ofAbstractParameter* param){
    return linkMidiToOfParameter(msg.control, param);
}
//--------------------------------------------------------------
bool ofxParameterMidiSync::linkMidiToOfParameter(int controlNum, ofAbstractParameter* param){
    if (param == NULL) return false;
    
    if (synced.count(controlNum) == 0) {
        int isVec = isVecParam(param);
        int isCol = isColorParam(param);
        int dims = (isVec + isCol);
        if (dims == 0) dims = 1;
        if (dims > 4) dims = 4;
        synced[controlNum] = std::make_shared<ofParameterMidiInfo>(param, dims, isCol, isVec, controlNum, isVec + isCol);
        if (isVec != 0 || isCol != 0) {
            for (int i = 1; i < dims ; i++) {
                synced[controlNum+i] = synced[controlNum];
            }
        }
        return true;
    }
    return false;
}
//--------------------------------------------------------------
bool ofxParameterMidiSync::load(string path){
    ofXml xml;
    bool bLoad = false;
    
    cout << "ofxParameterMidiSync::load(" << path << ");" << endl;
    //    cout << "syncGroup iteration: " << endl;
    //    for (vector<shared_ptr<ofAbstractParameter> >::iterator i = syncGroup.begin(); i != syncGroup.end(); i++){
    //        cout << i->get()->getName() << endl;
    //    }
    //
    if(bIsSetup){
        bLoad = xml.load(path);
        if (bLoad) {
            if (xml.exists("ofxParameterMidiSync")) {
                xml.setTo("ofxParameterMidiSync");
            }

            
            if (xml.exists("ofParameterMidiInfo")) {
                xml.setTo("ofParameterMidiInfo[0]");
                do
                {
                    if (xml.getName() == "ofParameterMidiInfo"){
                        int controlNum = xml.getValue<int>("controlNum");
                        if(synced.count(controlNum) == 0){
                            int  dims = xml.getValue<int>("dims");
                            bool bIsColor = xml.getValue<bool>("bIsColor");
                            bool bIsVec = xml.getValue<int>("bIsVec");
                            int multiDimType = xml.getValue<int>("multiDimType");
                            ofAbstractParameter* param = NULL;
                            vector<string> groupHierarchyNames = ofSplitString( xml.getValue<string>("groupHierarchyNames"), "/");
                            
                            
                            if(groupHierarchyNames.size()){
                                param  = static_cast<ofAbstractParameter*> (&syncGroup);
                                if (param->getName() == groupHierarchyNames[0]) {
                                    for (int i = 1; i < groupHierarchyNames.size(); i++) {
                                        if (param->type() == typeid(ofParameterGroup).name()) {
                                            if (static_cast<ofParameterGroup*>(param)->contains(groupHierarchyNames[i])) {
                                                param = &static_cast<ofParameterGroup*>(param)->get(groupHierarchyNames[i]);
                                            }else{
                                                param = NULL;
                                                break;
                                                cout << "ruta incorrecta" << endl;
                                            }
                                        }
                                    }
                                }
                            }
                            if (param != NULL) {
                                int isVec = isVecParam(param);
                                int isCol = isColorParam(param);
                                int d =(isVec + isCol);
                                if (d == 0) d = 1;
                                if (d > 4) d = 4;
                                if (bIsVec == (bool) isVec && bIsColor == (bool)isCol && d == dims && multiDimType == isCol + isVec ) {
                                    linkMidiToOfParameter(controlNum, param);
                                }else{
                                    cout << "no se puede linkear: datos no coinciden." << endl;
                                }
                                
                            }
                        }
                    }
                }
                while( xml.setToSibling() );
            }
        }
    }
    
    return bLoad;
}
//--------------------------------------------------------------
void ofxParameterMidiSync::drawDebug(){
    
    string str = "Learning: " + (string)(bLearning?"YES":"NO")+"\n";
    str += "learningParameter: " + (string)((learningParameter==NULL)?"NULL": learningParameter->getName())+"\n";
    str += "controlNum: " + ofToString(midiMessage.control) + "\n";
    str += "lastMidiMessage: " + midiMessage.toString();// + "\n";
    
    ofDrawBitmapStringHighlight(str, 20, ofGetHeight() - 60);
    
}
//--------------------------------------------------------------
void ofxParameterMidiSync::save(string path){
    ofXml xml;
    xml.addChild("ofxParameterMidiSync");
    xml.setTo("ofxParameterMidiSync");
    if(!syncGroup.getName().empty()) xml.setTo(syncGroup.getName());
    
    for (map<int, shared_ptr<ofParameterMidiInfo> > ::iterator i = synced.begin(); i != synced.end() ; i++) {
        i->second.get()->saveToXml(xml);
    }
    xml.save(path);
    
}
//--------------------------------------------------------------
void ofxParameterMidiSync::newMidiMessage(ofxMidiMessage& msg) {
    if (bIsSetup) {
        ofxMidiMessage message = msg;
        if (message.status == MIDI_CONTROL_CHANGE) {
            
            if (learningParameter!= NULL && bLearning) {
                if (bParameterGroupSetup) {
                    if (linkMidiToOfParameter(message, learningParameter)){
                        cout << "learned  " << endl;
                        learningParameter=NULL;
                        bLearning = false;
                    }
                }
            }else if(bUnlearning){
                if (synced.count(message.control) > 0) {
                    int dims = synced[message.control]->dims;
                    if (dims == 0) dims = 1;
                    if (dims > 4) dims = 4;
                    for (int i = 0; i < dims; i++) {
                        if (synced.count(message.control+i)) {
                            synced.erase(message.control+i);
                        }
                    }
                    bUnlearning  = false;
                    cout << "unlearned  " << endl;
                }
            }else{
                if (synced.count(message.control)) {
                    mapMidiInfoToParameter(*synced[message.control].get(), message);
                }
            }
        }
        midiMessage = message;
    }
}
