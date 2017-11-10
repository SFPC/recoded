
#include "hyojinVeraMolnar.h"

void hyojinVeraMolnar::setup(){
  
    hue.set("hue", 0, 0, 255);
    saturation.set("saturation", 255, 0, 255);
    random.set("random", 10, 2, 15);
    parameters.add(hue);
    parameters.add(saturation);
    parameters.add(random);
    
    setAuthor("Hyojin Yoo");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/hyojinVeraMolnar/exampleCode.cpp");
    
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofColor brightRed(157,32,62);
    ofColor darkRed(180,200,204);

}

void hyojinVeraMolnar::update(){
    
//    for(int i = 0; i < 5; i++){
//        for(int j = 0; j < 5; j++){
//            if(i == 1 && j ==0){
//                brightRed.setHue(hue);
//                brightRed.setSaturation(saturation);
//                ofSetColor(brightRed);
//            }else if(i == 2 && j ==0){
//                brightRed.setHue(hue);
//                brightRed.setSaturation(saturation);
//                ofSetColor(brightRed);
//            }else if(i == 0 && j ==2){
//                brightRed.setHue(hue);
//                brightRed.setSaturation(saturation);
//                ofSetColor(brightRed);
//            }else if(i == 0 && j ==4){
//                brightRed.setHue(hue);
//                brightRed.setSaturation(saturation);
//                ofSetColor(brightRed);
//            }else if(i == 4 && j ==4){
//                brightRed.setHue(hue);
//                brightRed.setSaturation(saturation);
//                ofSetColor(brightRed);
//            }else{
//                darkRed.setHue(hue);
//                darkRed.setSaturation(saturation);
//                ofSetColor(darkRed);
//            }
//            randomness = ofRandom(-random*2,random*2);
//            ofRectangle myRect(i*recW+gap*i+gutter+randomness * sin(i*0.01 + time),j*recH+gap*j+gutter+randomness * sin(i*0.01 + time),recW,recH);
//            ofDrawRectangle(myRect);
//        }
    
}

void hyojinVeraMolnar::draw(){
    
    ofColor brightRed(157,32,62);
    ofColor darkRed(180,200,204);
    
    ofSetColor(255);
    ofDrawRectangle(0,0,width,height);
    
    ofSeedRandom(100);
    float time = ofGetElapsedTimef();
    int randomness;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 1 && j ==0){
                brightRed.setHue(hue);
                brightRed.setSaturation(saturation);
                ofSetColor(brightRed);
            }else if(i == 2 && j ==0){
                brightRed.setHue(hue);
                brightRed.setSaturation(saturation);
                ofSetColor(brightRed);
            }else if(i == 0 && j ==2){
                brightRed.setHue(hue);
                brightRed.setSaturation(saturation);
                ofSetColor(brightRed);
            }else if(i == 0 && j ==4){
                brightRed.setHue(hue);
                brightRed.setSaturation(saturation);
                ofSetColor(brightRed);
            }else if(i == 4 && j ==4){
                brightRed.setHue(hue);
                brightRed.setSaturation(saturation);
                ofSetColor(brightRed);
            }else{
                darkRed.setHue(hue);
                darkRed.setSaturation(saturation);
                ofSetColor(darkRed);
            }
            randomness = ofRandom(-random*2,random*2);
            ofRectangle myRect(i*recW+gap*i+gutter+randomness * sin(i*0.01 + time),j*recH+gap*j+gutter+randomness * sin(i*0.01 + time),recW,recH);
            ofDrawRectangle(myRect);
            
        }
    }

}
