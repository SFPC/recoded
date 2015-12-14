//
//  baseScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "baseScene.h"


void baseScene::loadCode( string fileName ){
    
    ofBuffer buffer = ofBufferFromFile(fileName);
    code = "";
    
    for (auto line : buffer.getLines()){
        code += line;
        code += "\n";
    }

}

void baseScene::setAuthor(string newAuthor) {
    author = newAuthor;
}

void baseScene::setOriginalArtist(string newOriginalArtist) {
    originalArtist = newOriginalArtist;
}

float baseScene::getElapsedTimef(){
    return (ofGetElapsedTimeMicros() - startTime)/1000000.;
}
uint64_t baseScene::getFrameNum(){
    return ofGetFrameNum() - startFrame;
}

void baseScene::resetTiming(){
    startTime = ofGetElapsedTimeMicros();
    startFrame = ofGetFrameNum();
}
