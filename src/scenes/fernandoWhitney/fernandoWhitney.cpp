
#include "fernandoWhitney.h"

void fernandoWhitney::setup(){
    player.load("scenes/fernandoWhitney/video.mp4");
    player.play();
    
    setAuthor("Fernando Ramallo");
    setOriginalArtist("John Whitney");
    
    // setup pramaters
    //    param.set("param", 5, 0, 100);
    //    parameters.add(param);
    
    loadCode("scenes/fernandoWhitney/exampleCode.cpp");
}

void fernandoWhitney::update(){
    player.update();
}

void fernandoWhitney::draw(){
    player.draw(dimensions.x, dimensions.y);
}

