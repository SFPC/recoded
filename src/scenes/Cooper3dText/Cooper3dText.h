#pragma once

#include "ofMain.h"
#include "baseScene.h"


#include "ofMain.h"
#include "ofxTween.h"
#include "ofxGui.h"

class textSurface: public ofNode{
public:
    string text;
    ofColor color;
    ofColor offColor;
    
    ofTrueTypeFont* font;
    ofRectangle r;
    
    float transition;
    
    ofTexture tex;//, texOff;
    ofVec3f axis;
    int sign;
    ofVec3f moveVector;
    float rotationFactor;
    bool bIsMain;
    textSurface(){
        font = NULL;
        offColor.set(130, 200);
        transition = 0;
        bIsMain = false;
    }
    
    void setTextAndFont(string text,  ofTrueTypeFont& font, ofColor color){
        this->color = color;
        this->text = text;
        this->font = &font;
        r = font.getStringBoundingBox(text, 0, 0);

        ofFbo fbo;
        fbo.allocate(r.width, r.height);
        fbo.begin();
        ofClear(255,0);
        ofSetColor(color);
        font.drawStringAsShapes(text, 0, -r.y);
        fbo.end();
        tex = fbo.getTexture();

    }
    void setIsMain(bool bMain = true){
        bIsMain = bMain;
    }
    void customDraw(){
        ofPushStyle();

        if(bIsMain){
            ofSetColor(color.r, color.g, color.b, ofMap(transition, 0, 1, 0.5, 1)*255);
            font->drawStringAsShapes(text, 0, r.y);
        }else{
            ofSetColor(255, ofMap(transition, 0, 1, 0.5, 1)*255);
            tex.draw(0,-r.height);
        }
        ofPopStyle();
    }
};

class Cooper3dText : public baseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    vector<textSurface> surfaces;
    
    ofTrueTypeFont font;
    
    void reset();
    
    ofCamera cam;
    int currentSurface, prevSurface;
    
    ofxTween tween;
    ofxEasingExpo easing;
    
    void updateCameraTween();
    
    void setupSurfaces();
    void rotateSurfaces();
    void nextSurface(bool bTween = true);
    
    ofVec3f camStartPos, camEndPos;
    ofQuaternion camStartOrientation, camEndOrientation;
  
    float distWords;
//    ofParameter<float> distWords;
    ofParameter<int>tweenDuration, pauseDuration;
    ofParameter<float>minAngle, maxAngle;
    void tweenEnded(int &i);
  //  void distWordsChange(float & f);
    void angleChanged(float& f);
    ofBlendMode blend;
    
//    ofParameter<float>tweenVal;
//    ofParameter<ofVec3f>camPos;
//    ofParameter<ofVec4f>camOrientation, camStartOrientationParam, camEndOrientationParam;
//    
};
