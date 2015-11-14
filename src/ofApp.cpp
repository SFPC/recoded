#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::fixScreenSize(){
    // I am assuming a 2x1 window size for now...
    float width = ofGetWidth();
    float height = width / 2.0;
    ofSetWindowShape(width, height);
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //LET'S GET BIG...
    ofSetWindowShape(ofGetScreenWidth(), ofGetScreenWidth()/2.0);
    fixScreenSize();
    
    SM.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    SM.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    SM.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        SM.advanceScene();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

    
    //float width = w;
    //float height = width / 2.0;
    //ofSetWindowShape(width, height);
    fixScreenSize();
    
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
