
#include "zzWatermelonScene.h"

void zzWatermelonScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzWatermelonScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzWatermelonScene/exampleCode.cpp");
    
    
    bg.load("zzScenes/zzWatermelonScene/images/bg.png");
    for (int i = 0; i < 7; i++){
        imgs[i].load("zzScenes/zzWatermelonScene/images/" + ofToString(i) + ".png");
        
    }
}

void zzWatermelonScene::update(){
    
}

void zzWatermelonScene::draw(){
    
    bg.draw(0,0,dimensions.width, dimensions.height);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(dimensions.width/2, dimensions.height/2);
    for (int i = 0; i < 6; i++){
        ofRotateZ( sin(fmod(getElapsedTimef()*i, TWO_PI)) * 300 * sin(getElapsedTimef() ));
        imgs[i].draw(0,0,dimensions.width, dimensions.height);
    
    }
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
}
