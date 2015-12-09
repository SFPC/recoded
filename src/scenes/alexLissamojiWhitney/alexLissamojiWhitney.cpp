
#include "alexLissamojiWhitney.h"

void alexLissamojiWhitney::setup(){
  
    ofBackground(0);
    // ofEnableSmoothing();
    center.set(ofGetWidth()*0.25f, ofGetHeight()*0.5f, 0);
    
    bckgImg.loadImage("alexLissamojiWhitney/back.png");
    
    // To Do: flip through all emojis in the folder ?
    eyesImg.loadImage("alexLissamojiWhitney/emojis/1f440.png");
    
    anim[0] = 0;
    anim[1] = 0;
    

    // setup pramameters
    parameters.add(pAmp.set( "Amplitude", 200, 10, 400 ));
    // parameters.add(pFreq[1].set( "Frequency ", 1, 1, 10 ));
    parameters.add(pPhase.set("Phase", 0,0,TWO_PI));
    parameters.add(pDensity.set("Density", 140, 0, 200));
    parameters.add(pAnimSpeed.set("Animation Speed", 10, 1, 60));
    parameters.add(plissajouRatioX.set("Lissajous Ratio X", 2, 1, 8));
    parameters.add(plissajouRatioY.set("Lissajous Ratio Y", 3, 1, 8));
    parameters.add(pImgScale.set("Image scale", 0.15, 0.1, 1));

    loadCode("alexLissamojiWhitney/exampleCode.cpp");
    
    timerLastTime = ofGetElapsedTimeMillis();

}

void alexLissamojiWhitney::update(){
    
    if(anim[1] > TWO_PI) {
        anim[1] = 0;
    }
    animSpeed[1] = 60 * pAnimSpeed;
    pPhase.set(( ofGetFrameNum() % animSpeed[1] ) * TWO_PI / animSpeed[1]);
    
    if( ( ofGetElapsedTimeMillis() - timerLastTime ) > 3000 ){
        plissajouRatioX.set(ofRandom(1,plissajouRatioX.getMax()));
        plissajouRatioY.set(ofRandom(1,plissajouRatioY.getMax()));
        timerLastTime = ofGetElapsedTimeMillis();
    }
    
}

void alexLissamojiWhitney::draw(){
    
    bckgImg.draw(0, 0);
    
    ofPushMatrix();
        ofTranslate(center);
        ofSetColor(255);
        ofSetLineWidth(1);
        drawLissaous();
    ofPopMatrix();
    
}

void alexLissamojiWhitney::drawLissaous() {
    
    double y,x;
    float v,iconHeight,iconWidth;
    v = TWO_PI / pDensity;
    
    for (int i = 0; i < this->pDensity ; i++) {
        x = pAmp * cos( this->plissajouRatioX * v * i + pPhase);
        y = pAmp * sin( this->plissajouRatioY * v * i + pPhase);
        
        iconWidth = eyesImg.getWidth() * pImgScale;
        iconHeight = eyesImg.getHeight() * pImgScale;
        
        eyesImg.draw(x-iconWidth/2, y-iconHeight/2, iconWidth, iconHeight);
    }
}


