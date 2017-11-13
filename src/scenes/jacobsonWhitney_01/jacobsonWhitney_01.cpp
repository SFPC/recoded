
#include "jacobsonWhitney_01.h"

void jacobsonWhitney_01::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    
    imageSize.set("imageSize", 25, 25, 75);
    parameters.add(imageSize);
    rotationSpeed.set("rotationSpeed", 0.5, 0.5, 1);
    parameters.add(rotationSpeed);
    phaseShift.set("phaseShift", 0, 0, 20);
    parameters.add(phaseShift);
    
    img.load("scenes/jacobsonWhitney_01/image.png");
    setAuthor("Matt Jacobson");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/jacobsonWhitney_01/exampleCode.cpp");
    
}

void jacobsonWhitney_01::update(){
    img.resize(imageSize, imageSize);
}

void jacobsonWhitney_01::draw(){
    
    float framePad = 1.5;
    int countLevels = 30;
    
    ofBackground(0);
    
    ofTranslate(dimensions.width / 2, dimensions.height / 2);
    
    for (int n = 1; n < countLevels; n++) {
        for (int i = 0; i < n; i++) {
            float r = framePad * MIN(dimensions.width / 2, dimensions.height / 2) * n / countLevels;
            float t = ofMap(i, 0, n, 0, 2 * PI) + (rotationSpeed * n / countLevels) * (ofGetElapsedTimef() + ofSignedNoise(n / countLevels, 0.2 * ofGetElapsedTimef(), 0.2 * ofGetElapsedTimef()) + phaseShift);
            float x = r * cos(t) + (1 - n / countLevels) * sin(ofGetElapsedTimef() + 5 * PI * n / countLevels);
            float y = r * sin(t) + (1 - n / countLevels) * cos(ofGetElapsedTimef() + 5 * PI * n / countLevels);
            ofSetColor(127 + 0.01 * (n * i) + 80 * cos(0.6 * ofGetElapsedTimef()), 127 + 0.02 * (n * i) + 50 * cos(0.4 * ofGetElapsedTimef() + 1), 127 + 0.9 * (n * i), 255);
            ofDrawCircle(x, y, ofMap(framePad, 0.75, 2, 1, 2));
            img.draw(x - img.getWidth() / 2, y - img.getHeight() / 2);
        }
    }
    
}
