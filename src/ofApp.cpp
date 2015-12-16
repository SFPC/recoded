#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    SM.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    SM.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(40);
    SM.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        SM.advanceScene();
    } else if (key == '.'){
		SM.regressScene();
	}
    
    
    if (key == 'f'){
        ofToggleFullscreen();
    }
    
    
    if (key == 's') {
        SM.screenGrab();
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

    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
