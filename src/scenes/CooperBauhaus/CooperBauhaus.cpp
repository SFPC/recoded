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
    
    font.load("Helvetica Neue", 70, true,true,true);
    
   // text = "SCHOOL\nFOR\nPOETIC\nCOMPUTATION";
    text = "BAUHAUS";

    setAuthor("Roy MacDonald");
    setOriginalArtist("Muriel Cooper");
    loadCode("scenes/CooperBauhaus/exampleCode.cpp");
}
//--------------------------------------------------------------
void CooperBauhaus::update(){}
//--------------------------------------------------------------
void CooperBauhaus::draw(){
    
    ofBackground(251, 241, 229);
    ofPushStyle();
    ofFill();
    ofRectangle r = font.getStringBoundingBox(text, 0,0);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    for (int i = 0; i < 6; i ++) {
        ofSetColor(colors[(int)floor(i/2.0)]);
        font.drawStringAsShapes(text, VISUALS_WIDTH/2 - r.width/2 - 6, VISUALS_HEIGHT - displacement*i - 10);
    }
    ofDisableBlendMode();
    ofPopStyle();
}
