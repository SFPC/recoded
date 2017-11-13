
#include "EstherMolnarScene.h"

void EstherMolnarScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in EstherMolnarScene.h
    //parameters.add(param.set("param", 5, 0, 100));
    blendMode = OF_BLENDMODE_ADD;
    
    parameters.add(color.set("color", 25, 0, 60));
    parameters.add(size.set("size", 115, 80, 140));
    parameters.add(move.set("move", 250, 0, 400));
    
    

    setAuthor("Esther Bouquet");
    setOriginalArtist("Vera Molnar");

    loadCode("scenes/EstherMolnarScene/exampleCode.cpp");
	

	
}

void EstherMolnarScene::update(){
    
}

void EstherMolnarScene::draw(){
	ofBackground(0);
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofEnableBlendMode(OF_BLENDMODE_ADD);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ofSetColor(255,color*i/2,color*j/2);
			ofDrawRectangle(50 + i * 140 + ofRandom(-move, move) / 30, 50 + j * 140 + ofRandom(-move, move) / 30, size, size);
		}
	}
	ofPopStyle();
	ofDisableBlendMode();



}
