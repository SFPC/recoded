
#include "andyMenkmanDataBendsTif.h"

void andyMenkmanDataBendsTif::setup(){
  
    bender.setup("andyMenkmanDataBends/images/", "tif");
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, bender.lineCount);
    startLine.set("startLine", 50, 0, bender.lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
    
    loadCode("andyMenkmanDataBends/code/tif.txt");
 
    ofBackground(0);
    ofSetColor(255);
}

void andyMenkmanDataBendsTif::update(){
    bender.update(startLine, numberOfLines, true);
}

void andyMenkmanDataBendsTif::draw(){
    bender.draw(0, 0, dimensions.getWidth(), dimensions.getHeight());
}
