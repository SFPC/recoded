#pragma once

#include "ofMain.h"
#include "baseScene.h"

#define MAXNUMOFGROPU 4
#define MAXNUMOFBALL 40

class yosukeJohnWhitneyMatrix : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void reset();
    
    float integratedTime;
    float lastTime;

    
    vector < ofVec3f > points;
    
    float xorigin;
    float yorigin;
    
    float t;
    
    float x[MAXNUMOFGROPU][MAXNUMOFBALL];
    float y[MAXNUMOFGROPU][MAXNUMOFBALL];
    
    //float radius;
    
    float angleofangle[MAXNUMOFGROPU][MAXNUMOFBALL];
    float angle[MAXNUMOFGROPU][MAXNUMOFBALL];

//    ofParameter<float> param;
    ofParameter<int> numOfGroup;
    ofParameter<int> numOfBall;
    ofParameter<float> radius;
    ofParameter<float> speed;
    ofParameter<float> ballRadius;
};
