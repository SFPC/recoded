#include "weiWhitney.h"

//--------------------------------------------------------------
void weiWhitney::setup(){
    
    parameters.add(speed.set("Speed", 1,0,10));
    parameters.add(scale.set("Scale", 1,0,1));
    parameters.add(nTips.set("Num Tips", 10, 5, 60));
    parameters.add(radiusAdder.set("Radius Adder", 0.5,0,10));
	
    setAuthor("HE Wei");
    setOriginalArtist("John Whitney");    
    loadCode("scenes/weiWhitney/exampleCode.cpp");
}

//--------------------------------------------------------------
void weiWhitney::update(){

}

//--------------------------------------------------------------
void weiWhitney::draw(){
	
    //use dimensions
    
    float time = ofGetElapsedTimef() * speed;
    

    //int nStarPts = nTips * 2;
    int nStarPts = nTips * ofMap(sin(time)/2, -1, 1, 1, 10);
    
    
    //the shape from two verices to grow more
    //float angleChangePerPt = TWO_PI / (float)nStarPts;      //TWO_PI means solid
    float angleChangePerPt = FOUR_PI / (float)nStarPts;   //FOUR_PI meas inside hollow
    float innerRadius =  scale *30+ofMap(sin(time), -1, 1, -30, 50);
    float outerRadius =  scale *160+ofMap(sin(time)/2, -1, 1, -100, 300);
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

    ofPushMatrix();
    ofTranslate(dimensions.width/3,dimensions.height/3,0);

    //ofSetHexColor(0xff2220);
    ofSetColor(ofMap(sin(time)*5, -1, 1, 0, 255), 0, ofMap(cos(time)*5, -1, 1, 0, 255), 200);
    ofFill();
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    //ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    
    ofBeginShape();
    float angleStep     = TWO_PI/(100.0f + sin(time/5.0f) * 600);
//    float radiusAdder     = 0.5f;
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
