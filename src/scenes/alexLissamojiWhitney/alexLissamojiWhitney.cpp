
#include "alexLissamojiWhitney.h"

void alexLissamojiWhitney::setup(){
  
    ofBackground(0);
    // ofEnableSmoothing();
    center.set(dimensions.width*0.5, dimensions.height*0.5, 0);
    
    // Removing for black-on-white aesthetic
    // bckgImg.loadImage("scenes/alexLissamojiWhitney/back.png");
    
    // To Do: flip through all emojis in the folder ?
//    eyesImg.load("scenes/alexLissamojiWhitney/emojis/1f440.png");
    
    emojiSheet.load("scenes/alexLissamojiWhitney/sheet_32.png");
    
    anim[0] = 0;
    anim[1] = 0;
    

    // setup pramameters
    parameters.add(pAmp.set( "Amplitude", 200, 10, 400 ));
    // parameters.add(pFreq[1].set( "Frequency ", 1, 1, 10 ));
    pPhase.set("Phase", PI / 2 ,0,TWO_PI);
    parameters.add(pDensity.set("Density", 140, 0, 200));
    parameters.add(plissajouRatioX.set("Lissajous Ratio X", 2, 1, 3));
    parameters.add(plissajouRatioY.set("Lissajous Ratio Y", 3, 1, 3));
    pAnimSpeed.set("Animation Speed", 10, 1, 60);
    pImgScale.set("Image scale", 0.15, 0.0, 1);
    
    timerLastTime = ofGetElapsedTimeMillis();

    setAuthor("Alex Tolar");
    setOriginalArtist("John Whitney");
    loadCode("scenes/alexLissamojiWhitney/exampleCode.cpp");
}

void alexLissamojiWhitney::update(){
    
    if(anim[1] > TWO_PI) {
        anim[1] = 0;
    }
    animSpeed[1] = 60 * pAnimSpeed;
    //pPhase.set(( ofGetFrameNum() % animSpeed[1] ) * TWO_PI / animSpeed[1]);
    
//    if( ( ofGetElapsedTimeMillis() - timerLastTime ) > 3000 ){
//        plissajouRatioX.set(ofRandom(1,plissajouRatioX.getMax()));
//        plissajouRatioY.set(ofRandom(1,plissajouRatioY.getMax()));
//        timerLastTime = ofGetElapsedTimeMillis();
//    }
    
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
    ofFill();
    
    float emojiDiff = (float)getFrameNum() / 10;
    float frac = fmod((float)emojiDiff, 1);
//    int frameMod = getFrameNum() % 40;
    for (int i = 0; i < pDensity ; i++) {
        x = pAmp * cos( plissajouRatioX * v * ((float)i - frac) + pPhase);
        y = pAmp * sin( plissajouRatioY * v * ((float)i - frac) + pPhase);
        
        iconWidth = eyesImg.getWidth() * pImgScale;
        iconHeight = eyesImg.getHeight() * pImgScale;
        
        int emoji = (i + (int)emojiDiff) % 870;
        // TBD: use emoji or circles?
        emojiSheet.drawSubsection(x-16, y-16, 32, 32, 32*(emoji/29+1), 32*(emoji%29+1));
        //eyesImg.draw(x-iconWidth/2, y-iconHeight/2, iconWidth, iconHeight);

        // Alternative 2: use circles
        //ofSetColor(i/pDensity * 255);
        //ofDrawCircle(x, y, iconWidth / 4.0);
    }
}


