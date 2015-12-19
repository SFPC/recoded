
#include "andyMenkmanDataBendsGif.h"

void andyMenkmanDataBendsGif::setup(){
  
    bender.setup("scenes/andyMenkmanDataBends/images/", "gif");
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, bender.lineCount);
    startLine.set("startLine", 50, 0, bender.lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
 
    ofBackground(0);
    ofSetColor(255);

    setAuthor("Andy Dayton");
    setOriginalArtist("Rosa Menkman");
    loadCode("scenes/andyMenkmanDataBends/code/gif.txt");
}

void andyMenkmanDataBendsGif::update(){
    bender.update(startLine, numberOfLines, false);
}

void andyMenkmanDataBendsGif::draw(){
    bender.draw(0, 0, dimensions.getWidth(), dimensions.getHeight());
}
