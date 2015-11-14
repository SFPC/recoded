
#include "emptyScene.h"

void emptyScene::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    loadCode("emptyScene/exampleCode.cpp");
}

void emptyScene::update(){
    
}

void emptyScene::draw(){
    drawCode();
}

void emptyScene::drawCode(){
    string codeReplaced = getCodeWithParamsReplaced();
    ofDrawBitmapString(codeReplaced, 40,40);
}

