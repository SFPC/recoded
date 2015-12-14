
#include "yosukeVeraSansTitre.h"

void yosukeVeraSansTitre::setup(){
  
// setup pramaters
    displacementCoef.set("displacementCoef", 25, 0, 100);
    parameters.add(displacementCoef);
    margin.set("margin", 3, -50, 50);
    parameters.add(margin);

    transx.set("transx", 15, 0, 100);
    transy.set("transy", 85, 0, 500);

//    parameters.add(transx);
//    parameters.add(transy);

    ofBackground(0);
    ofSetBackgroundAuto(false);

    loadCode("yosukeVeraSansTitre/exampleCode.cpp");
}

void yosukeVeraSansTitre::update(){
    displacementCoef.set(100*abs(sin(ofGetElapsedTimef()/5.0)));

}

void yosukeVeraSansTitre::draw(){
    ofPushMatrix();
    ofTranslate(15, 85);
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
