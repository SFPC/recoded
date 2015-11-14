
#include "robbyRileyScene.h"

#define R_RIL_CNT 20

void robbyRileyScene::setup(){
    param.set("dent", 15, -10, 30);
    parameters.add(param);
    loadCode("robbyRileyScene/code.txt");
}

void robbyRileyScene::update(){
    
}

void robbyRileyScene::draw(){
    
    float space = dimensions.height / R_RIL_CNT;
    float colPos = 0;
    
    int i = 0;
    while (colPos < dimensions.width){
        float colWidth = (.3+powf(atan((i - param)*.25),2)) * space*.5;
        for(int j = 0; j < R_RIL_CNT; j++){
            if((i+j)%2)
                ofSetColor(255, 255, 255);
            else{
                float dist = powf(sinf(PI*(i+j)/40.0), 6);
//                dist += ofNoise(ofGetElapsedTimef());
//                dist *= .5;
                ofSetColor(255*dist, 255*dist, 255*dist);
            }
            ofDrawRectangle(colPos, j  * space, colWidth, space);
        }
        colPos += colWidth;
        i++;
    }
}

