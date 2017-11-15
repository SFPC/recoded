
#include "zzBaconScene.h"

void zzBaconScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzBaconScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    bacon.setup();
    
    
    //animation
    startTime = ofGetElapsedTimef();
    duration = 10;
    parameters.add(sineAmp.set("sineAmp", 15, -30, 30));
    
    setAuthor("Peter Pan");
    setOriginalArtist("Put the original Artist's name here");
    
    loadCode("zzScenes/zzBacons/exampleCode.cpp", false);

}

void zzBaconScene::update(){
    bacon.update();
    
    // animation
    elapsedTime = ofGetElapsedTimef() - startTime;
    pct = elapsedTime / duration;
    
    if (pct > 1) {
        startTime = ofGetElapsedTimef();
        pct = 0;}
    
    posA = 0;
    posB = 3 * (bacon.width + bacon.height);
    pos = (1-pct) * posA + pct * posB;
}

void zzBaconScene::draw(){
    ofSetColor(255, 100, 0);
    ofDrawRectangle(dimensions);
    
    
    //    float sineAmp = ofMap(mouseY, 0, ofGetHeight(), 0, 20);
    
    ofRotateZ(-45);
    ofTranslate(- 6 * (bacon.width + bacon.height),0);
    
    for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 6; j ++){
            float offset = 0;
            float move;
            if(j % 2 == 1) offset = bacon.width/2;
            
            ofPushMatrix();
            ofTranslate(i * (bacon.width + bacon.height) + offset + pos,
                        j * (bacon.height * 2) + 7 * sin(ofGetElapsedTimef()+ i*0.1));
            bacon.draw(sineAmp);
            ofPopMatrix();
        }
    }
}


//---------------------------------------------------------------
void Bacon::setup(){
    
    width = 300;
    height = 84;
    
}


//---------------------------------------------------------------
void Bacon::update(){
    
    
}


//---------------------------------------------------------------
void Bacon::draw(float amp){
    
    ofPolyline line;
    for (int i = 0; i < 100; i++){
        
        float y = 0 - (height/2) + amp * sin(ofGetElapsedTimef() * 6 + i * 0.1);
        float x = ofMap(i, 0, 99, 0 - (width/2), 0 + (width/2));
        line.addVertex(x, y);
    }
    
    for(int i = 0; i < 5; i ++){
        ofColor c;
        if (i % 2 == 0) c = ofColor(100,25,13);
        else c = ofColor(255,200,200);
        
        ofMesh m;
        m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        for (int j = 0; j < line.size(); j++){
            ofPoint p = line.getPointAtIndexInterpolated(j);
            m.addVertex(ofPoint(p.x, p.y + i * (height/5)));
            m.addColor(c);
            m.addVertex(ofPoint(p.x, p.y + i * (height/5) + height/5));
            m.addColor(c);
        }
        m.draw();
    }
    
}
