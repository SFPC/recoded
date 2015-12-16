
#include "yeseulMenkmanInstitution.h"


void yeseulMenkmanInstitution::setup(){
    
    for (int i=0; i<7000; i++) {
        for (int j=0; j<11; j++) {
            patternRandomArray[i][j] = int(ofRandom(1, 11));
        }
    }
    
    for (int i=0; i<5000; i++) {
        patternRandomNumberArray[i] = int(ofRandom(1, 11));
    }
    
    for(int i=0; i<324; i++) {
        squareRandomArray[i] = int(ofRandom(0, 10));
    }
    
    parameters.add(amountOfSquares.set("amountOfSquares", 2, 0, 5));
    parameters.add(numberOfBricks.set("numberOfBricks", 118, 0, 475));
    
    setAuthor("Yeseul Song");
    setOriginalArtist("Rosa Menkman");
    loadCode("scenes/yeseulMenkmanInstitution/exampleCode.cpp");
    
    
}


void yeseulMenkmanInstitution::update(){
    
}


void yeseulMenkmanInstitution::draw(){
    
    unitCounter = 0;
    brickCounter = 0;
    squareCounter = 0;
    
    for (int i=0; i<dimensions.width; i+=unitSize) {
        for (int j=0; j<dimensions.height; j+=unitSize) {
            randomNumber = patternRandomNumberArray[unitCounter];
            drawUnit(i, j, randomNumber, randomNumber%4);
            unitCounter++;
        }
    }
    
    drawSquare();
    
    int numberOfBrickRows = int((numberOfBricks+numberOfBricksPerRow)/numberOfBricksPerRow);
    
    for (int j = 0; j < numberOfBrickRows; j++) {
        if (j == int(numberOfBrickRows)-1) {
            for (int i = 0; i < numberOfBricks%numberOfBricksPerRow; i++) {
                drawBrick(dimensions.width-unitSize*2-i*unitSize*2, dimensions.height-unitSize*2-j*unitSize*2);
                brickCounter++;
            }
        } else {
            for (int i = 0; i < numberOfBricksPerRow; i++) {
                drawBrick(dimensions.width-unitSize*2-i*unitSize*2, dimensions.height-unitSize*2-j*unitSize*2);
                brickCounter++;
                
            }
        }
    }
}


void yeseulMenkmanInstitution::drawUnit(int x, int y, int randomNumber, int rotation) {
    
    int index;
    
    for (int j=0; j<4; j++) {
        for (int i=0; i<4; i++) {
            switch (rotation) {
                case 0:
                    index = i + j*4; // 0 rotation
                    break;
                case 1:
                    index = (3-i)*4 + j; // 90 rotatiion
                    break;
                case 2:
                    index = (3-i) + (3-j)*4; // 180 rotation
                    break;
                case 3:
                    index = i*4 + (3-j); // 270 rotation
                    break;
            }
            
            ofSetColor((unitTypeArray[randomNumber][index])*255);
            ofFill();
            
            ofDrawRectangle(x+i*unitSize/4, y+j*unitSize/4, unitSize/4, unitSize/4);
            
        }
    }
}


void yeseulMenkmanInstitution::drawSquare() {
    
    ofSetColor(0);
    ofFill();
    
    for (int i=0; i<dimensions.width; i+=unitSize*2) {
        for (int j=0; j<dimensions.height; j+=unitSize*2) {
            
            int randomVal = squareRandomArray[squareCounter];
            squareCounter++;
            if (randomVal < amountOfSquares) {
                ofDrawRectangle(i, j, unitSize*2, unitSize*2);
                
            }
        }
    }
}


void yeseulMenkmanInstitution::drawBrick(int x, int y) {
    
    int index = 0;
    int type = 0;
    
    for (int jPos = 0; jPos < 2; jPos+=1) {
        for (int iPos = 0; iPos < 2; iPos+=1) {
            for (int j=0; j<4; j++) {
                for (int i=0; i<4; i++) {
                    if (iPos == 1) {
                        type = 1;
                    }
                    else {
                        type = 0;
                    }
                    switch (type) {
                        case 0:
                            index = i + j*4; // 0 rotation
                            break;
                        case 1:
                            index = (3-i)*4 + j; // 90 rotatiion
                            break;
                    }
                    ofSetColor((wallTypeArray[index])*255);
                    ofFill();
                    
                    ofDrawRectangle(x+iPos*unitSize+i*unitSize/4, y+jPos*unitSize+j*unitSize/4, unitSize/4, unitSize/4);
                    
                }
            }
        }
    }
}



