
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
    imgs[0].load("zzScenes/zzWatermelonScene/images/aa.png");
    imgs[1].load("zzScenes/zzWatermelonScene/images/bb.png");
    imgs[2].load("zzScenes/zzWatermelonScene/images/cc.png");
    imgs[3].load("zzScenes/zzWatermelonScene/images/dd.png");
    imgs[4].load("zzScenes/zzWatermelonScene/images/ee.png");
    imgs[5].load("zzScenes/zzWatermelonScene/images/ff.png");
    imgs[6].load("zzScenes/zzWatermelonScene/images/gg.png");
}

void zzWatermelonScene::update(){
    
}

void zzWatermelonScene::draw(){
    
    bg.draw(0,0,dimensions.width, dimensions.height);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(dimensions.width/2, dimensions.height/2);
    for (int i = 0; i < 6; i++){
        ofPushMatrix();
        ofRotateZ( getElapsedTimef() * 40 +  sin(fmod(getElapsedTimef()*(i*0.1 + 1), TWO_PI)) * 300 * ofMap(sin(getElapsedTimef() ), -0.8, 1, 0, 1, true));
        imgs[i].draw(0,0,dimensions.width, dimensions.height);
        ofPopMatrix();
        
    }
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
}
