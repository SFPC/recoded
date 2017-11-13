
#include "niklasLissajous.h"

void niklasLissajous::setup(){
  
    ofSetFrameRate(60);
    ofSetBackgroundColor(15);
    ofSetColor(240);
    numCopys = 40;
    
    //layout
    numElement = 1;
    
    
    numElement.set("Copys", 1, 2, 4);
        parameters.add(numElement);
    innerCopys.set("Inner Copys", 40, 1, 40);
        parameters.add(innerCopys);
    rotationSpeed.set("Draw Speed", 2, -3, 3);
        parameters.add(rotationSpeed);
    sinAdder.set("Sine Shape", 1, 0.5, 4);
        parameters.add(sinAdder);
    
    setAuthor("Niklas May");
    setOriginalArtist("Oscilloscope");
    loadCode("scenes/niklasLissajous/exampleCode.cpp");
}

void niklasLissajous::update(){
    // layout
    frame = 0.9;
    scaleElement = 0.8;
    width = dimensions.width * frame / numElement;
    height = dimensions.height * frame / numElement;
    
}

void niklasLissajous::lissajous(float xIn, float yIn, float widthIn, float heightIn, float angleIn){
    
    radius = widthIn * 0.35;
//    speed = 1.5 * ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 3);
//    adder = ofMap(ofGetMouseY(), 50, ofGetHeight() - 50, 1, 4);
    speed = 1.5 * rotationSpeed;
    adder = sinAdder;
    xOrigin = xIn + widthIn * 0.5 ;
    yOrigin = yIn + heightIn * 0.5;
    sinAngle = ofGetElapsedTimef() * speed;
    cosAngle = ofGetElapsedTimef() * speed * adder;
    
    myLine = ofPolyline();
    
    for (int i =0; i < 500; i++) {
        float increment = (float)i * 0.01;
        myLine.addVertex(xOrigin + radius * sin(angleIn + increment * speed * (int) adder + sinAngle),
                         yOrigin + radius * cos(increment * speed));
    }
    
    ofSetLineWidth(widthIn * 0.01);
    myLine.draw();
}

void niklasLissajous::draw(){
    
    ofPushStyle();
        ofSetColor(15);
        ofDrawRectangle(dimensions);
    ofPopStyle();
    
    ofTranslate((dimensions.width - dimensions.width * frame) * 0.5,
                (dimensions.height - dimensions.height * frame) * 0.5);
    
    for (int i = 0; i < numElement; i++) {
        for (int j = 0; j < numElement; j++) {
            for (int k = 0; k < innerCopys; k++) {
                
                container.set(0 + i * width, 0 + j * height, width, height);
                container.scaleFromCenter(scaleElement);
                container.scaleFromCenter(ofMap(k, 0, innerCopys, 1, 0));
                
                ofSetColor(240 - k * 10);
                
                lissajous(container.getX() + k * ofMap(sin(ofGetElapsedTimef() * 1.25) ,
                                                       -1, 1, -container.getWidth() * 0.025, container.getWidth() * 0.025),
                          container.getY(),
                          container.getWidth(),
                          container.getHeight(),
                          i * 0.25 + (j * 0.5));
            }
        }
    }
}
