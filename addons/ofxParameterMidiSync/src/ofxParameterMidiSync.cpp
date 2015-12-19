//
//  ofxParameterMidiSync.cpp
//  emptyExample
//
//  Created by Roy Macdonald on 18-08-15.
//
//

#include "ofxParameterMidiSync.h"
#include "nanoKontrolConstants.h"
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
    smoothing.set("Smoothing",0.5,0,1);
    kontrolButtons = shared_ptr<ofxMidiNanoKontrolButtons>(new ofxMidiNanoKontrolButtons);
    kontrolButtons->setup(0);
    player.kontrolButtons = kontrolButtons;
    recorder.kontrolButtons = kontrolButtons;
}
//-----------------------------------------------------
void ofxParameterMidiSync::update(){
    for (map<int, shared_ptr<ofParameterMidiInfo> > ::iterator it = synced.begin(); it != synced.end(); ++it) {
        it->second->updateSmoothing(smoothing);
    }
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
bool ofxParameterMidiSync::enableMidi(bool b){
    if (bIsSetup && bParameterGroupSetup) {
        if (b != bMidiEnabled) {
            if (b) {
                midiIn.listPorts();
                bool opened = midiIn.openPort(portNum);
                if (opened) {
                    midiIn.ignoreTypes(true, true, false);
                    midiIn.addListener(this);
                    ofAddListener(syncGroup.parameterChangedE(),this,&ofxParameterMidiSync::parameterChanged);
                    midiIn.addListener(&recorder);
                    midiIn.addListener(&player);
                }
                return opened;
            }else{
                midiIn.closePort();
                midiIn.removeListener(this);
                midiIn.removeListener(&recorder);
                midiIn.removeListener(&player);
                ofRemoveListener(syncGroup.parameterChangedE(),this,&ofxParameterMidiSync::parameterChanged);
                return true;
            }
            bMidiEnabled = b;
        }
    }
    return false;
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
                if (msg.control == NANO_KONTROL_KEY_FFW) {
                    if (msg.value == 127) {
                        ofNotifyEvent(ffwKeyPressed, this);
                    }
                }else if(msg.control == NANO_KONTROL_KEY_REW) {
                }else if(msg.control == NANO_KONTROL_KEY_STOP) {
                }else if(msg.control == NANO_KONTROL_KEY_PLAY) {
                }else if(msg.control == NANO_KONTROL_KEY_REC) {
                }else if (synced.count(message.control)) {
                    synced[message.control]->setNewValue(message.value);
                    // mapMidiInfoToParameter(*synced[message.control].get(), message);
                }
            }
        }
        midiMessage = message;
    }
}
