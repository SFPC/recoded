
#include "yeseulRileybrokencircle.h"


void yeseulRileyBrokencircle::setup(){
    
    setAuthor("Yeseul Song");
    setOriginalArtist("Bridget Riley");
    
    parameters.add(speed.set("speed", 0.7, 0, 10));
    parameters.add(rotation.set("rotation", 0, 0, 180));
    parameters.add(numberOfPatterns.set("numberOfPatterns", 1, 1, 7));
    
    loadCode("scenes/yeseulRileybrokencircle/exampleCode.cpp");
}


void yeseulRileyBrokencircle::update(){
    
}

void yeseulRileyBrokencircle::draw(){
    
    ofBackground(0);
    
    if (bDirection) {
        speedVal+=speed/numberOfPatterns;
    } else {
        speedVal-=speed/numberOfPatterns;
    }
    
    if (speedVal*numberOfPatterns>=100 || speedVal*numberOfPatterns<=0) {
        
        bDirection = !bDirection;
    }
    
    if (oldNumberOfPatterns == numberOfPatterns){
    } else {
        oldNumberOfPatterns = numberOfPatterns;
        resetSpeedVal();
    }
    
    for (int j=0; j<numberOfPatterns; j+=1){
        
        float startX = dimensions.width/(1+(numberOfPatterns))*(j+1)-dimensions.width/2;
        float startY = dimensions.height/2-dimensions.height/2;
        
        circle1.set(startX+10/numberOfPatterns-speedVal*0.1, startY-40/numberOfPatterns+speedVal*0.4);
        circle2.set(startX+15/numberOfPatterns-speedVal*0.15, startY-35/numberOfPatterns+speedVal*0.35);
        circle3.set(startX-20/numberOfPatterns+speedVal*0.2, startY+20/numberOfPatterns-speedVal*0.2);
        circle4.set(startX, startY);
        
        ofPushMatrix();
        ofTranslate(dimensions.width/2, dimensions.height/2);
        ofRotate(rotation);
        
        drawShape();
        
        ofPopMatrix();
    
    }
}


void yeseulRileyBrokencircle::resetSpeedVal(){
    speedVal = 0;
    bDirection = true;
}


void yeseulRileyBrokencircle::drawShape() {
    
    glLineWidth(0.1);
    float radius = 170/numberOfPatterns;
    float firstGap = 25/numberOfPatterns;
    float gap [14];
    
    ofSetColor(255);
    ofPolyline shapes [14];
    
    gap [0] = firstGap;
    gap [13] = firstGap*2;
    
    for (int i=1; i<13; i++) {
        if (i < 7) {
            firstGap = firstGap*2/3;
            gap[i] = gap[i-1]+firstGap;
        } else {
            firstGap = firstGap*3/2;
            gap[i] = gap[i-1]+firstGap;
        }
    }
    
    for (int i = 0; i < 14; i++) {
        
        shapes[i].arc(circle1, radius-gap[i], radius-gap[i], -90, 0, 100);
        shapes[i].arc(circle2, radius-gap[i], radius-gap[i], 0, 90, 100);
        shapes[i].arc(circle3, radius-gap[i], radius-gap[i], 90, 180, 100);
        shapes[i].arc(circle4, radius-gap[i], radius-gap[i], 180, 270, 100);
        shapes[i].close();
        shapes[i].draw();
        
    }
}


