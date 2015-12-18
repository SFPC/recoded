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

    // Remove trailing newlines and spaces
    code.erase(std::find_if(code.rbegin(),
                            code.rend(),
                            std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
               code.end());
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
