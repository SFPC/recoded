//
//  baseScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "baseScene.h"




void baseScene::loadCode( string fileName ){
    
    ofBuffer buffer = ofBufferFromFile(fileName);
    code = "";
    
    for (auto line : buffer.getLines()){
        code += line;
        code += "\n";
    }
    
   
    
    
}



string baseScene::getCodeWithParamsReplaced(){
    
    
    ofParameter < float > floatParam;
    
    string codeWithParams = code;
    
    for (auto p : parameters){
        
        string name = p->getName();
        string templateName = "[[" + name + "]]";
        
        if (p->type() == floatParam.type()){
            float f = p->cast<float>();
            ofStringReplace(codeWithParams, templateName, ofToString(f, 1));
        } else {
            ofStringReplace(codeWithParams, templateName, ofToString(*p));
        }
        
    }
    
    return codeWithParams;

}
