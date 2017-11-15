
#include "zzDonutScene.h"

void zzDonutScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzDonutScene.h
    //parameters.add(param.set("param", 5, 0, 100));
    
    
    //data/zzScenes/zzDonutScene
    
    parameters.add(xSpeed.set("xSpeed", 0.02, 0, 1));
    parameters.add(ySpeed.set("ySpeed", 0.01, 0, 1));
    parameters.add(donutScale.set("donutScale", 0.6, 0, 6));
    
    dir.listDir("zzScenes/zzDonutScene/Donuts");
    for (int i = 0; i < dir.size(); i++){
        cout << dir.getPath(i) << endl;
        ofImage blah;
        images.push_back(blah);
        images.back().load(dir.getPath(i));
    }

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzDonutScene/exampleCode.cpp", false);
    bg.load("zzScenes/zzDonutScene/bgs/Instagram_C_61-15.png");
}

void zzDonutScene::update(){
    
}

void zzDonutScene::draw(){
    
    ofBackground( ofColor::darkCyan);
    //bg.draw(0,0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //ofEnableDepthTest();
    //cam.enableOrtho();
    //cam.begin(dimensions);
    
    ofEnableAlphaBlending();
    ofPushMatrix();
    
    // ofRotateY(ofGetElapsedTimef()*100);
    
     ofTranslate(dimensions.width*0.5, dimensions.height*0.5);
     ofScale(0.9, 0.9);
    for (int i = 0; i < 100; i+=2){
        ofPushMatrix();
        ofTranslate(sin(i*xSpeed+ ofGetElapsedTimef()*2.0)*300.0, sin(i*ySpeed+ ofGetElapsedTimef()*0.9)*300.0);
        
        //ofRotateX(ofGetMouseX());
        ofRotateZ(i*0.1 + ofGetElapsedTimef()*200);
        ofScale(donutScale, donutScale);
        images[(int)(ofGetFrameNum()*0.03 + i * 0.1)%images.size()].draw(0,0, 300,300);
        ofPopMatrix();
    }
    
    ofPopMatrix();
    
    //cam.end();
    ofSetRectMode(OF_RECTMODE_CORNER);
}
