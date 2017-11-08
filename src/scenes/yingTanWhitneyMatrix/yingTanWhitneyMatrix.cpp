
#include "yingTanWhitneyMatrix.h"

void yingTanWhitneyMatrix::setup(){

    ofBackground(0);
    ofNoFill();

    // don't freeze time for recoded project
    hexagonTrack1 = new HexagonTrack1(dimensions);
    hexagonTrack2 = new HexagonTrack1(dimensions);
    hexagonTrack3 = new HexagonTrack1(dimensions);

    hexagonTrack1->freezeTime = -100;
    hexagonTrack2->freezeTime = -100;
    hexagonTrack3->freezeTime = -100;

    time = 0;

    time_scale.set("time_scale", 1.0, 0, 1.5);
    parameters.add(time_scale);
    spacing.set("spacing", 0.4, 0.0, 2.0);
    parameters.add(spacing);

    setAuthor("Ying Quan Tan");
    setOriginalArtist("John Whitney");
    loadCode("scenes/yingTanWhitneyMatrix/exampleCode.cpp");
}

void yingTanWhitneyMatrix::update() {
    time += ofGetLastFrameTime() * time_scale;
    hexagonTrack1->spacingRatioMultiplier = spacing;
    hexagonTrack2->spacingRatioMultiplier = spacing;
    hexagonTrack3->spacingRatioMultiplier = spacing;
}

void yingTanWhitneyMatrix::draw(){
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofNoFill();
    ofSetLineWidth(2);
    hexagonTrack1->draw(time);
    hexagonTrack2->draw(time + 3);
    hexagonTrack3->draw(time + 8);
    ofPopStyle();
}
