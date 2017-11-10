
#include "weiMolnar_01.h"

void weiMolnar_01::setup(){
  
// setup pramaters
    parameters.add(xOffset.set("Size X", 28, 0, 30));
    parameters.add(yOffset.set("Size Y", 28, 0, 30));
	parameters.add(speed.set("Speed", 1,0,3));
    
    setAuthor("HE Wei");
    setOriginalArtist("Vera Molnar");
    
    loadCode("scenes/weiMolnar_01/exampleCode.cpp");
}

void weiMolnar_01::update(){
    
}

void weiMolnar_01::draw(){
    ofSeedRandom(15);
    
//    for (int i = 0; i < 12; i++){
//        for (int j=0; j < 12; j++){
//
//            float time = ofGetElapsedTimef();
//
//            int green = ofMap(sin(time), -1,1, 0, 255);
//            ofSetColor(ofMap(sin(time*2), -1,1, 0, 255),
//                       ofMap(sin(time*10), -1,1, 100, 255),
//                       ofMap(cos(time*4), -1,1, 0, 255));
//            ofFill();
//            ofBeginShape();
//                ofVertex( 100+i*50+ofMap(sin(time*5), -1, 1, 0, 10)+ofRandom(-20,20),100+j*50+ofRandom(-20,20));
//                ofVertex( 100+i*50+ofMap(cos(time)*2, -1, 1, -0, 0)+ofRandom(-30,30),130+j*50+ofMap(cos(time*10), -1, 1, -10, 10));
//                ofVertex( 130+i*50+ofMap(sin(time), -1, 1, -20, 0)+ofRandom(-30,30),130+j*50+ofMap(sin(time*2)*2, -1, 1, 0, 10)+ofRandom(-30,30));
//                ofVertex( 130+i*50+ofRandom(-30,30),100+j*50+ofMap(cos(time*20), -1, 1, -10, 0)+ofRandom(-40,40));
//            ofEndShape();
//        }
//    }
    

    
    int count = 10;
    float time = ofGetElapsedTimef() * speed;
    ofSetColor(ofMap(sin(time*2), -1,1, 0, 255),
               ofMap(sin(time*10), -1,1, 100, 255),
               ofMap(cos(time*4), -1,1, 0, 255));
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
            float x = ofMap(i + 1, 0, count + 1, 0, MIN(dimensions.width, dimensions.height));
            float y = ofMap(j + 1, 0, count + 1, 0, MIN(dimensions.width, dimensions.height));
            ofBeginShape();
                ofVertex(x + ofRandom(-xOffset, xOffset) + ofMap(sin(time*5), -1, 1, 0, 10), y + ofRandom(-yOffset, yOffset));
                ofVertex(x + ofMap(cos(time) * 2, -1, 1, -0, 0) + ofRandom(-xOffset, xOffset), y + ofMap(cos(time * 10), -1, 1, -10, 10));
                ofVertex(x + ofMap(sin(time), -1, 1, -20, 0) + ofRandom(-xOffset, xOffset), y + ofMap(sin(time * 2) * 2, -1, 1, 0, 10) + ofRandom(-yOffset, yOffset));
                ofVertex(x + ofRandom(-xOffset, xOffset), y + ofMap(cos(time * 20), -1, 1, -10, 0) + ofRandom(-yOffset, yOffset));
            ofEndShape();
        }
    }
}
