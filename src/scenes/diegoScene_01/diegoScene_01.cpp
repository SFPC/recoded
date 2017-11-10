
#include "diegoScene_01.h"

void diegoScene_01::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in diegoScene_01.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Diego Salinas");
    setOriginalArtist("John Whitney");

    loadCode("scenes/diegoScene_01/exampleCode.cpp");
	
	ofSetCircleResolution(100);
    
    posX = 200;
    posY = 2000;
    radius = 2;
    
    rot1 = 0;
    rot2 = 0;
    rot3 = 0.0;
	
}

void diegoScene_01::update(){
     rot1 += 0.1;
    rot2 += 0.2;
    rot3 += 1.5;
    
    posX = cos(rot3);
    posY = sin(rot3);
	
}

void diegoScene_01::draw(){
	ofPushStyle();
    ofSetColor(ofRandom(0, 255),0,0);
    ofPushMatrix();
    ofTranslate(dimensions.width/2, dimensions.height/2);
    
    float time = ofGetElapsedTimef();
    float size = time;
    
    for (int i = 0; i < 2000; i++){
        ofNoFill();
        ofRotate(size/2);
        ofDrawCircle(i, i, 80 + sin(ofGetElapsedTimef()));
    }
	ofPopMatrix();
	ofPopStyle();
}
