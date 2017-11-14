
#include "zzEyeScene.h"

void zzEyeScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzEyeScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzEyeScene/exampleCode.cpp", false);
}

void zzEyeScene::update(){
    
}

void zzEyeScene::draw(){
}
