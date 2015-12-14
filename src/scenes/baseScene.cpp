//
//  baseScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "baseScene.h"



vector < int > positionsOfSubstring(string str, string sub){
    vector <int> positions; // holds all the positions that sub occurs within str
    size_t pos = str.find(sub, 0);
    while(pos != string::npos){
        positions.push_back(pos);
        pos = str.find(sub,pos+1);
    }
    return positions;
}


void baseScene::loadCode( string fileName ){
    
    ofBuffer buffer = ofBufferFromFile(fileName);
    code = "";
    
    for (auto line : buffer.getLines()){
        code += line;
        code += "\n";
    }
    
    nParams = parameters.size();
    
    ofParameter < float > floatParam;
    
    paramsToReplace.resize(nParams);
    paramChangedEnergy.resize(nParams);
    
    for (int i = 0; i < nParams; i++){
        
        string name = parameters[i].getName();
        string templateName = "[[" + name + "]]";
        paramLengths.push_back(templateName.size());
        vector < int > paramLocations = positionsOfSubstring(code, templateName);
        paramPositions.push_back(paramLocations);
        
        
        if (parameters[i].type() == floatParam.type()){
            paramsToReplace[i] = ofToString(parameters[i], 1);
        } else {
            paramsToReplace[i] = ofToString(parameters[i]);
        }

        paramChangedEnergy[i] = 0;
        
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



vector < codeLetter > baseScene::getCodeWithParamsReplaced2(){
    
    vector < string > prevStrings = paramsToReplace;
    
    vector < codeLetter > codeLetters;
    

    for (int i = 0; i < nParams; i++){
        paramsToReplace[i] = "";                // fill these in as we calculate them.
    }
    
    
    ofParameter < float > floatParam;
    
    for (int i = 0; i < code.length(); i++){
        
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
            
            codeLetter tempLetter;
            tempLetter.character = code[i];
            tempLetter.idOfChar = -1;
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
                    codeLetters.push_back(tempLetter);
                }
                //output += paramsToReplace[which];
                
                
                i += toSwap.length-1;
            } else {
                
                if (parameters[which].type() == floatParam.type()){
                    paramsToReplace[which] = ofToString(parameters[which], 1);
                } else {
                    paramsToReplace[which] = ofToString(parameters[which]);
                }
                for (auto p : paramsToReplace[which]){
                    codeLetter tempLetter;
                    tempLetter.character = p;
                    tempLetter.idOfChar = which;
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
            paramChangedEnergy[i] += 0.1;
            if (paramChangedEnergy[i] > 2){
                paramChangedEnergy[i] = 2;
            }
        }
    }
    // vector < string > prevStrings = paramsToReplace;
    
    
    for (int i = 0; i < nParams; i++){
        paramChangedEnergy[i] *= 0.95;                          // too fast?
    }
 
    return codeLetters;
    

    
}



string baseScene::getCodeWithParamsReplaced(){
    
    
    vector < string > paramsToReplace;
    paramsToReplace.resize(nParams);
    for (int i = 0; i < nParams; i++){
        paramsToReplace[i] = "";                // fill these in as we calculate them.
    }
    
    
    ofParameter < float > floatParam;
    
    
    string output;
    for (int i = 0; i < code.length(); i++){
        
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
            output += code[i];
        } else {
            
            int which = toSwap.paramID;
            //cout << toSwap.length << endl;
            // have we calculated this already???
            if (paramsToReplace[which] != ""){
                output += paramsToReplace[which];
                i += toSwap.length-1;
            } else {
                
                if (parameters[which].type() == floatParam.type()){
                    paramsToReplace[which] = ofToString(parameters[which], 1);
                } else {
                    paramsToReplace[which] = ofToString(parameters[which]);
                }
                output += paramsToReplace[which];
                i += toSwap.length-1;
            }
            
            
        }
        
    }
    
    return output;
    
//    ofParameter < float > floatParam;
//    
//    string codeWithParams = code;
//    
//    for (auto p : parameters){
//        
//        string name = p->getName();
//        string templateName = "[[" + name + "]]";
//        
//        if (p->type() == floatParam.type()){
//            float f = p->cast<float>();
//            ofStringReplace(codeWithParams, templateName, ofToString(f, 1));
//        } else {
//            ofStringReplace(codeWithParams, templateName, ofToString(*p));
//        }
//        
//    }
//    
//    return codeWithParams;

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
