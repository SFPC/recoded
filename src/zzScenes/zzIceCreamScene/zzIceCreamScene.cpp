
#include "zzIceCreamScene.h"

void zzIceCreamScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzIceCreamScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzIceCreamScene/exampleCode.cpp");
    
    
    for (int i = 0; i < 6; i++){
        string name = "zzScenes/zzIceCreamScene/images/Instagram_Icecream-0" + ofToString(i+1) + ".png";
        ofImage temp;
        iceCreams.push_back(temp);
        iceCreams.back().load(name);
    }
    
    
    int amt = 10;
    for (int i = 0; i < amt; i++){
        iceCreamPoint pt;
        pt.pt =ofPoint(dimensions.width/2, ofMap(i, 0, amt-1, 0-100, dimensions.height));
        pt.index = i % 6;
        
        pts.push_back( pt );
    }
}

void zzIceCreamScene::update(){
    
}

void zzIceCreamScene::draw(){
    
    if (pts.size() != ofGetMouseX()){
        
        pts.clear();
        
        int amt = ofGetMouseX();
        for (int i = 0; i < amt; i++){
            iceCreamPoint pt;
            pt.pt =ofPoint(dimensions.width/2, ofMap(i, 0, amt-1, 0-100, dimensions.height));
            pt.index = i % 6;
            
            pts.push_back( pt );
        }
    }
    
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    for (int i = 0; i < pts.size(); i++){
        pts[i].pt.y += 5;
        if (pts[i].pt.y > (dimensions.height+ 100)){
            pts[i].pt.y = -100;
        }
    }
    
    sort(pts.begin(), pts.end(),
         [](const iceCreamPoint & a, const iceCreamPoint & b) -> bool
    {
        return a.pt.y > b.pt.y;
    });
    
    for (int i = 0; i < pts.size(); i++){
        ofPushMatrix();
        ofTranslate(pts[i].pt + ofPoint(0,200));
        iceCreams[pts[i].index].draw(0,0, sin(pts[i].index * 0.1 + getElapsedTimef()) * ofGetMouseY() + 200,sin(pts[i].index * 0.1 + getElapsedTimef()) * ofGetMouseY() + 200);
        ofPopMatrix();
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
                          
    
}
