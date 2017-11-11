
#include "diegoScene_01.h"

void diegoScene_01::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in diegoScene_01.h
    //parameters.add(param.set("param", 5, 0, 100));
    
    ofSetCircleResolution(100);
	
	parameters.add(speed.set("Speed", 0.1, 0, 2));
	parameters.add(rotate.set("Rotate", 0.5, 0.0001, 2));
    parameters.add(noiseScale.set("Noise Scale", 0.01,0,1));
	parameters.add(oscilationScale.set("Oscilation Scale", 0, -80,80));
    setAuthor("Diego Salinas");
    setOriginalArtist("John Whitney");

    loadCode("scenes/diegoScene_01/exampleCode.cpp");
}

void diegoScene_01::update(){
	
}

void diegoScene_01::draw(){
	ofPushStyle();
	float time = ofGetElapsedTimef();
	float n = ofNoise(noiseScale*time);
    ofSetColor(ofColor::fromHsb(n*255,255,255));
    ofPushMatrix();
    ofTranslate(dimensions.width/2, dimensions.height/2);
	
    for (int i = 0; i < 2000; i++){
        ofNoFill();
        ofRotate(time*rotate);
        ofDrawCircle(i, i, 80 + sin(time * speed) * oscilationScale);
    }
	ofPopMatrix();
	ofPopStyle();
}
