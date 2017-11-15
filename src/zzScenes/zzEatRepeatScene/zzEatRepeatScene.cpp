
#include "zzEatRepeatScene.h"

void zzEatRepeatScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzEatRepeatScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    
    //data/zzScenes/zzEatRepeatScene/eat.svg
    
    
    parameters.add(amtRotateZ.set("amtRotateZ", 0,0,1));
    parameters.add(amtRotateY.set("amtRotateY", 0,0,1));
    parameters.add(amtRotateX.set("amtRotateX", 0,0,1));
    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzEatRepeatScene/exampleCode.cpp", false);
    
    
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
    
    timeAdder = 0;
    
}

void zzEatRepeatScene::update(){
    
    timeAdder += ofGetLastFrameTime()*amtRotateZ * 1;
  //  timeAdderY += ofGetLastFrameTime()*amtRotateY * 1;
  //  timeAdderX += ofGetLastFrameTime()*amtRotateX * 1;
    
}

void zzEatRepeatScene::draw(){
    
    ofBackground(255,0,0);
    
    
    shared_ptr<ofxSvgRectangle > rect = svg.get<ofxSvgRectangle>(0);
    ofPoint midPt = ofPoint(720/2, 720/2); //rect->rectangle.getCenter();
    
    
    vector < shared_ptr<ofxSvgGroup > > groups = svg.getElementsForType<ofxSvgGroup>();
    
    //cout << groups.size() << endl;
    ofTranslate(midPt);
    for (int i = 0; i < groups.size(); i++){
        vector < shared_ptr<ofxSvgPath > > paths = groups[i]->getElementsForType<ofxSvgPath>();
        cout <<(timeAdder * 200 *( i % 2 == 0 ? -1 : 1)) << endl;
        ofPushMatrix();
       
        ofRotateX(getElapsedTimef() * (1 + i*0.2) *amtRotateX * 30 );
        ofRotateY(getElapsedTimef() * (1 + i*0.2) *amtRotateY * 30 );
         ofRotateZ( (timeAdder * 200 *( i % 2 == 0 ? -1 : 1)));
        for (int j = 0; j < paths.size(); j++){
            paths[j]->path.draw();
        }
        ofPopMatrix();
    }
}
