#pragma once

#include "ofMain.h"
#include "baseScene.h"

class Flower {
    
public:
    
    float fade;
    float target = 255;
    float lifespan;
    float lifespanDec;
    float x, y, x1, y1, x2, y2;
    float size;
    ofColor basecolor;
    ofVec2f location;
    float easing;
    float offset, offset1, f;
    
#define CDIRECT 3
    int circleDirect[CDIRECT];
    float speeds[CDIRECT];
    ofColor colors[CDIRECT];
    
    Flower(){};
    ~Flower(){};
    
    void setup(float _size, ofColor _co, float _x, float _y){
        
        size = _size - ofRandom(0, _size/2);
        
        fade = 0;
        lifespan = 255;
        lifespanDec = ofRandom(0.5, 1.0);
        basecolor = _co;
        
        x = _x;
        y = _y;
        
        // Initialize x and y offsets
        x = 0.0;
        y = 0.0;
        x1 = 0.0;
        y1 = 0.0;
        x2 = 0.0;
        y2 = 0.0;
        
        easing = ofRandom(0.05, 0.5);
        
        location = ofVec2f(_x, _y);
        
        offset = ofRandom(0, 1000);
        
        
        int rand[] = {-1, 1};
        
        for(int i=0; i<3; i++){
            
            int randSelector = int(ofRandom(0, 2));
            
            circleDirect[i] = rand[randSelector];
            speeds[i] = ofRandom(0.01, 0.05);
        }
        
    };
    
    void update(){
        
        float time = ofGetElapsedTimeMillis() * 0.0333;
        //float time = getFrameNum();
        
        x = ofMap(sin(time * speeds[0] + offset), -1*circleDirect[0], 1*circleDirect[0], -size, size);
        y = ofMap(cos(time * speeds[0] + offset), -1, 1, -size, size);
        x1 = ofMap(sin(time * speeds[1]), -1*circleDirect[1], 1*circleDirect[1], -size, size);
        y1 = ofMap(cos(time * speeds[1] - 0.2), -1, 1, -size, size);
        x2 = ofMap(sin(time * speeds[2]), -1*circleDirect[2], 1*circleDirect[2], -size, size);
        y2 = ofMap(cos(time * speeds[2] - 0.002), -1, 1, -size, size);
        
        lifespan -= lifespanDec;
        
        float fadeOffset = ofMap(lifespan, 255, 0, 0, 255);
        
        if(fade > 254){
            target = 0;
        }
        
        fade = ofLerp(fade, target, easing);
        fade = fade - fadeOffset;
        
    };
    
    void draw(){
        
        ofPushMatrix();
        ofTranslate(size + location.x, size + location.y);
        ofNoFill();
        ofSetColor(basecolor, fade);
        ofDrawLine(0, 0, x, y);
        ofSetColor(basecolor, fade);
        ofDrawLine(0, 0, x1, y1);
        ofSetColor(basecolor, fade);
        ofDrawLine(0, 0, x2, y2);
        ofPopMatrix();
        
    };
    
    Boolean isDead(){
        if(lifespan<0){
            return true;
        } else {
            return false;
        }
    };
    
};

class mattKnowlton : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void addFlowers();
    void loadPoints();
    void loadColors(ofImage tempImage);
    
    int tileCount;
    int gridSize;
    int numFlowers;
    
    Flower flower;
    vector <Flower> flowers;
    
    vector <ofVec2f> points;
    vector <ofColor> colors;
    
    ofFbo fbo;
    
    ofImage img;
    vector <ofImage> imgs;
    
    ofParameter<float> size;
    ofParameter<int> colorshift;
    ofParameter<int> speed;
};
