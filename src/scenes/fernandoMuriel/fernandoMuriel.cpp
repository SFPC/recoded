
#include "fernandoMuriel.h"

void fernandoMuriel::setup(){
    
    player.load("scenes/fernandoMuriel/video.mp4");
    player.play();
    
    setAuthor("Fernando Ramallo");
    setOriginalArtist("Muriel Cooper");
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    loadCode("scenes/fernandoMuriel/exampleCode.cpp");
}

void fernandoMuriel::update(){
    player.update();
}

void fernandoMuriel::draw(){
    player.draw(dimensions.x, dimensions.y);
}
