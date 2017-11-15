//
//  emoji.cpp
//  cloudZZRecode1
//
//  Created by Ann Kidder on 11/13/17.
//
//

#include "emoji.hpp"

Emoji::Emoji(){
}

void Emoji::setup(int x, int y, ofImage * icon){
    x_start = x;
    img = icon;
    emojiSpeed = 1;
    emojiSize = 1; //img->getWidth();
    y_val = y;
    creation_time = ofGetElapsedTimef();
    
    randomOffset = ofRandom(0, TWO_PI);
    randomSpeed = ofRandom(0.8, 1.2);
}

void Emoji::update(){
    y_val += emojiSpeed*randomSpeed;
}

void Emoji::draw(){
    //img.resize(emojiSize, emojiSize);
    float time = ofGetElapsedTimef();
    float time_diff = time - creation_time;
    ofSetRectMode(OF_RECTMODE_CENTER);
    float w = ofGetMouseX();
    ofPushMatrix();
    ofTranslate(x_start, y_val);
    ofRotateZ(0 + sin(ofGetElapsedTimef() * randomSpeed + randomOffset) * 20);
    img->draw(0,0,  img->getWidth()*emojiSize,  img->getHeight()*emojiSize);
    ofPopMatrix();
    
    ofSetRectMode(OF_RECTMODE_CORNER);
}
