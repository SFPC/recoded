
#include "andyMenkmanDataBendsTif.h"

void andyMenkmanDataBendsTif::setup(){
  
    bender.setup("andyMenkmanDataBends/images/", "tif");
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, bender.lineCount);
    startLine.set("startLine", 50, 0, bender.lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
 
    ofBackground(0);
    ofSetColor(255);

    setAuthor("Andy Dayton");
    setOriginalArtist("Rosa Menkman");
    loadCode("andyMenkmanDataBends/code/tif.txt");
}

void andyMenkmanDataBendsTif::update(){
    bender.update(startLine, numberOfLines);
}

void andyMenkmanDataBendsTif::draw(){
    bender.draw(0, 0, dimensions.getWidth(), dimensions.getHeight());
}
