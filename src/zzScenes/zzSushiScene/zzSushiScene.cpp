
#include "zzSushiScene.h"

void zzSushiScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzSushiScene.h
    parameters.add(imageScale.set("image scale", 0.0075, 0.005, 0.02));
    parameters.add(widthScale.set("width scale", 0.8, 0.5, 1));
    parameters.add(drawEvery.set("spacing", 4, 2, 20));

    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");

    loadCode("scenes/zzSushiScene/exampleCode.cpp", false);
    center.set(dimensions.getCenter());


    font.load("zzScenes/zzSushiScene/SF.otf", 200, true, true, true);

    ofBackground(0);
    string stringToUse = "sushi";
    bounds = font.getStringBoundingBox(stringToUse, 0, 0);
    auto offset = ofPoint(-bounds.width/2, bounds.height/2);

    characters = font.getStringAsPoints(stringToUse);

    for (int i = 0; i < imageCount; i++) {
        char buf[30];
        sprintf(buf, "zzScenes/zzSushiScene/%d.png", i);
        images[i].load(buf);
    }
}

void zzSushiScene::update(){
    scale = (dimensions.width * widthScale) /bounds.width;
    sushiScale = dimensions.width / images[0].getWidth() * imageScale;
}

void zzSushiScene::draw(){

    ofColor backgroundColor = ofColor::fromHsb(fmod(ofGetElapsedTimef() * 2.0, 255), 200, 255);
    ofBackground(backgroundColor);

    ofPushStyle();

    ofPushMatrix();
    ofTranslate(center.x - (bounds.width/2 + bounds.x) * scale, center.y + (bounds.height/2) * scale);
    ofScale(scale, scale);

    for (ofTTFCharacter shape : characters) {
        vector<ofPolyline> lines = shape.getOutline();
        for (ofPolyline line : lines) {
            ofPolyline resampledLine = line.getResampledBySpacing(5);
            drawAlongLine(resampledLine);
        }
    }

    ofPopMatrix();
    ofPopStyle();
}

void zzSushiScene::drawAlongLine(ofPolyline &polyline) {
    float size = polyline.size();
    float time = ofGetElapsedTimef() * 0.08;
    float length  = polyline.getLengthAtIndex(polyline.size()-1);
    int numberOfPointsToDraw = size / drawEvery; // draw every x points
    float increment = 1.0/numberOfPointsToDraw;

    int count = 0;
    float pct = 0.0;
    while(pct < 0.98) {

        ofPushMatrix();
        ofSetRectMode(OF_RECTMODE_CENTER);
        float offset = fmod(pct + time, 1.0);
        float findex = polyline.getIndexAtPercent(offset);
        float fangle = polyline.getAngleAtIndexInterpolated(findex);

        int i_m_1 = fmod(findex - 1 + size, size);
        int i_p_1 = fmod(findex + 1 + size, size);

        ofPoint diff = polyline[i_p_1] - polyline[i_m_1];
        float angle = atan2(diff.y, diff.x);

        ofPoint point = polyline.getPointAtPercent(offset);
        ofTranslate(point.x, point.y);
        ofRotate(angle * RAD_TO_DEG);
        ofScale(sushiScale, sushiScale);


        //        sushiImage.draw(0, 0);
        images[count].draw(0, 0);

        ofPopMatrix();

        pct += increment;
        count = (count + 1) % imageCount;
    }
}
