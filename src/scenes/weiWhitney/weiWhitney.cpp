#include "weiWhitney.h"

//--------------------------------------------------------------
void weiWhitney::setup(){
    
    ofBackground(0);
    //ofSetFrameRate(60);
    
//    nCurveVertices = 7;
//
//    curveVertices[0].x = 326;
//    curveVertices[0].y = 209;
//    curveVertices[1].x = 306;
//    curveVertices[1].y = 279;
//    curveVertices[2].x = 265;
//    curveVertices[2].y = 331;
//    curveVertices[3].x = 304;
//    curveVertices[3].y = 383;
//    curveVertices[4].x = 374;
//    curveVertices[4].y = 383;
//    curveVertices[5].x = 418;
//    curveVertices[5].y = 309;
//    curveVertices[6].x = 345;
//    curveVertices[6].y = 279;
//
//    for (int i = 0; i < nCurveVertices; i++){
//        curveVertices[i].bOver             = false;
//        curveVertices[i].bBeingDragged     = false;
//        curveVertices[i].radius = 4;
//    }
    
    
    
    setAuthor("HE Wei");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/weiWhitney/exampleCode.cpp");


}

//--------------------------------------------------------------
void weiWhitney::update(){

}

//--------------------------------------------------------------
void weiWhitney::draw(){
    
//    ofFill();
//    ofSetHexColor(0xe0be21);
    
    //------(a)--------------------------------------
    //
    //         draw a star
    //
    //         use poly winding odd, the default rule
    //
    //         info about the winding rules is here:
    //        http://glprogramming.com/red/images/Image128.gif
    //
//    ofSetPolyMode(OF_POLY_WINDING_ODD);    // this is the normal mode
//    ofBeginShape();
//    ofVertex(200,135);
//    ofVertex(15,135);
//    ofVertex(165,25);
//    ofVertex(105,200);
//    ofVertex(50,25);
//    ofEndShape();
    
    
    //------(b)--------------------------------------
    //
    //         draw a star
    //
    //         use poly winding nonzero
    //
    //         info about the winding rules is here:
    //        http://glprogramming.com/red/images/Image128.gif
    //
//  ofSetHexColor(0xb5de10);
//  ofSetPolyMode(OF_POLY_WINDING_NONZERO);
//  ofBeginShape();
//  ofVertex(400,135);
//  ofVertex(215,135);
//  ofVertex(365,25);
//  ofVertex(305,200);
//  ofVertex(250,25);
//  ofEndShape();
    //-------------------------------------
    
    
    
    
    
    //------(c)--------------------------------------
    //
    //         draw a star dynamically
    //
    //         use the mouse position as a pct
    //        to calc nPoints and internal point radius
    //
    
    //use dimensions
    dimensions.width;
    dimensions.height;
    float xPct = (float)(ofGetMouseX()) / (float)(dimensions.width);
    float yPct = (float)(ofGetMouseY()) / (float)(dimensions.height);
    
    float time = ofGetElapsedTimef();
    
    int nTips = 5 + xPct * 60;
    //int nStarPts = nTips * 2;
    int nStarPts = nTips * ofMap(sin(time)/2, -1, 1, 1, 10);
    
    
    //the shape from two verices to grow more
    //float angleChangePerPt = TWO_PI / (float)nStarPts;      //TWO_PI means solid
    float angleChangePerPt = FOUR_PI / (float)nStarPts;   //FOUR_PI meas inside hollow
    float innerRadius = 0 + yPct*30+ofMap(sin(time), -1, 1, -30, 50);
    float outerRadius = 0 + yPct*160+ofMap(sin(time)/2, -1, 1, -100, 300);
    float origx = dimensions.width/2;
    float origy = dimensions.height/2;

    
    float angle = -time*ofMap(sin(time), -1, 1, 0, 1);
    

    
    
    ofSetHexColor(0xa16bca);
    ofBeginShape();
    for (int i = 0; i < nStarPts; i++){
    
        if (i % 2 == 0) {
            // inside point:
            float x = origx + innerRadius * cos(angle);
            float y = origy + innerRadius * sin(angle);
            ofVertex(x,y);
        } else {
            // outside point
            //float x = origx + outerRadius * cos(ofMap(time/50, -1, 1, 0, 500));
            float x = origx + outerRadius * cos(angle);
            float y = origy + outerRadius * sin(angle);
            ofVertex(x,y);
        }
        //angle += angleChangePerPt;
        angle = angle + angleChangePerPt;
    }
    ofEndShape();
    //-------------------------------------
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //------(e)--------------------------------------
    //
    //         use sin cos and time to make some spirally shape
    //
    ofPushMatrix();
    ofTranslate(dimensions.width/3,dimensions.height/3,0);

    //ofSetHexColor(0xff2220);
    ofSetColor(ofMap(sin(time)*5, -1, 1, 0, 255), 0, ofMap(cos(time)*5, -1, 1, 0, 255), 200);
    ofFill();
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    //ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    
    ofBeginShape();
    float angleStep     = TWO_PI/(100.0f + sin(ofGetElapsedTimef()/5.0f) * 600);
    float radiusAdder     = 0.5f;
    float radius         = ofMap(sin(time)*10, -1, 1, 0, 100);
    for (int i = 0; i < 200; i++){
        float anglef = (i) * angleStep;
        float x = radius * cos(anglef);
        float y = radius * sin(anglef);
        ofVertex(x,y);
        radius     += radiusAdder;
    }
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
    //-------------------------------------
    

    
    
    
    
    
    
    
    
    
    
    
    
    


    
    

    

    

        

        
        
  

    
    
}

//--------------------------------------------------------------
void weiWhitney::keyPressed(int key){

}

//--------------------------------------------------------------
void weiWhitney::keyReleased(int key){

}

//--------------------------------------------------------------
void weiWhitney::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void weiWhitney::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void weiWhitney::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void weiWhitney::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void weiWhitney::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void weiWhitney::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void weiWhitney::windowResized(int w, int h){

}

//--------------------------------------------------------------
void weiWhitney::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void weiWhitney::dragEvent(ofDragInfo dragInfo){

}
