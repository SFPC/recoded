
#include "RoyWhitney1.h"

void RoyWhitney1::setup(){
    parameters.add(radius0.set("Radius", 200, 1, 1000));
    parameters.add(size0.set("Size", 50, 1, 1000));
    parameters.add(multiplier.set("multiplier", 2, 0, 10));
    parameters.add(speed.set("Speed", 0.01, 0, 1));
    parameters.add(circles.set("Number Of Circles", 10, 1, 10));
//    parameters.add(iterations.set("Iterations", 2, 1, 10));
    parameters.add(opacity.set("Opacity", 20, 0, 255));
    parameters.add(lineWidth.set("Line Width", 1,0, 10));
//    parameters.add(currentTime.set("Current Time", 0,0, 5000));
//    parameters.add(currentSize.set("Current Size", 50,0,400));

    setAuthor("Roy MacDonald");
    setOriginalArtist("John Whitney");
    loadCode("scenes/RoyWhitney1/exampleCode.cpp");
    
    iterations = 2;
}

void RoyWhitney1::update(){
    
}


void RoyWhitney1::draw(){
    ofVec3f center (VISUALS_WIDTH/2,VISUALS_HEIGHT/2);
    ofNoFill();
    ofBackground(0);
    ofSetColor(255,opacity);
    ofSetLineWidth(lineWidth);
    drawCircles(center, radius0, TWO_PI*getElapsedTimef()*speed, size0, circles, 0);
}
//--------------------------------------------------------------
void RoyWhitney1::drawCircles(ofVec3f center, float radius, float time, float size, int numCircles, int currentIteration){
    for (int i =0; i < numCircles; i++) {
        float angle = TWO_PI*(i/float(numCircles)) + time;
        if (currentIteration < iterations) {
            drawCircles(ofVec3f(center.x+ radius*sin(angle),
                                center.y+ radius*cos(angle)),
                        size*multiplier,
                        time/2,
                        radius/multiplier,
                        numCircles*2,
                        currentIteration+1);
        }else{
            ofDrawCircle( center.x+ radius*sin(angle)
                         ,center.y+ radius*cos(angle), size);
        }
    }
}
