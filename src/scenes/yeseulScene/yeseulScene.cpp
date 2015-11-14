
#include "exampleScene.h"




void exampleScene::setup(){
    
    
    angle.set("angle", 0, -180, 180);
    width.set("width", 100, 20, 400);
    parameters.add(angle);
    parameters.add(width);
    
    loadCode("exampleScene/exampleCode.cpp");
    
    
}

void exampleScene::update(){
    
    // arbitrarily wiggle things up....  so we can see if this works.
    // later
    
    angle = angle.getMin() + ofMap(sin(ofGetElapsedTimef()*0.5), -1, 1, 0, 1) * (angle.getMax() - angle.getMin());
    
//    width = width.getMin() + ofMap(sin(ofGetElapsedTimef()*0.7), -1, 1, 0, 1) * (width.getMax() - width.getMin());
    
}

void exampleScene::draw(){
    
    
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);
    ofDrawRectangle(0, 0, width, 40);
    
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
    string codeReplaced = getCodeWithParamsReplaced();
    
    
    
    ofDrawBitmapString(codeReplaced, 40,40);
    
}
