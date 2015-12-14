
#include "robbyRileyScene.h"

#define R_RIL_CNT 20

void robbyRileyScene::setup(){
    param.set("dent", 15, 7, 20);
    parameters.add(param);

    setAuthor("Robby Kraft");
    setOriginalArtist("Bridget Riley");
    loadCode("robbyRileyScene/code.txt");
}

void robbyRileyScene::update(){
    
}

void robbyRileyScene::draw(){
    ofFill();
    
    float space = dimensions.height / R_RIL_CNT;
    float colPos = 0;
//    float time1 = (cosf(ofGetElapsedTimeMillis() / 5453.0) * 5) + 15;
    float time2 = cosf(ofGetElapsedTimeMillis() / 5000.0) * .5 + 1.75;
    
//    param.set(time1);

    int i = 0;
    while (colPos < dimensions.width){
        float colWidth = (.3+powf(atan((i - param)*.25),2)) * space*.5;
        for(int j = 0; j < R_RIL_CNT; j++){
            if((i+j)%2)
                ofSetColor(255, 255, 255);
            else{
                float dist = powf(sinf(PI*(i+j)/40.0*time2), 6);
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

