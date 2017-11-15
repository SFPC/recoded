
#include "zzEatRepeatScene.h"

void zzEatRepeatScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzEatRepeatScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    
    //data/zzScenes/zzEatRepeatScene/eat.svg
    
    
    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzEatRepeatScene/exampleCode.cpp");
    
    
    svg.load( "zzScenes/zzEatRepeatScene/eat.svg" );
    cout << svg.toString();
    

    shared_ptr<ofxSvgRectangle > rect = svg.get<ofxSvgRectangle>(0);
    ofPoint midPt = rect->rectangle.getCenter();
    
    
    vector < shared_ptr<ofxSvgGroup > > groups = svg.getElementsForType<ofxSvgGroup>();
    
    for (int i = 0; i < groups.size(); i++){
        vector < shared_ptr<ofxSvgPath > > paths = groups[i]->getElementsForType<ofxSvgPath>();
        for (int j = 0; j < paths.size(); j++){
            paths[j]->path.translate(-midPt);
        }
    }
    
}

void zzEatRepeatScene::update(){
    
}

void zzEatRepeatScene::draw(){
    
    ofBackground(255,0,0);
    
    
    shared_ptr<ofxSvgRectangle > rect = svg.get<ofxSvgRectangle>(0);
    ofPoint midPt = rect->rectangle.getCenter();
    
    
    vector < shared_ptr<ofxSvgGroup > > groups = svg.getElementsForType<ofxSvgGroup>();
    
    //cout << groups.size() << endl;
    ofTranslate(midPt);
    for (int i = 0; i < groups.size(); i++){
        vector < shared_ptr<ofxSvgPath > > paths = groups[i]->getElementsForType<ofxSvgPath>();
        ofRotateZ(ofGetElapsedTimef() * (1 + i*0.1));
        ofRotateX(ofGetElapsedTimef() * (1 + i*0.1));
        for (int j = 0; j < paths.size(); j++){
            paths[j]->path.draw();
        }
    }
}
