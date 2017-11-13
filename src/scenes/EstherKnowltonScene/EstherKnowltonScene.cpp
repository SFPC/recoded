
#include "EstherKnowltonScene.h"

void EstherKnowltonScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in EstherKnowltonScene.h
    //parameters.add(param.set("param", 5, 0, 100));

	img.load("scenes/EstherKnowltonScene/N00004808.jpg");
	img.setImageType(OF_IMAGE_GRAYSCALE);

	float width = ofGetWidth();

	parameters.add(posX1.set("posX1", -10, -25, 0));
	parameters.add(rotation.set("rotation", 150, 0, ofGetWidth()));
	parameters.add(alpha.set("alpha", 140, 0, 255));




    setAuthor("Esther Bouquet");
    setOriginalArtist("Ken Knowlton");

    loadCode("scenes/EstherKnowltonScene/exampleCode.cpp");
	
	
}

void EstherKnowltonScene::update(){
    
}

void EstherKnowltonScene::draw(){

	ofSetRectMode(OF_RECTMODE_CENTER);
	
	for (int i = 0; i < img.getWidth(); i=i+20) {
		for (int j = 0; j < img.getHeight(); j=j+20) {

			ofColor c = img.getColor(i, j); 
			float bright = c.getBrightness(); 

			ofPushMatrix();

			ofTranslate(i, j);
			ofRotateZ(ofMap(bright, 0, 255, 0, rotation));
			ofSetColor(255, alpha);
			ofDrawLine(posX1, 0, 5, 0);

			ofPopMatrix();
			
		}
	}
}
