#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yeseulMenkmanInstitution : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawUnit(int x, int y, int randomArrayNum, int rotation = 0);
    void drawSquare();
    void drawBrick(int x, int y);
    
    ofParameter<int> numberOfBricks;
    ofParameter<int> amountOfSquares;
    
    int numberOfUnitsPerRow = 36;
    float unitSize = 504/numberOfUnitsPerRow;
    int numberOfBricksPerRow = numberOfUnitsPerRow;
    
    int randomNumber;
    int unitCounter;
    int brickCounter;
    int squareCounter;
    
    int patternRandomArray[7000][16];
    int patternRandomNumberArray[5000];
    int squareRandomArray[324];
    
    int unitTypeArray[11][16] = {
        {1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    
    int wallTypeArray[16] =
    {1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1};
    
    
};