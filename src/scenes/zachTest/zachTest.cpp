
#include "zachTest.h"

void zachTest::setup(){
  
// setup pramaters
	radius.set("radius", 50, 0, 200);
    xPos.set("xPos", 100, 0, 500);
    yPos.set("yPos", 100, 0, 500);
    
	parameters.add(radius);
    parameters.add(xPos);
    parameters.add(yPos);

    setAuthor("Zach Lieberman");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/zachTest/exampleCode.cpp");
    
   
    
}

void zachTest::update(){
    
}

void zachTest::draw(){
    
    ofSetColor(255);
    ofDrawCircle(xPos,yPos,radius);
    ofDrawLine(0,0,dimensions.width, dimensions.height);
}
