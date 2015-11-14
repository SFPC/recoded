
#include "emptyScene.h"

void emptyScene::setup(){
    
//    parameters.add(param);

    loadCode("emptyScene/exampleCode.cpp");
}

void emptyScene::update(){
    
}

void emptyScene::draw(){
    
}

void emptyScene::drawCode(){
    string codeReplaced = getCodeWithParamsReplaced();
    ofDrawBitmapString(codeReplaced, 40,40);
}

