
#include "robbyRileyScene.h"

#define R_RIL_CNT 20

void robbyRileyScene::setup(){
    dent.set("dent", 0, -R_RIL_CNT * 0.5, R_RIL_CNT * 1.5);
    parameters.add(dent);
    time.set("time", 0, 0, 40.0*PI);
    parameters.add(time);
    scale.set("scale", 1, 0.5, 2);
    parameters.add(scale);

    setAuthor("Robby Kraft");
    setOriginalArtist("Bridget Riley");
    loadCode("scenes/robbyRileyScene/code.txt");
}

void robbyRileyScene::update(){
    
}

void robbyRileyScene::draw(){
    ofFill();
    
    float space = dimensions.height / R_RIL_CNT * scale;
    float colPos = 0;
//    float time1 = (cosf(ofGetElapsedTimeMillis() / 5453.0) * 5) + 15;
    float time2 = cosf(time) * .5 + 1.75;
    
//    param.set(time1);

    int i = 0;
    while (colPos < dimensions.width){
        float colWidth = (.3+powf(atan((i - dent)*.25),2)) * space*.5;
        for(int j = 0; j < 3*R_RIL_CNT; j++){
            if((i+j)%2)
                ofSetColor(255, 255, 255);
            else{
                float dist = powf(sinf(PI*(i+j+10+time)/40.0), 6);
//                dist += ofNoise(ofGetElapsedTimef());
//                dist *= .5;
//                dist = time1;
                
                ofSetColor(ofFloatColor(dist, dist, dist, 1.0));
            }
            ofDrawRectangle(colPos, j  * space, colWidth, space);
        }
        colPos += colWidth;
        i++;
    }
}

