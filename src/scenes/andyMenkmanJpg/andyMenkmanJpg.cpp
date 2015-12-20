
#include "andyMenkmanJpg.h"

void andyMenkmanJpg::setup(){
  
    bender.setup("scenes/andyMenkmanJpg/images/", "jpg");
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, bender.lineCount);
    startLine.set("startLine", 50, 0, bender.lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
 
    ofBackground(0);
    ofSetColor(255);

    setAuthor("Andy Dayton");
    setOriginalArtist("Rosa Menkman");
    loadCode("scenes/andyMenkmanJpg/exampleCode.cpp");
}

void andyMenkmanJpg::update(){
    bender.update(startLine, numberOfLines);
}

void andyMenkmanJpg::draw(){
    bender.draw(0, 0, dimensions.getWidth(), dimensions.getHeight());
}
