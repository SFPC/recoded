
#include "Guillermo_Whitney_catalogue_1.h"

void Guillermo_Whitney_catalogue_1::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in Guillermo_Whitney_catalogue_1.h
    //parameters.add(param.set("param", 5, 0, 100));

	img.load("scenes/Guillermo_Whitney_catalogue_1/image.png");
	speed.set("Speed", 0.1, 0, 3);
//parameters.add(speed);
parameters.add(inRad.set("Inner Radius", 180, 0, 400));
parameters.add(midRad.set("Mid Radius", 360, 0, 400));
parameters.add(numLines.set("Num lines", 16, 0, 30));

    setAuthor("Guillermo Montecinos");
    setOriginalArtist("John Whitney");

    loadCode("scenes/Guillermo_Whitney_catalogue_1/exampleCode.cpp");
}

void Guillermo_Whitney_catalogue_1::update(){
    
}

void Guillermo_Whitney_catalogue_1::draw(){
   ofBackground(0);
    //ofSetColor(255,100,100,150);
    //Translation to the center

	float phiLines = 2*PI/numLines; //Span between lines centre

    ofPoint center = dimensions.getCenter();
    ofTranslate(center);
    for (int  i = 0; i < numLines; i++) {
		
        x = ofMap(sin(ofGetElapsedTimef()),-1,1,inRad,midRad)*cos(i * phiLines);
        y = ofMap(sin(ofGetElapsedTimef()),-1,1,inRad,midRad)*sin(i * phiLines);
		
        //New reference matrix
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(360 * ofGetElapsedTimef() * speed + ofMap(i*phiLines,0,2*PI,0,360));
        //For loop for define and draw dots
        for (int j = -7; j < 7; j++) {
            ofPoint a = ofPoint(2*midRad/14*j,0);
            ofSetColor(255,100,100,255);
            img.draw(a, 100, 100);
        }
        
        ofPopMatrix();
    }
}
