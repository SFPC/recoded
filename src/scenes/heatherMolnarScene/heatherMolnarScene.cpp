#include "heatherMolnarScene.h"

void heatherMolnarScene::setup(){
    
    // www.galeriecourcarree.com/img/galeries/vera_molnar/web/Galerie-Cour-Carree-Vera-Molnar-8.jpeg
    
    columns = 30;
    rows = 30;
    midPoint = floor(columns/2);
    cellSize = dimensions.width/columns;
    offset = 10;
    minAngle = 90;
    maxMidpointAngle = 135;
//    scaledWidth = 0;
    
    ofBackground(255);
    ofSetColor(0);
    
    thickness.set("thickness", 3, 1, 6);
    minAngle.set("minAngle", 90, 60, 120);
    maxMidpointAngle.set("maxMidpointAngle", 135, 120, 150);
    
    parameters.add(thickness);
    parameters.add(minAngle);
    parameters.add(maxMidpointAngle);
    
    setAuthor("Heather Moore");
    setOriginalArtist("Vera Molnar");
    
    loadCode("scenes/heatherMolnarScene/exampleCode.cpp");
}

void heatherMolnarScene::update(){
    ofSeedRandom(0);
}

void heatherMolnarScene::drawLineWithAngleAndThickness(ofPoint startingPoint, int angleVariation, int distanceFromEdge){
    int maxAngle = minAngle + angleVariation;
    int scaledWidth = (1.0/distanceFromEdge)*thickness;
    
    ofTranslate(startingPoint.x, startingPoint.y);
    ofRotateZ(ofRandom(minAngle, maxAngle));
    ofPoint lineStart = -ofPoint(0, cellSize);
    ofPoint lineEnd = ofPoint(cellSize,0);
    ofSetLineWidth(scaledWidth);
    
    ofDrawLine(lineStart, lineEnd);
}

int heatherMolnarScene::calculateAngleRangeForColumn(int columnPosition){
    float distanceFromEdge = midPoint - abs(columnPosition - midPoint);
    
    if(distanceFromEdge == 0) {
        return 0;
    } else {
        int possibleRange = maxMidpointAngle-minAngle;
        return (possibleRange/midPoint)*distanceFromEdge;
    }
}

ofPoint heatherMolnarScene::calculateStartCoordinates(int columnPosition, int rowPosition){
    float scaledOffset = abs(columnPosition-midPoint) * 10;
    
    int yPos = rowPosition*cellSize;
    int xPos = cellSize*columnPosition;
    
    ofPoint pos;
    if(columnPosition == midPoint) {
        pos = ofPoint(xPos, yPos+offset);
    } else if (columnPosition < midPoint) {
        pos = ofPoint(xPos+(scaledOffset), yPos+offset);
    } else if (columnPosition > midPoint) {
        pos = ofPoint(xPos-(scaledOffset), yPos+offset);
    }
    return pos;
}

void heatherMolnarScene::draw(){
    for (int column=0;column<columns;column++){
        int possibleAngleVariation = calculateAngleRangeForColumn(column);
        
        for (int row=0;row<rows;row++){
            ofPoint lineStart = calculateStartCoordinates(column, row);
            
            ofPushMatrix();
            int distanceFromEdge = midPoint - abs(column - midPoint);
            drawLineWithAngleAndThickness(lineStart, possibleAngleVariation, distanceFromEdge);
            ofPopMatrix();
        }
    }
}


