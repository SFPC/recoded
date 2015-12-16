#include "cantusFirmusRiley.h"

void cantusFirmusRiley::setup(){
    ofBackground(255);
    size = 5000;
    
    y.c.setHex(0xA79C26);
    y.width = 9;
    
    p.c.setHex(0xC781A8);
    p.width = 9;
    
    b.c.setHex(0x64A2C9);
    b.width = 11;
    
    k.c.setHex(0x222B32);
    k.width = 39;
    
    w.c.setHex(0xE3E2DE);
    w.width = 29;
    
    g.c.set(127);
    g.width = 29;
    
    r.c.set(255,0,0);
    r.width = 10;
    
    int counter = 0;
    
    for (int i = 0; i <= size; i++){
        if(i == size/2) stripes.push_back(w);
        
        else if(abs(i-size/2)% 8 == 1) stripes.push_back(y);
        else if(abs(i-size/2)% 8 == 2) stripes.push_back(p);
        else if(abs(i-size/2)% 8 == 3) stripes.push_back(b);
        
        else if(abs(i-size/2)% 8 == 5) stripes.push_back(b);
        else if(abs(i-size/2)% 8 == 6) stripes.push_back(p);
        else if(abs(i-size/2)% 8 == 7) stripes.push_back(y);
        
        else if(abs(i-size/2)%12 == 0) stripes.push_back(w);
        else if(abs(i-size/2)%12 == 8) stripes.push_back(k);
        
        else if(abs(i-size/2)%12 == 4) {
            int rand = ofRandom(120,180);
            g.c.set(rand);
        //    cout << rand << endl;
            stripes.push_back(g);
        }
        
        else stripes.push_back(r);
    }

    parameters.add(posNoiseSpeed.set("offsetX", 0, -300, 300));
    parameters.add(zoomNoiseSpeed.set("zoom", 0.2, 0.05, 1));
    //parameters.add(range.set("scale", 0.3, 0.02, 1.0));

    setAuthor("Reed Tothong");
    setOriginalArtist("Bridget Riley");
    loadCode("scenes/cantusFirmusRiley/cantusFirmusRiley.cpp");
}

void cantusFirmusRiley::update(){
    
}

void cantusFirmusRiley::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CORNER);
//    posNoise = ofNoise(getElapsedTimef()*posNoiseSpeed);
//    
//    float posX = ofMap(posNoise, 0, 1.0, 0, ofGetWidth()/2);
    ofTranslate(posNoiseSpeed, 0);
    
    
//    zoomNoise = ofNoise(getElapsedTimef()*zoomNoiseSpeed);
//    // cinematic = 0.1 // motion sickness = 10
//    
////    float rangeNoise = ofNoise(getElapsedTimef()*rangeNoiseSpeed);
//    float microScale = ofMap(range, 0, 0.5, 0.015, 1.0, true);
//    float macroScale = ofMap(range, 0.5, 1.0, 1.0, 2.5,true);
//    
//    float maxZoomOut = range < 0.5 ? microScale : macroScale;
//    //     zoom range control
//    float zoom = ofMap(zoomNoise, 0.0, 1.0, .0001, maxZoomOut, true);
    
    
    ofScale(zoomNoiseSpeed, 1);
    
    //midline
    stripes[size/2].x = -stripes[size/2].width/2;
    ofSetColor(stripes[size/2].c);
    ofDrawRectangle(stripes[size/2].x, 0, stripes[size/2].width, dimensions.width*2);
    
    //loop to the left
    for (int i = (size/2)-1; i> 0; i--){
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i+1].x - stripes[i].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, dimensions.height*2);
    }
    
    //loop to the right
    for (int i = (size/2)+1; i< stripes.size();i++) {
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i-1].x + stripes[i-1].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, dimensions.height*2);
    }
    
}
