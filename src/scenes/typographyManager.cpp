#include "typographyManager.hpp"

//-------------------------------------------------------------------------------------
vector < int > positionsOfSubstring(string str, string sub){
  vector <int> positions; // holds all the positions that sub occurs within str
  size_t pos = str.find(sub, 0);
  while(pos != string::npos){
    positions.push_back(pos);
    pos = str.find(sub,pos+1);
  }
  return positions;
}


void typographyManager::loadSounds(){

  string path = "sounds/";

  keystroke1Sound.load(path+"keystroke1.aiff");
  keystroke1Sound.setMultiPlay(true);

  keystroke2Sound.load(path+"keystroke2.aiff");
  keystroke2Sound.setMultiPlay(true);

}

//-------------------------------------------------------------------------------------
void typographyManager::setup(baseScene * bs, float animationTime){


  for (int i = 0; i < paramPositions.size(); i++){
    paramPositions[i].clear();
  }
  paramPositions.clear();
  paramLengths.clear();
  paramsInOrder.clear();
  paramsToReplace.clear();
  paramChangedEnergy.clear();
  paramEnergy.clear();
  paramEnergyTarget.clear();

  setupTime = ofGetElapsedTimef();
  animTime = animationTime;


  nParams = bs->parameters.size();

  ofParameter < float > floatParam;

  paramsToReplace.resize(nParams);
  paramChangedEnergy.resize(nParams);
  paramEnergy.resize(nParams);
  paramEnergyTarget.resize(nParams);

  for (int i = 0; i < nParams; i++){

    string name = bs->parameters[i].getName();
    string templateName = "[[" + name + "]]";
    paramLengths.push_back(templateName.size());
    vector < int > paramLocations = positionsOfSubstring(bs->code, templateName);
    paramPositions.push_back(paramLocations);

    if (bs->parameters[i].type() == floatParam.type()){
      paramsToReplace[i] = ofToString(bs->parameters[i], 1);
    } else {
      paramsToReplace[i] = ofToString(bs->parameters[i]);
    }
    //
    //        if (bs->parameters[i].type() == floatParam.type()){
    //          float ff = bs->parameters[i].cast<float>();
    //          paramsToReplace[i] = ofToString(ff, 1);
    //        } else {
    //          float ff = bs->parameters[i].cast<float>();
    //          paramsToReplace[i] = ofToString(ff, 1);
    //        }

    paramChangedEnergy[i] = 0;
    paramEnergy[i] = 0;
    paramEnergyTarget[i] = 0;

    for (int j = 0; j < paramLocations.size(); j++){
      templatePos pos;
      pos.length = templateName.size();
      pos.paramName = name;
      pos.paramID = i;
      pos.position = paramLocations[j];
      paramsInOrder.push_back(pos);
    }
  }


  sort(paramsInOrder.begin(), paramsInOrder.end(),
       [](const templatePos & a, const templatePos & b) -> bool
       {
         return a.position < b.position;
       });

  for (int i = 0; i < paramsInOrder.size(); i++){
    //cout << paramsInOrder[i].position << endl;
  }


}





