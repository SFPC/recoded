
#pragma once

#include "ofMain.h"
//#include "appConstants.h"
#include "ofxXmlSettings.h"
//#ifdef USE_MIDI_RECORDING
#include "ofxMidiRecorder.h"
//#endif


void reportKnobs(string f);
class baseScene {
    
public:

    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    
    vector < float > origFloatValues;
    vector < bool > origBoolValues;
    vector < int > origIntValues;
    
    void postSetup(){
        
        for (auto & p : boolParams){
            origBoolValues.push_back(p.get());
        }
        
        for (auto & p : floatParams){
            origFloatValues.push_back(p.get());
        }
        
        for (auto & p : intParams){
            origIntValues.push_back(p.get());
        }

        
//        vector<ofParameter<bool>> boolParams;
//        vector<ofParameter<int>> intParams;
//        vector<ofParameter<float>> floatParams;
        
    }
//    ofParameterGroup parametersCopy;
//    virtual void postSetupSetup(){
//        parametersCopy = parameters;
//    }
   
    
    
    void reset(){
        resetTiming();
        
        
        ofParameter<bool>   boolParam;
        ofParameter<int>    intParam;
        ofParameter<float>  floatParam;

        
        int boolCount = 0;
        int intCount = 0;
        int floatCount = 0;
        
        
        for (auto param : parameters) {
            if (param->type() == boolParam.type()) {
                ofParameter<bool> &oldParam = param->cast<bool>();
                oldParam.set(origBoolValues[boolCount]);
                boolCount++;
                
            } else if (param->type() == intParam.type()) {
                ofParameter<int> &oldParam = param->cast<int>();
                
                oldParam.set(origIntValues[intCount]);
                intCount++;
                
            } else if (param->type() == floatParam.type()) {
                ofParameter<float> &oldParam = param->cast<float>();
                oldParam.set(origFloatValues[floatCount]);
                floatCount++;
            }
        }
        
//        for (int i = 0; i < boolParams.size(); i++){
//            boolParams[i].set(origBoolValues[i]);
//            cout << "settings " << boolParams[i].getName() << " " << origBoolValues[i] << endl;
//            
//            //origBoolValues.push_back(p.get());
//        }
//        
//        for (int i = 0; i < intParams.size(); i++){
//            intParams[i].set(origIntValues[i]);
//            cout << "settings " << intParams[i].getName() << " " << origIntValues[i] << endl;
//            //origBoolValues.push_back(p.get());
//        }
//        for (int i = 0; i < floatParams.size(); i++){
//            floatParams[i].set(origFloatValues[i]);
//            cout << "settings " << floatParams[i].getName() << " " << origFloatValues[i] << endl;
//            //origBoolValues.push_back(p.get());
//        }
        
        
//        for (int i = 0; i < parametersCopy.size(); i++){
//            //parameters.set(parametersCopy.get(i).
//            
//        }
    }          // this is for scenes that change over time....
    
    baseScene(){};
    ~baseScene(){}
    
    void enableMidi();
    void updateMidiParams();
    vector<char> paramTypes;
    
    void loadCode( string fileName, bool bShowAuthorAndArtistNames = true);
    void setAuthor(string author);
    void setOriginalArtist(string originalArtist);


    int horribleKnobCounter = 0;
    ofParameterGroup parameters;    // this is the parameters of your sketch...
    vector<ofParameter<bool>> boolParams;
    vector<ofParameter<int>> intParams;
    vector<ofParameter<float>> floatParams;
    map<int,int> paramMap;
    ofParameterGroup midiParameters;

    string code;                // this is the code we show
    string author, originalArtist; // for scene transitions

    ofRectangle dimensions;     // this is the dimensions of
                                // the surface you are drawing into.
//#ifdef USE_MIDI_RECORDING
    vector<ofxMidiRecordingEvent> recData;
    string dataPath;
    void setRecData(const vector<ofxMidiRecordingEvent>& data);
    const vector<ofxMidiRecordingEvent>& getRecData();
    bool hasRecData();
//#endif
    //----------------------------------------
    // scene timing and frames.
    uint64_t startTime;
    uint64_t startFrame;
    float getElapsedTimef();
    uint64_t getFrameNum();
    void resetTiming();
    //----------------------------------------

    bool bIsSceneDone;
    float sceneDuration = 25.0f;
    static float smoothingSpeed;
    bool isSceneDone();
    void setSceneEnd();
    void setSceneEnd(float time);
    bool bHasEndSet;
    bool isEndSet(){return bHasEndSet;}
    
    bool bAnimateScene;
    void reportKnobs(string f);
        
    bool bUpdateParamFromRecording = true;
    void updateInteractiveParams(float valChangeAsPct, int param, float abspct = 1.0);
    vector < int > midiKnobs;
    float defaultDuration = 45;
	
};
