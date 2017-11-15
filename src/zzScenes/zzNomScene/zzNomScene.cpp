
#include "zzNomScene.h"

void zzNomScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzNomScene.h
    parameters.add(wavyAmt.set("wavyAmt", 0, 0, 1000));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzNomScene/exampleCode.cpp", false);
    
    
    svg.load( "zzScenes/zzNomScene/nom.svg" );
    
    shared_ptr<ofxSvgGroup> group     = svg.get<ofxSvgGroup>(0);
    shared_ptr<ofxSvgGroup> subGroup  = group->get<ofxSvgGroup>(0);
    vector< shared_ptr<ofxSvgPath> > svgPaths = subGroup->getElementsForType< ofxSvgPath>();
    cout << svgPaths.size() << endl;
    
    for (int i = 0; i < svgPaths.size(); i++){
        paths.push_back(svgPaths[i]->path);
    }
}

void zzNomScene::update(){
    
}

void zzNomScene::draw(){
    
    ofBackground(255, 0, 0);
    ofPushMatrix();
    ofScale(0.7, 0.7);
    
    ofEnableAlphaBlending();
    for (int h = 0; h < 7; h++) {
        ofPushMatrix();
        ofTranslate(0, 20*h - 3.5*20-20);
        
        for (int i = 0; i < paths.size(); i++) {
            vector < ofPolyline > lines = paths[i].getOutline();
            for (int j = 0; j < lines.size(); j++) {
                lines[j] = lines[j].getResampledBySpacing(3);
            }
            
            
            for (int j = 0; j < lines.size(); j++) {
                for (int k = 0; k < lines[j].size(); k++) {
                    //lines[j][k].x += ofRandom(-20, 20);
                    //lines[j][k].y += ofRandom(-20, 20);
                    float y = lines[j][k].x + lines[j][k].y * 0.1;
                    
                    
                    lines[j][k].y += ofSignedNoise(y*(0.001) + ofGetElapsedTimef(), h*0.2) * wavyAmt;  //= mat * lines[i][j];
                }
            }
            
            ofBeginShape();
            for (int j = 0; j < lines.size(); j++) {
                if (j != 0) ofNextContour();
                for (int k = 0; k < lines[j].size(); k++) {
                    ofSetColor(255, 255, 0, ofMap(h, 0, 6, 20, 80));
                    ofVertex(lines[j][k]);
                }
            }
            ofEndShape();
        }
        ofPopMatrix();
        
    }
    ofPopMatrix();
}
