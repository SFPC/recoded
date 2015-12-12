
#include "yosukeVeraSansTitre.h"

void yosukeVeraSansTitre::setup(){
  
// setup pramaters
    displacementCoef.set("displacementCoef", 25, 0, 100);
    parameters.add(displacementCoef);
    margin.set("margin", 3, -50, 50);
    parameters.add(margin);

    transx.set("transx", 75, 0, 100);
    transy.set("transy", 170, 0, 500);

//    parameters.add(transx);
//    parameters.add(transy);

    loadCode("yosukeVeraSansTitre/exampleCode.cpp");
    ofBackground(0);
    ofSetBackgroundAuto(false);
}

void yosukeVeraSansTitre::update(){
    displacementCoef.set(100*abs(sin(ofGetElapsedTimef()/5.0)));

}

void yosukeVeraSansTitre::draw(){
    ofPushMatrix();
    ofTranslate(75, 170);
    //ofTranslate(transx, transy);
    ofSetColor(255);
    ofNoFill();
    for (int i=0; i<row; i++) {
        for(int j=0; j<col; j++ ){
            ofDrawRectangle(j*rectWidth+margin*j , i*rectHeight+margin*i + displacementCoef*ofNoise(j*rectWidth+margin*j, i*rectHeight+margin*i, ofGetElapsedTimef()/2.0), rectWidth, rectHeight);
        }
    }
    ofPopMatrix();
    ofFill();
    ofSetColor(0, 0, 0, 15);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}
