
#include "yeseulScene.h"




void yeseulScene::setup(){
    
    
    angle.set("angle", 0, -180, 180);
    width.set("width", 100, 20, 400);
    parameters.add(angle);
    parameters.add(width);
    
    loadCode("exampleScene/exampleCode.cpp");
    
    
}

void yeseulScene::update(){
    
    // arbitrarily wiggle things up....  so we can see if this works.
    // later
    
    angle = angle.getMin() + ofMap(sin(ofGetElapsedTimef()*0.5), -1, 1, 0, 1) * (angle.getMax() - angle.getMin());
    
//    width = width.getMin() + ofMap(sin(ofGetElapsedTimef()*0.7), -1, 1, 0, 1) * (width.getMax() - width.getMin());
    
}

void yeseulScene::draw(){
    
    
    
    float counter;
    counter+=0.1;
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);
    ofFill();


    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            ofRotate(counter*width);
            ofDrawCircle(j*3, j*3, 1);
        }
    }
    
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
    string codeReplaced = getCodeWithParamsReplaced();
    
    
    
    ofDrawBitmapString(codeReplaced, 40,40);
    
}
