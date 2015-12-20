
#include "yeseulCooperMessages.h"

void yeseulCooperMessages::setup(){
    
    setAuthor("Yeseul Song");
    setOriginalArtist("Muriel Cooper");

    texture.load("scenes/yeseulCooperMessages/texture.png");
    
    font.load("Helvetica Neue", 50, true,true,true);
    font.setLineHeight(60);
    
    text1 = "MEANS";
    text2 = "MESSAGES";
    
    parameters.add(greenTextSpeed.set("greenTextSpeed", 20, 5, 35));
    parameters.add(redTextSpeed.set("redTextSpeed", 20, 5, 35));
    parameters.add(purpleTextSpeed.set("purpleTextSpeed", 20, 5, 35));
    parameters.add(rotation.set("rotation", 0, 0, 360));
    
    loadCode("scenes/yeseulCooperMessages/exampleCode.cpp");
    
}


void yeseulCooperMessages::update(){
    
}


void yeseulCooperMessages::draw(){
    
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    // uncomment the following line when the texture is disabled
    // ofBackground(56, 39, 36);
    
    // comment out the following two lines to disable texture on the background
    ofBackground(10, 0, 0);
    texture.draw(0.0, 0.0);
    
    ofRectangle rec1 = font.getStringBoundingBox(text1, 100, 100);
    ofRectangle rec2 = font.getStringBoundingBox(text2, 100, 100);
    
    ofPushMatrix();
    ofTranslate(dimensions.width/2, dimensions.height/2);
    
    tensionEffect(rec1, rec2);
    animateText(rec1, rec2);
    
    ofPopMatrix();
    
    ofDisableBlendMode();
    ofPopStyle();
    
}


void yeseulCooperMessages::tensionEffect(ofRectangle rec1, ofRectangle rec2) {
    
    if (abs((dimensions.width/2+margin-redMove*1.1 - (0-dimensions.width/2-rec1.getWidth()-margin+redMove*1.6))) < rec1.getWidth()) {
        redMove+=redTextSpeed/7;
    }
    else {
        redMove+=redTextSpeed;
    }
    
    if (abs((dimensions.width/2+margin-greenMove) - (0-dimensions.width/2-rec1.getWidth()-margin+greenMove)) < rec1.getWidth()) {
        greenMove+=greenTextSpeed/6;
    }
    else {
        greenMove+=greenTextSpeed;
    }
    
    if (abs((0-dimensions.width/2-margin-rec1.getWidth()+purpleMove*1.7) - (dimensions.width/2+margin-150-purpleMove*1.4)) < rec1.getWidth()) {
        purpleMove+=purpleTextSpeed/6;
    }
    else {
        purpleMove+=purpleTextSpeed;
        
    }
    
    resetPosition();
}


void yeseulCooperMessages::resetPosition() {
    
    if (greenMove > dimensions.width*2.5 && redMove > dimensions.width*2.5 && purpleMove > dimensions.width*2.5){
        greenMove = 0;
        redMove = 0;
        purpleMove = 0;
        
    }
}


void yeseulCooperMessages::animateText(ofRectangle rec1, ofRectangle rec2) {
    
    ofRotate(315+rotation);
    ofSetColor(ofColor::fromHsb(7, 255, 100));
    ofFill();
    for (int n = 0; n < 3; n++) {
        font.drawStringAsShapes(text1, dimensions.width/2+margin-redMove*1.2, -rec1.getHeight());
        font.drawStringAsShapes(text2, dimensions.width/2+margin-redMove*1.1, 0);
        font.drawStringAsShapes(text1, 0-dimensions.width/2-rec1.getWidth()-margin+redMove*1.6, rec1.getHeight());
        font.drawStringAsShapes(text2, 0-dimensions.width/2-rec2.getWidth()-margin-50+redMove*1.4, rec2.getHeight()*2);
    }
    
    ofRotate(90);
    ofSetColor(ofColor::fromHsb(90, 255, 20));
    ofFill();
    for (int n = 0; n < 3; n++) {
        font.drawStringAsShapes(text1, dimensions.width/2+margin-greenMove, -rec1.getHeight());
        font.drawStringAsShapes(text2, dimensions.width/2+margin-greenMove, 0);
        font.drawStringAsShapes(text1, 0-dimensions.width/2-rec1.getWidth()-margin+greenMove, rec1.getHeight());
        font.drawStringAsShapes(text2, 0-dimensions.width/2-rec2.getWidth()-margin+greenMove, rec2.getHeight()*2);
    }
    
    ofRotate(90);
    ofSetColor(ofColor::fromHsb(200, 255, 20));
    ofFill();
    for (int n = 0; n < 3; n++) {
        font.drawStringAsShapes(text1, 0-dimensions.width/2-margin-rec1.getWidth()-150+purpleMove*1.7, rec1.getHeight());
        font.drawStringAsShapes(text2, 0-dimensions.width/2-margin-rec2.getWidth()-150+purpleMove*1.5, rec2.getHeight()*2);
        font.drawStringAsShapes(text1, dimensions.width/2+margin-purpleMove-70, -rec1.getHeight());
        font.drawStringAsShapes(text2, dimensions.width/2+margin-purpleMove*1.4, 0); //
        
    }
}
