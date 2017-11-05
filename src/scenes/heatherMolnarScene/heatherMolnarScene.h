#pragma once

#include "ofMain.h"
#include "baseScene.h"

class heatherMolnarScene : public baseScene {
    
public:
    void setup();
    void update();
    void draw();
    
    ofPoint calculateStartCoordinates(int columnPosition, int rowPosition);
    int calculateAngleRangeForColumn(int distanceFromEdge);
    void drawLineWithAngleAndThickness(ofPoint startingPoint, int angle, int distance);
    
    int columns, rows, offset, cellSize;
    float midPoint, possibleAngleVariation;
    
    ofParameter<int> thickness;
    ofParameter<int> minAngle;
    ofParameter<int> maxMidpointAngle;
};
