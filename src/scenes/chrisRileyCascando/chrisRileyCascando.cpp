
#include "chrisRileyCascando.h"

#define TRI_SIDE_LENGTH 40.0
#define ROOT_3          1.73205
#define TRI_HEIGHT      TRI_SIDE_LENGTH * 1.73205 / 2.0
#define NOISE_SCALE     1.0/1000.0

void chrisRileyCascando::setup(){
  
// setup pramaters
    triScale.set("triScale", 0.2, 0.01, 1);
    parameters.add(triScale);
    
    noiseScale.set("noiseScale", 1000, 10, 10000);
    parameters.add(noiseScale);
    
    pStraight.set("pStraight", 0.7, 0, 1);
    parameters.add(pStraight);
    
    animSpeed.set("animSpeed", 100, -1000, 1000);
    parameters.add(animSpeed);
    
    diamondStraightBlack.lineTo(TRI_SIDE_LENGTH,   0);
    diamondStraightBlack.lineTo(TRI_SIDE_LENGTH/2, TRI_HEIGHT);
    diamondStraightBlack.lineTo(0, 0);
    diamondStraightBlack.close();
    diamondStraightBlack.setFilled(true);
    diamondStraightBlack.setStrokeWidth(0);
    diamondStraightBlack.setFillColor(ofColor(0));
    
    diamondStraightWhite.moveTo(TRI_SIDE_LENGTH,         0);
    diamondStraightWhite.lineTo(3 * TRI_SIDE_LENGTH / 2, TRI_HEIGHT);
    diamondStraightWhite.lineTo(TRI_SIDE_LENGTH / 2,     TRI_HEIGHT);
    diamondStraightWhite.lineTo(TRI_SIDE_LENGTH,         0);
    diamondStraightWhite.close();
    diamondStraightWhite.setFilled(true);
    diamondStraightWhite.setStrokeWidth(0);
    diamondStraightWhite.setFillColor(ofColor(255));
    
    diamondArcBlack.arc(0, 0, TRI_SIDE_LENGTH, TRI_SIDE_LENGTH, 0, 60);
    diamondArcBlack.close();
    diamondArcBlack.setCircleResolution(100);
    diamondArcBlack.setFilled(true);
    diamondArcBlack.setStrokeWidth(0);
    diamondArcBlack.setFillColor(ofColor(0));
    
    diamondArcWhite.arc(3 * TRI_SIDE_LENGTH / 2, TRI_HEIGHT, TRI_SIDE_LENGTH, TRI_SIDE_LENGTH, 180, 240);
    diamondArcWhite.close();
    diamondArcWhite.setCircleResolution(100);
    diamondArcWhite.setFilled(true);
    diamondArcWhite.setStrokeWidth(0);
    diamondArcWhite.setFillColor(ofColor(255));
    
    lastTime = 0;
    integratedTime = 0;

    setAuthor("Chris Anderson");
    setOriginalArtist("Bridget Riley");
    loadCode("scenes/chrisRileyCascando/exampleCode.cpp");
}

void chrisRileyCascando::reset() {
    lastTime = 0;
    integratedTime = 0;
}

void chrisRileyCascando::update(){
    float now = getElapsedTimef();
    if (lastTime == 0) {
        lastTime = now;
    }
    float dt = now - lastTime;
    lastTime = now;
    
    integratedTime += animSpeed * dt;
}

void chrisRileyCascando::draw(){
    ofEnableAntiAliasing();

    ofPushMatrix();
    ofTranslate(VISUALS_WIDTH / 2.0, VISUALS_HEIGHT / 2.0);
    
    ofPushMatrix();
    float scale = ofMap(sqrt(1.0 - triScale), 1, 0, 1.0/3.0, 4.0);
    ofScale(scale, scale);
    
    float startY = -VISUALS_WIDTH * 3;
    float startX = -VISUALS_WIDTH * 3;
    float endY   = VISUALS_WIDTH * 4;
    float endX   = VISUALS_WIDTH * 4;
    
    bool odd = false;
    for (int y = startY; y < endY; y += TRI_HEIGHT) {
        odd = !odd;

        for (int x = startX; x < endX; x += TRI_SIDE_LENGTH) {
            ofPushMatrix();
            
            ofTranslate(-VISUALS_WIDTH / 2.0, -VISUALS_HEIGHT / 2.0);
            ofTranslate(x, y);
            
            // Bump us over half a triangle on odd rows
            if (odd)
                ofTranslate(TRI_SIDE_LENGTH / 2.0, 0);

            // Add horizontal animation and loop it.
            float xDelta = fmod(integratedTime, TRI_SIDE_LENGTH);
            float r = ofNoise((x + integratedTime) * (1.0/noiseScale), y * (1.0/noiseScale));

            if (r < pStraight) {
                diamondStraightBlack.draw();
                diamondStraightWhite.draw();
            } else if (r < pStraight + (1.0-pStraight) / 2.0) {
                diamondStraightWhite.draw();
                diamondArcBlack.draw();
            } else {
                diamondStraightBlack.draw();
                diamondArcWhite.draw();
            }

            ofPopMatrix();
        }
    }

    ofPopMatrix();
    
    ofPopMatrix();
    ofDisableAntiAliasing();
}