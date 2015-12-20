#pragma once

#include "ofMain.h"
#include "baseScene.h"

class chrisVeraInterruptions : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void reset();
    
    ofParameter<float> lineWidth, lineLength, rotationSpeed, deletionChance,
        timeBtwnHoles, timeBtwnWalk, timeBtwnReset, timeBtwnRemove;
    
    float gridStartX, gridStartY, gridMarginX, gridMarginY;
    float lastHoleTime, lastWalkTime, lastResetTime, lastRemoveTime;
    
    vector<vector<int>> lineGridGoal, lineGrid;
    vector<vector<bool>> recentClear;
    queue<pair<int, int>> toRemove;
private:
    void resetRecent();
    void removeOne();
    void walkLinesOneStep();

    void walkLines(int i, int j, vector<vector<int>> &grid);

    
    void redrawGrid();
    void refillGrid();
    void resetGrid();
};