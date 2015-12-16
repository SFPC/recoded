
#include "andyMenkmanDataBendsJpg.h"

void andyMenkmanDataBendsJpg::setup(){
  
    bender.setup("scenes/andyMenkmanDataBends/images/", "jpg");
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, bender.lineCount);
    startLine.set("startLine", 50, 0, bender.lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
 
    ofBackground(0);
    ofSetColor(255);

    setAuthor("Andy Dayton");
    setOriginalArtist("Rosa Menkman");
    loadCode("scenes/andyMenkmanDataBends/code/jpg.txt");
}

void andyMenkmanDataBendsJpg::update(){
    bender.update(startLine, numberOfLines);
}

void andyMenkmanDataBendsJpg::draw(){
    bender.draw(0, 0, dimensions.getWidth(), dimensions.getHeight());
}
