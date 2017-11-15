#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate( 60 );
    svg.load( "sample.svg" );
    cout << svg.toString();
    
    vector< shared_ptr<ofxSvgImage> > trees = svg.getElementsForType< ofxSvgImage>("trees");
    for( int i = 0; i < trees.size(); i++ ) {
        trees[i]->img.setAnchorPercent( 0.5, 1.f );
        trees[i]->pos.x += trees[i]->getWidthScaled();
        trees[i]->pos.y += trees[i]->getHeightScaled();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor tcolor( 101,163,253 );
    tcolor.setHue( tcolor.getHue() + (sin(ofGetElapsedTimef()*0.5)) * 50 );
    
    shared_ptr<ofxSvgGroup> logoGroup = svg.get< ofxSvgGroup>("logo");
    if( logoGroup ) {
        for( int i = 0; i < logoGroup->getElements().size(); i++ ) {
            shared_ptr< ofxSvgElement > te = dynamic_pointer_cast< ofxSvgElement >( logoGroup->getElements()[i] );
            te->path.setFillColor( tcolor );
        }
    }
    
    vector< shared_ptr<ofxSvgImage> > trees = svg.getElementsForType< ofxSvgImage>("trees");
    float mouseX = ofGetMouseX();
    
    for( int i = 0; i < trees.size(); i++ ) {
        float dist = fabs( trees[i]->pos.x - mouseX );
        float tscale = ofMap( dist, 50, 500, 1.0, 0.4, true );
        trees[i]->scale.set( tscale, tscale );
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    svg.draw();
    
    // draw an O circling around the O in OF //
    shared_ptr< ofxSvgCircle > of_circle = svg.get<ofxSvgCircle>("logo:ofO");
    if( of_circle ) {
        float maxRadius = of_circle->getRadius() * 0.95;
        float tangle = ofGetElapsedTimef() * 1.2;
        float tradius = ofMap( sin( tangle ), -1.f, 1.f, of_circle->getRadius() * 0.25, of_circle->getRadius() * 0.05, true );
        ofVec2f tpos;
        tpos.x = cos( tangle ) * (maxRadius-tradius);
        tpos.y = sin( tangle ) * (maxRadius-tradius);
        
        ofSetColor( 255, 150 );
        ofDrawCircle( tpos + of_circle->pos, tradius );
    }
    
    shared_ptr< ofxSvgRectangle > of_rect = svg.get< ofxSvgRectangle >("logo:ofF");
    if( of_rect ) {
        float tangle = ofGetElapsedTimef() * 1.6;
        float th = ofMap(sin( tangle ), -0.8, 1, 0, 20, true );
        float ty = ofMap(sin( tangle ), -1, 1, of_rect->pos.y, of_rect->pos.y+of_rect->getHeightScaled()-th, true );
        ofDrawRectangle(of_rect->pos.x, ty, of_rect->getWidthScaled(), th );
    }
    
    // draw the trees again so the circle drawn above appears behind them //
    svg.get<ofxSvgGroup>("trees")->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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