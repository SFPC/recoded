
#include "yosukeVeraSansTitre.h"

void yosukeVeraSansTitre::setup(){
  
// setup pramaters
    displacementCoef.set("displacement-coef", 25.0, 0.0, 100.0);
    parameters.add(displacementCoef);
    row.set("number-of-row", 9, 1, 50);
    parameters.add(row);
    colmn.set("number-of-colmn", 37, 1, 100);
    parameters.add(colmn);
    spacingPercentX.set("space-x", 1.2, 0.0, 10.0);
    parameters.add(spacingPercentX);
    spacingPercentY.set("space-y", 1.2, 0.0, 10.0          );
    parameters.add(spacingPercentY);

    ofBackground(0);
    ofSetBackgroundAuto(false);

    setAuthor("Yosuke Sakai");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/yosukeVeraSansTitre/exampleCode.cpp");
}

void yosukeVeraSansTitre::update(){

}

void yosukeVeraSansTitre::draw(){
 
    spacingX = rectWidth * spacingPercentX;
    spacingY = rectHeight * spacingPercentY;
    
    gridLeft = (dimensions.width - colmn * spacingX) / 2;
    gridTop = (dimensions.height - row * spacingY) / 2;
    
    centerOfmostTopLeftRect = ofPoint(gridLeft + spacingX / 2, gridTop + spacingY / 2);
    topLeftOfmostTopLeftRect = ofPoint(centerOfmostTopLeftRect.x - rectWidth/2.0, centerOfmostTopLeftRect.y - rectHeight/2.0);

    ofSetColor(255);
    ofNoFill();
    
    for (int i=0; i<row; i++) {
        for(int j=0; j<colmn; j++ ){
            ofDrawRectangle(topLeftOfmostTopLeftRect.x + j*spacingX , topLeftOfmostTopLeftRect.y + i*spacingY + displacementCoef*ofNoise(topLeftOfmostTopLeftRect.x + j*spacingX, topLeftOfmostTopLeftRect.y + i*spacingY, getElapsedTimef()/2.0), rectWidth, rectHeight);
        }
    }

}
