
#include "sarahgpRileyCircle.h"

void sarahgpRileyCircle::setup(){
  
    // these three can be set dynamically
    parameters.add(numCircles.set("numCircles", 30, 0, 100));
    shift.set("shift", true, false, true);
    parameters.add(blue.set("brightness", 255, 0, 255));
    parameters.add(angle.set("angle", 0, 0, 180));
    
    center.x = dimensions.width/2;
    center.y = dimensions.height/2 + dimensions.height * .09;
    
    weeArc.setCircleResolution(100);
    weeArc.setFilled(false);
    weeArc.setStrokeWidth(1);

    setAuthor("Sarah Groff-Palermo");
    setOriginalArtist("Bridget Riley");
    loadCode("scenes/sarahgpRileyCircle/exampleCode.cpp");
}

void sarahgpRileyCircle::update(){
    weeArc.setStrokeColor(ofColor(blue,blue,blue));
}

void sarahgpRileyCircle::draw(){
    ofPushMatrix();
    ofScale(0.6, 0.6);
    ofTranslate(150, 150);
    ofSetLineWidth(2);
    if (shift){
        for (int i = 1; i < numCircles + 1; i++){
            float rad = i * (10 - .04 * i);
            float maxRad = numCircles;
            float diff = (center.y + maxRad * sin(ofDegToRad(90)))
                         - (center.y + (.35 * maxRad) * sin(ofDegToRad(90)));
            
            weeArc.moveTo(center.x, center.y - rad);
            weeArc.arc(center, rad, rad, 270 - angle, 90 - angle);
            weeArc.arc(center.x - 30, center.y - diff * 2, rad, rad, 92 - angle, 190 - angle);
            weeArc.arc(center.x - 40, center.y - diff * 6,  1.18 * rad, 1.18 * rad, 180 - angle, 260 - angle);
            
            weeArc.close();
            weeArc.draw();
            
        }
    } else {
        for (int i = 1; i < numCircles + 1; i++){
            float rad = i * (10 - .04 * i);
            
            weeArc.moveTo(center.x, center.y - rad);
            weeArc.arc(center, rad, rad, 270, 270);
            weeArc.draw();
            
        }
    }
    weeArc.clear();
    ofPopMatrix();
}