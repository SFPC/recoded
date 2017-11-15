#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    // some system fonts like Helvetica on osx are contained in .dfont files or ttc files
    // these types of files may contain several variations of the font face like regular, bold, italic, etc.
    // OF uses the first instance in the file, which will probably not match the font variation used in the svg file
    // you can place a fonts folder in the same directory as the svg file you are loading.
    // Inside this folder place ttf fonts that should be used instead of the system font.
    // For example, place a Helvetica.ttf file in the fonts folder (make one if there is no fonts folder)
    // if you are using Helvetica in your svg file.
    // This will override the system Helvetica font which is most likely a ttc or dfont.
    // To check the name of the fonts that are being used, open the .svg file in a text editor and check the
    // font-family tags.
    // If you are going to be editing the svg often and using Adobe Illustrator, you might want to save a .ai file
    // and then export the svg because when illustrator saves the svg file and then reloads it, the text can get weird.
    
    ofSetFrameRate( 60 );
    svg.load( "sample.svg" );
    cout << svg.toString();
    ofSetWindowTitle( "openFrameworks Application" );
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    svg.draw();
    ofSetColor( 255, 0, 0 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'r' ) {
        svg.reload();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}