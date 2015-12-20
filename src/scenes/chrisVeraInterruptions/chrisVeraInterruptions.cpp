
#include "chrisVeraInterruptions.h"
#include "appConstants.h"

#define N_XY            60
#define GRID_PADDING    10

#define N_GAPS          10

void chrisVeraInterruptions::setup(){
  
    // setup pramaters
    lineWidth.set("lineWidth", 2, 0, 10);
    parameters.add(lineWidth);
    
    lineLength.set("lineLength", 10, 0, 100);
    parameters.add(lineLength);
    
    rotationSpeed.set("rotationSpeed", 100, 0, 1000);
    parameters.add(rotationSpeed);
    
    deletionChance.set("deletionChance", 0.2, 0, 1);
    parameters.add(deletionChance);
    
    timeBtwnHoles.set("timeBtwnHoles", 0.2, 0, 5);
    parameters.add(timeBtwnHoles);

    timeBtwnWalk.set("timeBtwnWalk", 0.25, 0, 2);
    parameters.add(timeBtwnWalk);
    
    timeBtwnReset.set("timeBtwnReset", 20, 0, 60);
    parameters.add(timeBtwnReset);
    
    timeBtwnRemove.set("timeBtwnRemove", 0.01, 0, 0.2);
    parameters.add(timeBtwnRemove);
    
    gridStartX = GRID_PADDING;
    gridStartY = GRID_PADDING;
    gridMarginX = (float)(VISUALS_WIDTH  - 2 * GRID_PADDING) / (N_XY - 1);
    gridMarginY = (float)(VISUALS_HEIGHT - 2 * GRID_PADDING) / (N_XY - 1);

    resetGrid();
    resetRecent();
    redrawGrid();

    setAuthor("Chris Anderson");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/chrisVeraInterruptions/exampleCode.cpp");
}

void chrisVeraInterruptions::reset() {
    lastResetTime = 0;
    lastHoleTime = 0;
    lastWalkTime = 0;
    lastRemoveTime = 0;
}

void chrisVeraInterruptions::update() {
    float time = getElapsedTimef();
    
    if (lastResetTime + timeBtwnReset < time) {
        lastResetTime = time;
        refillGrid();
        resetRecent();
    }
    
    if (lastHoleTime + timeBtwnHoles < time) {
        lastHoleTime = time;
        recentClear[floor(ofRandom(N_XY))][floor(ofRandom(N_XY))] = true;
    }
    
    if (lastWalkTime + timeBtwnWalk < time) {
        lastWalkTime = time;
        walkLinesOneStep();
    }
    
    if (lastRemoveTime + timeBtwnRemove < time) {
        lastRemoveTime = time;
        removeOne();
    }
}

void chrisVeraInterruptions::refillGrid() {
    for (int i = 0; i < N_XY; ++i) {
        for (int j = 0; j < N_XY; ++j) {
            if (lineGrid[i][j]) continue;
            
            int randAngle = floor(ofRandom(359)) + 1;
            lineGrid[i][j] = randAngle;
            lineGridGoal[i][j] = randAngle;
        }
    }
}

void chrisVeraInterruptions::resetGrid() {
    lineGrid.clear();
    
    for (int i = 0; i < N_XY; ++i) {
        vector<int> lineRow;

        for (int j = 0; j < N_XY; ++j) {
            lineRow.push_back(0);
        }

        lineGrid.push_back(lineRow);
        lineGridGoal.push_back(lineRow);
    }
}
        
void chrisVeraInterruptions::redrawGrid() {
    refillGrid();
    
    int gaps = N_GAPS;
    while (gaps > 0) {
        int i = floor(ofRandomuf() * N_XY);
        int j = floor(ofRandomuf() * N_XY);
        
        if (!lineGrid[i][j]) continue;
        
        walkLines(i, j, lineGrid);
        --gaps;
    }
}

void chrisVeraInterruptions::resetRecent() {
    toRemove = queue<pair<int, int>>();
    recentClear.clear();
    
    for (int i = 0; i < N_XY; ++i) {
        vector<bool> lineRow;
        
        for (int j = 0; j < N_XY; ++j) {
            lineRow.push_back(false);
        }
        
        recentClear.push_back(lineRow);
    }
}

void chrisVeraInterruptions::removeOne() {
    if (!toRemove.size())
        return;

    pair<int, int> pos = toRemove.front();
    lineGrid[pos.first][pos.second] = 0;
    toRemove.pop();
}

void chrisVeraInterruptions::walkLines(int i, int j, vector<vector<int>> &grid) {
    if (!grid[i][j]) return;

    grid[i][j] = 0;

    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            int i2 = i + di;
            int j2 = j + dj;

            if (i2 < 0 || i2 >= grid.size() || j2 < 0 || j2 >= grid[i].size())
                continue;

            if (ofRandomuf() < deletionChance) {
                walkLines(i + di, j + dj, grid);
            }
        }
    }
}

void chrisVeraInterruptions::walkLinesOneStep() {
    for (int i = 0; i < N_XY; ++i) {
        for (int j = 0; j < N_XY; ++j) {
            if (!recentClear[i][j]) continue;

            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int i2 = i + di;
                    int j2 = j + dj;
                    
                    if (i2 < 0 || i2 >= lineGridGoal.size() || j2 < 0 || j2 >= lineGridGoal[i].size())
                        continue;
                    if (!lineGridGoal[i2][j2])
                        continue;
                    
                    if (ofRandomuf() < deletionChance) {
                        pair<int, int> pos(i2, j2);
                        toRemove.push(pos);
                        lineGridGoal[i2][j2] = 0;
                        recentClear[i2][j2] = true;
                    }
                }
            }
            
            recentClear[i][j] = false;
        }
    }
}

void chrisVeraInterruptions::draw() {
    ofBackground(0);
    ofSetLineWidth(lineWidth);
    
    for (int i = 0; i < N_XY; ++i) {
        for (int j = 0; j < N_XY; ++j) {
            if (!lineGrid[i][j]) continue;

            ofPushMatrix();

            ofTranslate(i * gridMarginX + gridStartX, j * gridMarginY + gridStartY);
            ofRotate(lineGrid[i][j] + getElapsedTimef() * rotationSpeed);
            ofDrawLine(-lineLength / 2.0, 0, lineLength / 2.0, 0);
            
            ofPopMatrix();
        }
    }

}
