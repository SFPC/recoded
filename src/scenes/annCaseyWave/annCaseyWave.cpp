#include "annCaseyWave.h"

//--------------------------------------------------------------
void annCaseyWave::setup(){
    // create two fbos for color and type
    color_fbo.allocate(dimensions.width, dimensions.height, GL_RGBA, 4);
    text_fbo.allocate(dimensions.width, dimensions.height, GL_RGBA, 4);
    
    img.load("scenes/annCaseyWave/casey.jpg");
    
    // set parameters
    parameters.add(radius.set("radius", 150, 0, 200));
    parameters.add(partyMode.set("party mode",0,0,1));
    parameters.add(posX.set("positionX",0,-dimensions.width, dimensions.width));
    parameters.add(posY.set("positionY",0, -dimensions.height, dimensions.height));
    
    
    setAuthor("ann tbd");
    setOriginalArtist("Jacqueline Casey");
    loadCode("scenes/annCaseyWave/exampleCode.cpp");}

//--------------------------------------------------------------
void annCaseyWave::update(){
    
}

//--------------------------------------------------------------
void annCaseyWave::draw(){
    text_fbo.getTexture().setAlphaMask(color_fbo.getTexture());
	
    float time = ofGetElapsedTimef();
    int xAmp = 50;
    ofFill();
    color_fbo.begin();
	ofClear(255);

	
    ofSetCircleResolution(100);
    int partyStart = 0;
    if (partyMode > 0) {
        partyStart = 127;
    }
    
    for (int i = 0; i < 700; i++){
        ofSetColor( 255 - abs( 255*sin(partyMode*i * 0.1)),
                   partyStart + partyStart * sin(partyMode*i * 0.11),
                   partyStart + partyStart * sin(partyMode*i * 0.12));
        ofDrawCircle(posX + i*2, posY + xAmp * sin(i*0.03 + time*1.4), radius);
        
    }
    color_fbo.end();
    
    // set the alpha layer as text
    text_fbo.begin();
    ofClear(0,0,0,255);
    
    img.draw((dimensions.width - img.getWidth())/2., (dimensions.height - img.getHeight())/2.);
    text_fbo.end();
	
	
	ofBackground(255);
    color_fbo.draw(0,0);
	text_fbo.draw(0,0);
	
}
