#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    SM.setup();
    
  //ofSetWindowPosition(2000, 0);
    ofSetFullscreen(true);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    SM.update();
    
   // cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofPushMatrix();
    
   
    
    // if draw two up:
   
    
#ifdef DRAW_TWO_UP

//  ofLine(0,0,520,520);
//  ofLine(520,0, 520+520,520);

  SM.draw();
  ofPushMatrix();
  ofTranslate(520,0);
  SM.codeFbo.draw(0, 0, 520,520);
  ofPopMatrix();
    
//    ofPushMatrix();
//        float h = 504 * 1920.0/(float)(504+504);
//        ofTranslate(0,(1080-h)*0.5);
//        ofScale(1920.0/(float)(504+504), 1920.0/(float)(504+504));
//        SM.draw();
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    
//    ofTranslate(h, 0);
//    SM.codeFbo.draw(0, 0, 504*2, 504*2);
//        //SM.drawType();
//    ofPopMatrix();


#elif defined DRAW_ONE_BIG
    float scale = 1080.0/(float)(504);
    float w = scale * 504;
    ofTranslate((1920-w)*0.5, 0);
    ofScale(scale, scale);
    SM.draw();
#else
    SM.draw();
#endif
    

    
    ofPopMatrix();
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
    
    if (key == 'c') {
        ofHideCursor();
    }
    if (key == 'C') {
        ofShowCursor();
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