//-------------------------------------------------------------------------------------
vector < codeLetter > typographyManager::getCodeWithParamsReplaced( baseScene * bs ){

  vector < string > prevStrings = paramsToReplace;

  vector < codeLetter > codeLetters;


  for (int i = 0; i < nParams; i++){
    paramsToReplace[i] = "";                // fill these in as we calculate them.
  }

  ofParameter < bool > boolParam;
  ofParameter < float > floatParam;
  ofParameter < int > intParam;

  bool insideComment = false;
  for (int i = 0; i < bs->code.length(); i++){

    // check if this int is in our list of position...
    bool bIsParam = false;
    templatePos toSwap;
    for (auto p : paramsInOrder){
      if (p.position == i){
        toSwap = p;
        bIsParam = true;
        //cout << toSwap.paramName << endl;
      }
    }

    if (!bIsParam){
      char nextChar = 0;
      if (i < bs->code.length()-1) {
        nextChar = bs->code[i+1];
      }
      char currChar = bs->code[i];

      if (currChar == '/' && nextChar == '/') {
        insideComment = true;
      } else if (currChar == '\n') {
        insideComment = false;
      }

      codeLetter tempLetter;
      tempLetter.character = currChar;
      tempLetter.idOfChar = -1;
      tempLetter.type = insideComment ? CHARACTER_COMMENT : CHARACTER_CODE;
      codeLetters.push_back(tempLetter);


    } else {

      int which = toSwap.paramID;
      //cout << toSwap.length << endl;
      // have we calculated this already???
      if (paramsToReplace[which] != ""){

        for (auto p : paramsToReplace[which]){
          codeLetter tempLetter;
          tempLetter.character = p;
          tempLetter.idOfChar = which;
          tempLetter.type = CHARACTER_PARAM;
          codeLetters.push_back(tempLetter);
        }
        //output += paramsToReplace[which];


        i += toSwap.length-1;
      } else {

        if (bs->parameters[which].type() == boolParam.type()){
          if(bs->parameters[which].cast<bool>()){
            paramsToReplace[which] = "true";
          } else {
            paramsToReplace[which] = "false";
          }
        } else if (bs->parameters[which].type() == intParam.type()){
          int ip = bs->parameters[which].cast<int>();
          paramsToReplace[which] = ofToString(ip);
        } else if (bs->parameters[which].type() == floatParam.type()){
          float ff = bs->parameters[which].cast<float>();
          paramsToReplace[which] = ofToString(ff,4);
        } else {
          float ff = bs->parameters[which].cast<float>();
          paramsToReplace[which] = ofToString(ff,4);
        }
        for (auto p : paramsToReplace[which]){
          codeLetter tempLetter;
          tempLetter.character = p;
          tempLetter.idOfChar = which;
          tempLetter.type = CHARACTER_PARAM;
          codeLetters.push_back(tempLetter);
        }
        i += toSwap.length-1;
      }


    }

  }


  // did we change ? let's do some animation :

  for (int i = 0; i < prevStrings.size(); i++){
    //paramsToReplace[i]
    //prevStrings[i];
    if (prevStrings[i] != paramsToReplace[i]){
      // If we've decayed, don't go way back up.
      float mappedEnergy = ofMap(paramEnergy[i], 0, paramEnergyTarget[i], 0, 0.9999f);
      if (mappedEnergy < 0.8)
        paramEnergyTarget[i] = paramEnergy[i];

      if (bs->parameters[i].type() == boolParam.type()
          || bs->parameters[i].type() == intParam.type()) {
        paramChangedEnergy[i] = 1;

        paramEnergyTarget[i] = 1;
      } else {
        paramChangedEnergy[i] += 0.1;
        if (paramChangedEnergy[i] > 1){
          paramChangedEnergy[i] = 1;
        }

        paramEnergyTarget[i] += energyChangePerFrame;
        paramEnergyTarget[i] = min(paramEnergyTarget[i], 1.0f);
      }
      paramEnergy[i] = paramEnergyTarget[i];
    }
  }
  // vector < string > prevStrings = paramsToReplace;

  for (int i = 0; i < nParams; i++){
    paramChangedEnergy[i] *= 0.96;                          // too fast?

    float mappedEnergy = ofMap(paramEnergy[i], 0, paramEnergyTarget[i], 0, 0.99999f);
    if (mappedEnergy > 0.5)
      mappedEnergy *= powf(mappedEnergy, energyDecayRate);
    else
      mappedEnergy *= (1.0 - energyDecayRate);
    paramEnergy[i] = ofMap(mappedEnergy, 0, 1, 0, paramEnergyTarget[i]);

    if (paramEnergyTarget[i] > 0.001 && paramEnergy[i] < 0.0001) {
      paramEnergy[i] = 0.0001;
    }
  }

  return codeLetters;
}
