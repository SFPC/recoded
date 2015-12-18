#include "veraFscene.h"

void veraFscene::setup(){
    
    //parameters.add(numberOfF.set("numberOfF", 4, 4, 50));
    numberOfF = 40;
    parameters.add(frequency.set("frequency", 0.0, 0.0, 0.5));
    parameters.add(margin.set("margin", 4, 0, 10));
    parameters.add(lineWidth.set("lineWidth", 2, 0, 10));
    parameters.add(zoom.set("zoom", 1, 0.66667, 3));
    lastValue = 0;
    
    setAuthor("Becca Moore");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/veraFscene/exampleCode.cpp");
}

void veraFscene::update(){
    
}


void veraFscene::draw(){
    
//    sizeOfF = dimensions.width/numberOfF;
    sizeOfF = 20.0;
    
//    if (sizeOfF > dimensions.width-(sizeOfF*(numberOfF-1))) {
//        offset = (dimensions.width - sizeOfF*(numberOfF-1))/2;
//    } else {
//        offset = (dimensions.width - sizeOfF*(numberOfF))/2;
//    }
    
    float drawnSize = sizeOfF * numberOfF;
    ofPushMatrix();
    ofTranslate(dimensions.width / 2.0, dimensions.height / 2.0);
    ofScale(zoom, zoom);
    ofPushMatrix();
    ofTranslate(-drawnSize / 2.0, -drawnSize / 2.0);
    
    
    ofSetColor(255);
    ofSetLineWidth(lineWidth * zoom);
    
    for (int i = 0; i< numberOfF; i++){
        for (int j = 0; j< numberOfF; j++) {
            ofPushMatrix();
            ofTranslate(i*sizeOfF, j*sizeOfF);
            float rand = ofNoise(i,j, ofGetElapsedTimef());
            if (rand < frequency) {
                if (rand < frequency / 3.0) {
                    ofScale(-1, 1);
                } else if (rand < frequency * 2.0 / 3.0) {
                    ofScale(-1, -1);
                } else {
                    ofScale(1, -1);
                }
            }
            drawf();
            
            ofPopMatrix();
        }
    }
    ofPopMatrix();
    ofPopMatrix();
}



void veraFscene::drawf()
{
    ofPushMatrix();
    float lineSize = sizeOfF - margin;
    ofTranslate(-lineSize/2.0, -lineSize/2.0);
    ofDrawLine(0, 0, 0, lineSize);
    ofDrawLine(0, 0, lineSize, 0);
    ofDrawLine(0, lineSize/2.0, lineSize, lineSize/2.0);
    ofPopMatrix();
}



void veraFscene::drawf2()
{
    ofDrawLine(0, 0, 0, sizeOfF - margin);
    ofDrawLine(0, sizeOfF - margin, sizeOfF - margin, sizeOfF - margin);
    ofDrawLine(0, (sizeOfF - margin)/2.0, sizeOfF - margin, (sizeOfF - margin)/2.0);
}
