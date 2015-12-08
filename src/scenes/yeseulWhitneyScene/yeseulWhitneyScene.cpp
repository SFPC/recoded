
#include "yeseulWhitneyScene.h"


void yeseulWhitneyScene::setup(){
    
    angle.set("angle", 0, 0, 90);
    numberOfPattern.set("number of pattern", 1, 1, 5);
    color.set("color", 150, 145, 255);
    parameters.add(angle);
    parameters.add(numberOfPattern);
    parameters.add(color);
    
    loadCode("yeseulWhitneyScene/exampleCode.cpp");

}

void yeseulWhitneyScene::update(){
    
    angle.set(ofMap(sin(ofGetElapsedTimef()), -1, 1, 90, 0));
    numberOfPattern.set(ofMap(sin(ofGetElapsedTimef()), -1, 1, 1, 6));
    color.set(ofMap(sin(ofGetElapsedTimef()), -1, 1, 145, 255));

}

void yeseulWhitneyScene::draw(){

    columnCount = 0;
    rowCount = 0;
    for (int i=1; i<dimensions.width; i+=dimensions.width/numberOfPattern) {
        columnCount++;
        for (int j=1; j<dimensions.height; j+=dimensions.height/numberOfPattern) {
            rowCount++;
            drawPattern(dimensions.width/(numberOfPattern+1)*rowCount, dimensions.height/(numberOfPattern+1)*columnCount);
        }
        rowCount = 0;
    }
    
}

void yeseulWhitneyScene::drawPattern(int x, int y){
    
    ofPushMatrix();
    
    ofTranslate(x, y);
    ofRotate(angle);

    ofColor c = ofColor::fromHsb(color, 255, 255);
    ofSetColor(c);
    ofFill();
    
    for (int i=0; i<21*(ceil(numberOfPattern/1.7)); i++){
        for (int j=0; j<120/(numberOfPattern); j+=numberOfPattern){
            ofRotate(PI/numberOfPattern*2);
            ofDrawCircle(j*5, j*5, 5/numberOfPattern);
        }
    }
    
    ofPopMatrix();
    
}