#include "appConstants.h"
#include "CooperBauhaus.h"

void CooperBauhaus::setup(){
    ofColor cyan(167, 200, 250);
    ofColor magenta(235, 173, 137);
    ofColor yellow(249, 235, 106);
    colors.push_back(cyan);
    colors.push_back(magenta);
    colors.push_back(yellow);
    
    parameters.add(displacement.set("displacement", 10,0,100));
    for (int i = 0; i < 6; i ++) {
        parameters.add(currentDisplacement[i].set("currentDisplacement"+ofToString(i), 0,0,100));
    }
    
    parameters.add(fontSize.set("Font Size", 56, 20, 400));
    parameters.add(speed.set("speed", 0.25, 0, 3));
    
    fontSize.addListener(this, &CooperBauhaus::fontSizeChanged);
    
    font.load("Helvetica Neue", 80, true,true,true);
    
    text = "SCHOOL\nFOR\nPOETIC\nCOMPUTATION";

    loadCode("CooperBauhaus/exampleCode.cpp");
}
//--------------------------------------------------------------
void CooperBauhaus::fontSizeChanged(float &f){
    font.load("Helvetica Neue", fontSize, true,true,true);
}
//--------------------------------------------------------------
void CooperBauhaus::update(){
    for (int i = 0; i < 6; i ++) {
        currentDisplacement[i].set(sin(ofGetElapsedTimef()*speed) * displacement*i);
    }
}
//--------------------------------------------------------------
void CooperBauhaus::draw(){
    
    ofBackground(251, 241, 229);
    //ofSetColor(251, 241, 229);
    //ofDrawRectangle(0, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
    ofPushStyle();
    ofFill();
    ofRectangle r = font.getStringBoundingBox(text, 0,0);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    for (int i = 0; i < 6; i ++) {
        ofSetColor(colors[(int)floor(i/2.0)]);
        font.drawStringAsShapes(text, VISUALS_WIDTH/2 - r.width/2, (VISUALS_HEIGHT - r.height)/2- currentDisplacement[i]);
    }
    ofDisableBlendMode();
    ofPopStyle();
}
