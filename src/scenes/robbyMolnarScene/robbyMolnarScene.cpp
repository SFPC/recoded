//
//  triangleScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "robbyMolnarScene.h"

#define V_PTB 0.4

veraRect::veraRect(){
    setup(50, dimensions.height*.25);
}

void veraRect::setup(int numberOfRectangles, float r){
    numRectangles = numberOfRectangles;
    radius.clear();
    perturb.clear();
    for( int i = 0; i < numRectangles; i++){
        radius.push_back(ofRandom((r)*.5));
        perturb.push_back(ofRandom(-V_PTB, 0));
        perturb.push_back(ofRandom(-V_PTB, 0));
        perturb.push_back(ofRandom(0, V_PTB));
        perturb.push_back(ofRandom(-V_PTB, 0));
        perturb.push_back(ofRandom(0, V_PTB));
        perturb.push_back(ofRandom(0, V_PTB));
        perturb.push_back(ofRandom(-V_PTB, 0));
        perturb.push_back(ofRandom(0, V_PTB));
    }
    for(int i = 0; i < numRectangles; i++){
        for(int j = 0; j < 4; j++){
            an.push_back(ofRandom(-.05, .05));
            an.push_back(ofRandom(-1, 1));
        }
    }
}

void veraRect::draw(int numRects, float d){
    for(int i = 0; i < numRects; i++){
        drawPerturbedRect(centerX - radius[i]*.5, centerY - radius[i]*.5, radius[i], radius[i],
                          d*(perturb[i*8+0] + an[i*8+0]*sinf(an[i*8+1]*ofGetElapsedTimef())), d*(perturb[i*8+1] + an[i*8+0]*cosf(an[i*8+1]*ofGetElapsedTimef())),
                          d*(perturb[i*8+2] + an[i*8+2]*sinf(an[i*8+3]*ofGetElapsedTimef())), d*(perturb[i*8+3] + an[i*8+2]*cosf(an[i*8+3]*ofGetElapsedTimef())),
                          d*(perturb[i*8+4] + an[i*8+4]*sinf(an[i*8+5]*ofGetElapsedTimef())), d*(perturb[i*8+5] + an[i*8+4]*cosf(an[i*8+5]*ofGetElapsedTimef())),
                          d*(perturb[i*8+6] + an[i*8+6]*sinf(an[i*8+7]*ofGetElapsedTimef())), d*(perturb[i*8+7] + an[i*8+6]*cosf(an[i*8+7]*ofGetElapsedTimef())));
    }
}

// almost your standard rectangle drawing function: (x, y, width, height)
// but contains 2 extra arguments which specify the percent of the width/height that
// the x and y locations of each of the 4 corners gets distorted
void veraRect::drawPerturbedRect(float x, float y, float width, float height,
                                 float X_PERTURB_TL, float Y_PERTURB_TL,
                                 float X_PERTURB_TR, float Y_PERTURB_TR,
                                 float X_PERTURB_BR, float Y_PERTURB_BR,
                                 float X_PERTURB_BL, float Y_PERTURB_BL){
    
    float topLeftX = (x + (width*X_PERTURB_TL) - (width*X_PERTURB_TL*.5));
    float topLeftY = (y + (height*Y_PERTURB_TL) - (height*Y_PERTURB_TL*.5));
    float topRightX = (x + width + (width*X_PERTURB_TR) - (width*X_PERTURB_TR*.5));
    float topRightY = (y + (height*Y_PERTURB_TR) - (height*Y_PERTURB_TR*.5));
    float bottomRightX = (x + width + (width*X_PERTURB_BR) - (width*X_PERTURB_BR*.5));
    float bottomRightY = (y + height + (height*Y_PERTURB_BR) - (height*Y_PERTURB_BR*.5));
    float bottomLeftX = (x + (width*X_PERTURB_BL) - (width*X_PERTURB_BL*.5));
    float bottomLeftY = (y + height + (height*Y_PERTURB_BL) - (height*Y_PERTURB_BL*.5));
    
    ofDrawLine(topLeftX, topLeftY, topRightX, topRightY);
    ofDrawLine(topRightX, topRightY, bottomRightX, bottomRightY);
    ofDrawLine(bottomRightX, bottomRightY, bottomLeftX, bottomLeftY);
    ofDrawLine(bottomLeftX, bottomLeftY, topLeftX, topLeftY);
}



void robbyMolnarScene::setup(){
    ofSetLineWidth(1);
    ofSetColor(255, 255, 255, 255);
    numRectangles.set("numRectangles", 30, 0, 50);
    disarray.set("disarray", .5, 0.0, 1.0);
    parameters.add(numRectangles);
    parameters.add(disarray);
    loadCode("robbyMolnarScene/code.txt");
    float centerX = dimensions.width*.5;
    float centerY = dimensions.height*.5;
    printf("%f, %f", dimensions.width, dimensions.height);
    vRect.setup(50, dimensions.height);
    vRect.centerX = centerX;
    vRect.centerY = centerY;
    float space = centerY / 4.0;
    for(int i = 0; i < 36; i++){
        veraRect v;
        v.setup(50, dimensions.height*.25);
        v.centerX = space*.5 + centerX - space*3 + space*(i%6);
        v.centerY = space*.5 + centerY - space*3 + space*((int)(i/6));
        veraRects.push_back(v);
    }
}
void robbyMolnarScene::update(){
    
}

void robbyMolnarScene::draw(){

//    vRect.draw(numRectangles, disarray);

    for(int i = 0; i < 36; i++){
        veraRects[i].draw(numRectangles, disarray);
    }

//    string codeReplaced = getCodeWithParamsReplaced();
//    ofDrawBitmapString(codeReplaced, 40,40);
}

