
#include "zzEggScene.h"

void zzEggScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzEggScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("scenes/zzEggScene/exampleCode.cpp", false);
}

void zzEggScene::update(){
    
}

void zzEggScene::draw(){
}
