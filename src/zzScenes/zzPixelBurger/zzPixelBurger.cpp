
#include "zzPixelBurger.h"

void zzPixelBurger::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzPixelBurger.h
    parameters.add(chaos.set("chaos", 0,0, 1));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("zzScenes/zzPixelBurger/exampleCode.cpp", false);
    
    burgerColors.push_back(ofColor(255, 200, 50));
    burgerColors.push_back(ofColor(225, 200, 225));
    burgerColors.push_back(ofColor(225, 50, 50));
    burgerColors.push_back(ofColor(150, 200, 50));
    burgerColors.push_back(ofColor(255, 225, 0));
    burgerColors.push_back(ofColor(190, 79, 24));
    burgerColors.push_back(ofColor(255, 225, 0));
    burgerColors.push_back(ofColor(190, 79, 24));
    burgerColors.push_back(ofColor(255, 200, 50));
    
    burgerHeights.push_back(0.25); // 833  833 830 .25
    burgerHeights.push_back(0.0625); // 1041 208 210 .0625
    burgerHeights.push_back(0.0625); // 1250 209 210 .0625
    burgerHeights.push_back(0.125); // 1666 416 415 .125
    burgerHeights.push_back(0.0625); // 1875 209 210 .0625
    burgerHeights.push_back(0.125); // 2292 417 415 .125
    burgerHeights.push_back(0.0625); // 2500 208 210 .0625
    burgerHeights.push_back(0.125); // 2917 417 415 .125
    burgerHeights.push_back(0.125); // 3333 416 415 .125
    
    float y = 0;
    for (int i = 0; i < burgerHeights.size(); i++) {
        ofRectangle temp = ofRectangle(0, dimensions.height * y, dimensions.width, dimensions.height * burgerHeights[i]);
        burgerLayers.push_back(temp);
        y += burgerHeights[i];
    }
    
}

void zzPixelBurger::update(){
    
}

void zzPixelBurger::draw(){
    
    ofSeedRandom(0);
    
    float y = 0;
    for (int i = 0; i < burgerLayers.size(); i++) {
        ofRectangle r = burgerLayers[i];
        float xOffset1 = ofRandom(r.x, r.x + r.getWidth());
        float yOffset1 = ofRandom(r.y, r.y + r.getHeight());
        float xOffset2 = ofRandom(r.x, r.x + r.getWidth());
        float yOffset2 = ofRandom(r.y, r.y + r.getHeight());
        ofPushMatrix();
            ofTranslate(ofMap(chaos, -1, 1, xOffset1, xOffset2), ofMap(chaos, -1, 1, yOffset1, yOffset2));
            ofRotateZ(chaos * ofRandom(-50, 50));
            ofRotateY(chaos * ofRandom(-50, 50));
            ofTranslate(ofMap(chaos, -1, 1, -xOffset1, -xOffset2), ofMap(chaos, -1, 1, -yOffset1, -yOffset2));
            ofSetColor(burgerColors[i]);
            ofDrawRectangle(r);
        ofPopMatrix();
    }
    
    ofSetColor(255);
    ofRectangle bun = burgerLayers[0];
    int xCount = 15;
    int yCount = 3;
    for (int i = 0; i < xCount; i++) {
        for (int j = 0; j < yCount; j++) {
            
            float xOffset = ofRandom(bun.x, bun.x + bun.getWidth());
            float yOffset = ofRandom(bun.y, bun.y + bun.getHeight());
            ofPushMatrix();
                ofTranslate(xOffset, yOffset);
                ofRotateZ(chaos * ofRandom(-50, 50));
                ofRotateY(chaos * ofRandom(-50, 50));
                ofTranslate(-xOffset, -yOffset);
            
                float x = ofMap(i + 1, 0, xCount + 1, bun.x, bun.x + bun.getWidth());
                float y = ofMap(j + 1, 0, yCount + 1, bun.y, bun.y + bun.getHeight());
                if (i % 2 == 1) {
                    if (i % 4 == 1 && j % 3 == 1) {
                        ofDrawRectangle(x - 10, y - 10, 20, 20);
                    }
                    if (i % 4 == 3 && (j % 3 == 0 || j % 3 == 2)) {
                        ofDrawRectangle(x - 10, y - 10, 20, 20);
                    }
                }
            ofPopMatrix();
        }
    }
    
}
