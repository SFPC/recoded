
#include "zzBurger.h"

void zzBurger::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzBurger.h
    parameters.add(xAmp.set("xAmp", 20, 0, 100));
    parameters.add(yAmp.set("yAmp", 20, 0, 100));
    parameters.add(xFreq.set("xFreq", 0, -0.1, 0.1));
    parameters.add(yFreq.set("yFreq", 0, -0.1, 0.1));

//    setAuthor("Put Your Name Here");
//    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzBurger/exampleCode.cpp", false);
    
    ofDirectory dir("scenes/zzBurger/images/");
    dir.allowExt("png");
    dir.listDir();
    for(int i = 0; i < dir.size(); i++){
        ofImage tmp;
        tmp.load(dir.getPath(i));
        tmp.resize(0.8 * tmp.getWidth() / tmp.getHeight() * dimensions.width, 0.8 * dimensions.height);
        assets.push_back(tmp);
    }
    
    xTime = 0;
    yTime = 0;
    
}

void zzBurger::update(){
    
    xTime += xFreq;
    yTime += yFreq;
    
}

void zzBurger::draw(){
    
    ofSetColor(0, 200, 255);
    ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
    ofSetColor(255);
    
    for (int i = assets.size() - 1; i >= 0; i--) {
        ofImage tmp = assets[i];
        float iMap = ofMap(i, 0, assets.size(), 0, 1.75 * PI);
        ofPushMatrix();
            ofTranslate(dimensions.width / 2, dimensions.height / 2);
            ofTranslate(xAmp * sin(xTime + iMap), yAmp * cos(yTime + iMap));
            tmp.draw(-tmp.getWidth() / 2, -tmp.getHeight() / 2);
        ofPopMatrix();
    }
    
}
