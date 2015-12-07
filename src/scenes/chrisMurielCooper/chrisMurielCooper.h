#pragma once

#include "ofMain.h"
#include "baseScene.h"

class spaceText {
public:
    vector<string> text;
    ofVec3f pos, rotAxis, vel;
    float rotAmt;
    ofColor planeColor;
    
    ofParameter<float> *textOpacity;
    ofParameter<float> *planeOpacity;
    
    void drawLeftPlane();
    void drawText(const ofTrueTypeFont& ttf);
    void drawRightPlane();
};

class chrisMurielCooper : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();

    spaceText text1, text2;
    
    ofEasyCam cam;
    ofTrueTypeFont ttf;
    
    ofParameter<float> cameraRotationX;
    ofParameter<float> cameraRotationY;
    ofParameter<float> cameraRotationZ;
    ofParameter<float> cameraZoom;
    
    ofParameter<float> text1Opacity;
    ofParameter<float> text2Opacity;
    ofParameter<float> text1PlaneOpacity;
    ofParameter<float> text2PlaneOpacity;
};