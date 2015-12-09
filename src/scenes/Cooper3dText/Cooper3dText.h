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

    ofTrueTypeFont* font;
    ofRectangle r;

    ofTexture tex;
        
    textSurface(){
        font = NULL;
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
    
    void customDraw(){
        ofPushStyle();
        ofSetColor(255);
        tex.draw(0,-r.height);
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
    
    ofCamera cam;
    int currentSurface, prevSurface;
    
    ofxTween tween;
    ofxEasingExpo easing;
    
    void updateCameraTween();
    
    void setupSurfaces();
    
    void nextSurface(bool bTween = true);
    
    ofVec3f camStartPos, camEndPos;
    ofQuaternion camStartOrientation, camEndOrientation;
    
    ofParameter<float> distWords;
    ofParameter<int>tweenDuration, pauseDuration;
    
    void tweenEnded(int &i);
    void distWordsChange(float & f);
    
    ofBlendMode blend;
    
    ofParameter<float>tweenVal;
    ofParameter<ofVec3f>camPos;
    ofParameter<ofVec4f>camOrientation, camStartOrientationParam, camEndOrientationParam;
    
};
