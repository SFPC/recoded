
#include "veraAnimatedScene.h"


void veraAnimatedScene::setup(){
  
    smile.set("smile", 5, 0, 100);
    parameters.add(smile);

    loadCode("veraAnimatedScene/exampleCode.cpp");
}

void veraAnimatedScene::update(){
    
}

void veraAnimatedScene::draw(){
    
    ofDrawLine(0,0,ofGetWidth(), ofGetHeight());
    
    drawCode();
}

void veraAnimatedScene::drawCode(){
    string codeReplaced = getCodeWithParamsReplaced();
    ofDrawBitmapString(codeReplaced, 40,40);
}

