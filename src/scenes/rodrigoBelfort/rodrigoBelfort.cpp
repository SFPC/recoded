
#include "rodrigoBelfort.h"
#include "appConstants.h"

const int origA[] = {1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0};
const int origB[] = {0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1};
const int origC[] = {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0};

#define WINDOW_PADDING          10.0
#define RECT_WIDTH_TO_PADDING   4.0

void rodrigoBelfort::setup(){
  
    timeBtwnLines.set("timeBtwnLines", 0.2, 0, 1);
    parameters.add(timeBtwnLines);
    
    pNewLine.set("pNewLine", 0.1, 0, 1);
    parameters.add(pNewLine);
    
    // Calculate rectangle size and padding from width
    float availableSpaceX = (VISUALS_WIDTH - WINDOW_PADDING * 2);
    float widthUnits = BELFORT_COLS * RECT_WIDTH_TO_PADDING + (BELFORT_COLS - 1);
    float unitWidth = availableSpaceX / widthUnits;
    rectSize = unitWidth * RECT_WIDTH_TO_PADDING;
    paddingSizeX = unitWidth;
    
    // Calculate Y padding
    float availableSpaceY = (VISUALS_HEIGHT - WINDOW_PADDING * 2);
    float totalPaddingY = availableSpaceY - unitWidth * BELFORT_ROWS;
    paddingSizeY = availableSpaceY / ((BELFORT_ROWS - 1) * 2);
    
    // Load in original
    for (int i = 0; i < BELFORT_ROWS; i++) {
        const int (*shape)[BELFORT_COLS];
        
        if (i < 5) {
            shape = &origA;
        } else if (i < 29) {
            shape = &origB;
        } else {
            shape = &origC;
        }

        for (int j = 0; j < BELFORT_COLS; j++) {
            dots[i][j]=(*shape)[j];
        }
    }

    setAuthor("Rodrigo Carvalho");
    setOriginalArtist("Belfort Group");
    loadCode("scenes/rodrigoBelfort/exampleCode.cpp");
}

void rodrigoBelfort::reset() {
    lastLineTime = 0;
}

void rodrigoBelfort::update(){
    if (lastLineTime == 0) {
        lastLineTime = getElapsedTimef();
    }

    float time = getElapsedTimef();
    
    if (lastLineTime + timeBtwnLines < time) {
        lastLineTime = time;
        // Copy all the lines down one
        for (int i = BELFORT_ROWS - 1; i >= 1; i--) {
            memcpy(dots[i], dots[i-1], sizeof(int) * BELFORT_COLS);
        }
        
        // Sometimes randomly replace the first line
        if (ofRandomuf() < pNewLine) {
            for (int i = 0; i < BELFORT_COLS; i++) {
                dots[0][i] = round(ofRandomuf());
            }
        }
    }
}

void rodrigoBelfort::draw(){
    for (int i = 0; i < BELFORT_ROWS; i++) {
        for (int j = 0; j < BELFORT_COLS; j++) {
            if (!dots[i][j]) continue;
            
            ofFill();
            ofSetLineWidth(0);
            ofDrawRectangle(j*(rectSize+paddingSizeX)+WINDOW_PADDING,
                            i*(rectSize+paddingSizeY)+WINDOW_PADDING,
                            rectSize, rectSize);
        }
    }
}