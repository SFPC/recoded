//
//  baseScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "baseScene.h"
#include <map>


//--------------------------------------------------------------
//int horribleKnobCounter = 0;
void baseScene::reportKnobs(string f){
  ofxXmlSettings settings;
  //vector < int > midiKnobs;
  settings.load(f);


  settings.pushTag("Midi");

  int numEvents = settings.getNumTags("midiEvent");
  
  for (int i = 0; i < numEvents; i++){
    settings.pushTag("midiEvent", i);

    int me = settings.getValue("control", -1);
    midiKnobs.push_back(me);
    //cout << me << endl;
    settings.popTag();
  }

  sort( midiKnobs.begin(), midiKnobs.end() );
  midiKnobs.erase( unique( midiKnobs.begin(), midiKnobs.end() ), midiKnobs.end() );

}

void baseScene::loadCode( string fileName ){
  ofBuffer buffer = ofBufferFromFile(fileName);
  code = "";

  code += "// artwork by " + originalArtist + "\n";
  code += "// re-coded by " + author + "\n";
  code += "\n";

  for (auto line : buffer.getLines()){
    code += line;
    code += "\n";
  }


  // Remove trailing newlines and spaces
  code.erase(std::find_if(code.rbegin(),
                          code.rend(),
                          std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
             code.end());
  dataPath = ofFilePath::removeTrailingSlash(ofFilePath::getEnclosingDirectory(fileName));

  bAnimateScene = true;
  bHasEndSet = false;
  ofFile xmlFile = ofFile(dataPath+"/paramsRecording.xml");
  string xmlPath = dataPath+"/paramsRecording.xml";
  reportKnobs(xmlPath);
  if (xmlFile.exists()) {
    float duration;
    loadMidi(recData, &duration, dataPath+"/paramsRecording.xml");
    //parseXmlFile("/paramsRecording.xml");
    cout << "got " << recData.size() << " events " << duration << endl;
    if (duration > 0) {
      setSceneEnd(duration);
    }
  }
}

void baseScene::enableMidi() {
  ofParameter<bool>   boolParam;
  ofParameter<int>    intParam;
  ofParameter<float>  floatParam;

  paramTypes.clear();
  boolParams.clear();
  intParams.clear();
  floatParams.clear();

  int n = 0;
  for (auto param : parameters) {
    if (param->type() == boolParam.type()) {
      n++;
      ofParameter<bool> newParam;
      ofParameter<bool> &oldParam = param->cast<bool>();
      newParam.setName(oldParam.getName());
      newParam.setMin(oldParam.getMin());
      newParam.setMax(oldParam.getMax());
      newParam.set(oldParam.get());
      boolParams.push_back(newParam);
      midiParameters.add(boolParams.back());
      paramTypes.push_back('b');
    } else if (param->type() == intParam.type()) {
      n++;
      ofParameter<int> newParam;
      ofParameter<int> &oldParam = param->cast<int>();
      newParam.setName(oldParam.getName());
      newParam.setMin(oldParam.getMin());
      newParam.setMax(oldParam.getMax());
      newParam.set(oldParam.get());
      intParams.push_back(newParam);
      midiParameters.add(intParams.back());
      paramTypes.push_back('i');
    } else if (param->type() == floatParam.type()) {
      n++;
      ofParameter<float> newParam;
      ofParameter<float> &oldParam = param->cast<float>();
      newParam.setName(oldParam.getName());
      newParam.setMin(oldParam.getMin());
      newParam.setMax(oldParam.getMax());
      newParam.set(oldParam.get());
      floatParams.push_back(newParam);
      midiParameters.add(floatParams.back());
      paramTypes.push_back('f');
    } else {
      cout << "couldn't link param with " << param->type() << endl;
    }
  }

  cout << "linked " << n << endl;

  if (!recData.size()) return;

  vector<bool> paramsSet;
  for (int i = 0; i < min((int)parameters.size(), 8); ++i) {
    paramsSet.push_back(false);
  }

  const int mx = 127;
  for (int i = 0; i < recData.size(); ++i) {
    int whichParam = recData[i].getMessage().control;
    int value = recData[i].getMessage().value;

    if (paramsSet[i])
      continue;

    if(parameters[whichParam].type()==typeid(ofParameter<int>).name()){
      ofParameter<int> &midiParam = midiParameters.getInt(whichParam);
      ofParameter<int> &param = parameters.getInt(whichParam);

      int mp = ofMap(value, 0, mx, param.getMin(), param.getMax(), true);
      if (param.get() != mp) {
        midiParam.set(mp);
        param.set(mp);
      }
    }else if(parameters[whichParam].type()==typeid(ofParameter<float>).name()){
      ofParameter<float> &midiParam = midiParameters.getFloat(whichParam);
      ofParameter<float> &param = parameters.getFloat(whichParam);

      float mp = ofMap(value, 0, mx, param.getMin(), param.getMax(), true);

      if (param.get() != mp) {
        midiParam.set(mp);
        param.set(mp);
      }
    }else if(parameters[whichParam].type()==typeid(ofParameter<bool>).name()){
      ofParameter<bool> &midiParam = midiParameters.getBool(whichParam);
      ofParameter<bool> &param = parameters.getBool(whichParam);

      bool bVal = value != 0;
      if (param.get() != bVal) {
        midiParam.set(bVal);
        param.set(bVal);
      }
    } else {
      continue;
    }

    paramsSet[whichParam] = true;
  }
}



void baseScene::updateInteractiveParams(float valChangeAsPct, int param, float abspct){

  //cout << "Param " << param << " = " << valChangeAsPct;
    
  int nToCheck = min((int)parameters.size(), 8);
  int i = param;
  char paramType = paramTypes[i];

  if (paramType == 'b') {
    ofParameter<bool> &param = parameters.getBool(i);

    // NO IDEA !!
      if (abspct > .5){
          param.set(true);
      } else {
          param.set(false);
      }
      

  } else if (paramType == 'i') {

      ofParameter<int> &param = parameters.getInt(i);

      float min = param.getMin();
      float max = param.getMax();
      float diffMinMax = max - min;
      float val = param.get();
      
      float amtToAdd = fabs(valChangeAsPct * diffMinMax);
      float sign = valChangeAsPct * diffMinMax > 0 ? 1 : -1;
      amtToAdd = MIN(1, amtToAdd) * sign;
      
      val += amtToAdd;
      if (val < min) val = min;
      if (val > max) val = max;
      
      float diff = val - param;
      if (fabs(diff) > 0.0001)
          param.set(param + diff); // * baseScene::smoothingSpeed);
      else
          param.set(val);

  } else if (paramType == 'f') {

    ofParameter<float> &param = parameters.getFloat(i);

    float min = param.getMin();
    float max = param.getMax();
    float diffMinMax = max - min;
    float val = param.get();
    val += valChangeAsPct * diffMinMax;
    if (val < min) val = min;
    if (val > max) val = max;

    float diff = val - param;
    if (fabs(diff) > 0.0001)
      param.set(param + diff); // * baseScene::smoothingSpeed);
    else
      param.set(val);
      
  }


}



void baseScene::updateMidiParams() {
  int nToCheck = min((int)parameters.size(), 8);
  for (int i = 0; i < nToCheck; ++i) {
    char paramType = paramTypes[i];

    if (paramType == 'b') {
      ofParameter<bool> &midiParam = midiParameters.getBool(i);
      ofParameter<bool> &param = parameters.getBool(i);
      if (bUpdateParamFromRecording) param.set(midiParam);
    } else if (paramType == 'i') {
      ofParameter<int> &midiParam = midiParameters.getInt(i);
      ofParameter<int> &param = parameters.getInt(i);
      if (bUpdateParamFromRecording)param.set(midiParam);
    } else if (paramType == 'f') {
      ofParameter<float> &midiParam = midiParameters.getFloat(i);
      ofParameter<float> &param = parameters.getFloat(i);

      if (isnan(midiParam.get()))
        continue;

      float diff = midiParam - param;
      if (fabs(diff) > 0.0001)
        if (bUpdateParamFromRecording) param.set(param + diff * baseScene::smoothingSpeed);
        else
          if (bUpdateParamFromRecording) param.set(midiParam);
    }
  }
}

bool baseScene::isSceneDone(){
  if (!bHasEndSet || sceneDuration < 0)
    return false;

  return (getElapsedTimef()>sceneDuration);
}
void baseScene::setSceneEnd(){
  setSceneEnd(getElapsedTimef());
}

void baseScene::setSceneEnd(float newEnd) {
  sceneDuration = newEnd;
  bHasEndSet = true;
}

bool baseScene::hasRecData(){
  return recData.size() != 0;
}
void baseScene::setRecData(const vector<ofxMidiRecordingEvent>& data){
  if(bAnimateScene){
    recData.clear();
    recData = data;
    cout << "setRecData: " << recData.size() << "  " << dataPath << endl;
    saveMidi(recData, bHasEndSet ? sceneDuration : -1, dataPath+"/paramsRecording.xml");
  }
}
const vector<ofxMidiRecordingEvent>& baseScene::getRecData(){
  return recData;
}
void baseScene::setAuthor(string newAuthor) {
  author = newAuthor;
}

void baseScene::setOriginalArtist(string newOriginalArtist) {
  originalArtist = newOriginalArtist;
}

float baseScene::getElapsedTimef(){
  return (ofGetElapsedTimeMicros() - startTime)/1000000.;
}
uint64_t baseScene::getFrameNum(){
  return ofGetFrameNum() - startFrame;
}

void baseScene::resetTiming(){
  startTime = ofGetElapsedTimeMicros();
  startFrame = ofGetFrameNum();
}
