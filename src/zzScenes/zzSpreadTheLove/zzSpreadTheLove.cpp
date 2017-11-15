
#include "zzSpreadTheLove.h"

void zzSpreadTheLove::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzSpreadTheLove.h
    parameters.add(spreadRotation.set("spreadRotation", 0, 0, 1000));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzSpreadTheLove/exampleCode.cpp", false);

    svg.load( "zzScenes/zzSpreadTheLove/test.svg" );
    
    
    shared_ptr<ofxSvgRectangle> rect     = svg.get<ofxSvgGroup>(0)->get<ofxSvgRectangle>(0);
    c = rect->getFillColor();
    midPt = rect->rectangle.getCenter();
    
    shared_ptr<ofxSvgPath> pathA     = svg.get<ofxSvgGroup>(1)->get<ofxSvgPath>(0);
    shared_ptr<ofxSvgPath> pathB     = svg.get<ofxSvgGroup>(2)->get<ofxSvgGroup>(0)->get<ofxSvgPath>(0);
    shared_ptr<ofxSvgPath> pathC     = svg.get<ofxSvgGroup>(3)->get<ofxSvgGroup>(0)->get<ofxSvgGroup>(0)->get<ofxSvgPath>(0);
    shared_ptr<ofxSvgPath> pathD     = svg.get<ofxSvgGroup>(3)->get<ofxSvgGroup>(0)->get<ofxSvgGroup>(0)->get<ofxSvgPath>(1);
    
    shared_ptr<ofxSvgPath> pathE     = svg.get<ofxSvgGroup>(3)->get<ofxSvgGroup>(0)->get<ofxSvgPath>(0);
    shared_ptr<ofxSvgPath> pathF     = svg.get<ofxSvgGroup>(3)->get<ofxSvgGroup>(0)->get<ofxSvgPath>(1);
    
    paths.push_back(pathA->path);
    paths.push_back(pathB->path);
    paths.push_back(pathC->path);
    paths.push_back(pathD->path);
    paths.push_back(pathF->path);
    
    for (int i = 0; i < paths.size(); i++){
        paths[i].translate(-midPt);
    }

}

void zzSpreadTheLove::update(){
    
}

void zzSpreadTheLove::draw(){
    
    ofBackground(c);
    
    //ofTranslate(midPt);
    
    ofTranslate(720/2, 720/2);
    ofScale(0.7, 0.7);
    //
    //
    //
    //    for (int i = 0; i < paths.size(); i++){
    //
    //        ofPushMatrix();
    //        ofTranslate( 0, 0.1*ofGetMouseY() * ofSignedNoise(i*0.1, ofGetMouseX()*0.003));
    //        ofRotateY(ofGetMouseY() * (i*0.1 + 1));
    //
    //        paths[i].draw();
    //        ofPopMatrix();
    //
    //    }
    
    for (int i = 0; i < paths.size(); i++){
        ofPushMatrix();
        ofRotateY(spreadRotation * (i*0.1 + 1));
        paths[i].draw();
        
        vector < ofPolyline > lines = paths[i].getOutline();
        
        for (int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(2);
            for (int k = 0; k < 400; k++){
                float pct = fmod(ofGetElapsedTimef()*0.02  + ofMap(k,0, 400, 0, 1), 1);
                ofPoint pt = line.getPointAtPercent(pct);
                ofCircle(pt, 2);
            }
        }
        
        ofPopMatrix();
        
        
    }
    
}
