//
//  triangleScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "triangleScene.h"


void triangleScene::setup(){
    numTriangles.set("numTriangles", 5, 0, 100);
    parameters.add(numTriangles);
    loadCode("triangleScene/triangle.txt");
    
}
void triangleScene::update(){
    
}
void triangleScene::draw(){
    
    ofSetColor(255,255,255,5);

    for (int i = 0; i < numTriangles; i++){
        
        ofDrawTriangle( ofRandom(0, ofGetWidth()),
                   ofRandom(0, ofGetHeight()),
                   ofRandom(0, ofGetWidth()),
                   ofRandom(0, ofGetHeight()),
                   ofRandom(0, ofGetWidth()),
                   ofRandom(0, ofGetHeight()));
        
    }
    
    ofSetColor(255,255,255);
    
    string codeReplaced = getCodeWithParamsReplaced();
    ofDrawBitmapString(codeReplaced, 40,40);

}

