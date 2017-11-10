
#include "fernandoWhitney2.h"

void fernandoWhitney2::setup(){
    player.load("scenes/fernandoWhitney2/video.mp4");
    player.play();
    
    setAuthor("Fernando Ramallo");
    setOriginalArtist("John Whitney");
    
    // setup pramaters
    //    param.set("param", 5, 0, 100);
    //    parameters.add(param);
    
    loadCode("scenes/fernandoWhitney/exampleCode.cpp");
}

void fernandoWhitney2::update(){
    player.update();
}

void fernandoWhitney2::draw(){
    player.draw(dimensions.x, dimensions.y);
}

