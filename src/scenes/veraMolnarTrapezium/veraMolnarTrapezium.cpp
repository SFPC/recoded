
#include "veraMolnarTrapezium.h"

void veraMolnarTrapezium::setup(){

	iCenterX = 0;
	iCenterY = 1;
	iTopLeftOffsetX = 2;
	iTopRightOffsetX = 3;
	iBottomLeftOffsetX = 4;
	iBottomRightOffsetX = 5;
  
    fboScale = 2;
    bigScreen.allocate(dimensions.width*fboScale, dimensions.height*fboScale);
    
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	spacingPercent.set("spacingPercent", 1.2, 0, 10);
	spacingPercentX.set("spacingPercentX", 1.2, 0, 10);
	spacingPercentY.set("spacingPercentY", 1.2, 0, 10);
	unifiedSpacing.set("unifiedSpacing", true);
	whiteBackground.set("whiteBackground", false);
	numWide.set("numWide", 40, 1, 100);
	baseSize.set("baseSize", 140, 40, bigScreen.getWidth());
	cornerNoise.set("cornerNoise", 0., 0., 1.);
	centerNoise.set("centerNoise", 0., 0., 1.);
	
	parameters.add(baseSize);
	parameters.add(spacingPercent);
	parameters.add(unifiedSpacing);
	parameters.add(spacingPercentX);
	parameters.add(spacingPercentY);
	//parameters.add(numWide);
	parameters.add(cornerNoise);
	parameters.add(centerNoise);
	parameters.add(whiteBackground);

    setAuthor("Quin Kennedy");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/veraMolnarTrapezium/exampleCode.cpp");
}

void veraMolnarTrapezium::update(){
	if (unifiedSpacing){
		spacingPercentX = spacingPercent;
		spacingPercentY = spacingPercent;
	}
    while(placements.size() < numWide*numWide){
		//centerX, centerY, 
		//topLeftOffsetX, topRightOffsetX,
		//bottomLeftOffsetX, bottomRightOffsetX
		placements.push_back({
			ofRandom(0, 1), 
			ofRandom(0, 1),
			ofRandom(-1, 1),
			ofRandom(-1, 1),
			ofRandom(-1, 1),
			ofRandom(-1, 1)});
	}
}

void veraMolnarTrapezium::draw(){
    bigScreen.begin();
	if (whiteBackground){
		ofBackground(255);
		ofSetColor(0);
	} else {
		ofBackground(0);
		ofSetColor(255);
	}
    ofSetLineWidth(3);
	for(int row = 0; row < numWide; row++){
		for(int column = 0; column < numWide; column++){
			drawTrapezium(row, column);
		}
	}
    bigScreen.end();
    
    bigScreen.draw(0, 0, dimensions.width, dimensions.height);
}

void veraMolnarTrapezium::drawTrapezium(int row, int column){
	float spacingX, spacingY;
	if (unifiedSpacing){
		spacingX = spacingY = baseSize * spacingPercent;
	} else {
		spacingX = baseSize * spacingPercentX;
		spacingY = baseSize * spacingPercentY;
	}
	int index = row * numWide + column;
	float gridLeft = (bigScreen.getWidth() - numWide * spacingX) / 2;
	float gridTop = (bigScreen.getHeight() - numWide * spacingY) / 2;

	float leftmostCenter = gridLeft + spacingX / 2;
	float rightmostCenter = leftmostCenter + (numWide - 1) * spacingX;
	float topmostCenter = gridTop + spacingY / 2;
	float bottommostCenter = topmostCenter + (numWide - 1) * spacingY;

	float startCenterX = leftmostCenter + column * spacingX;
	float startCenterY = topmostCenter + row * spacingY;
	float centerSpanX = (rightmostCenter - leftmostCenter);
	float centerSpanY = (bottommostCenter - topmostCenter);
	float targetCenterX = centerSpanX * placements[index][iCenterX] + leftmostCenter;
	float targetCenterY = centerSpanY * placements[index][iCenterY] + topmostCenter;

	float centerX = 
		startCenterX * (1. - centerNoise) + 
		targetCenterX * centerNoise;
	float centerY = 
		startCenterY * (1. - centerNoise) +
		targetCenterY * centerNoise;

	float top = centerY - baseSize / 2;
	float bottom = centerY + baseSize / 2;
	float left = centerX - baseSize / 2;
	float right = centerX + baseSize / 2;

	float cornerMagnitude = cornerNoise * baseSize;
	ofVec2f topLeft = ofVec2f(top, left);
	topLeft.x += placements[index][iTopLeftOffsetX] * cornerMagnitude;
	ofVec2f topRight = ofVec2f(top, right);
	topRight.x += placements[index][iTopRightOffsetX] * cornerMagnitude;
	ofVec2f bottomRight = ofVec2f(bottom, right);
	bottomRight.x += placements[index][iBottomRightOffsetX] * cornerMagnitude;
	ofVec2f bottomLeft = ofVec2f(bottom, left);
	bottomLeft.x += placements[index][iBottomLeftOffsetX] * cornerMagnitude;

	ofDrawLine(topLeft.x, topLeft.y, topRight.x, topRight.y);
	ofDrawLine(topRight.x, topRight.y, bottomRight.x, bottomRight.y);
	ofDrawLine(bottomRight.x, bottomRight.y, bottomLeft.x, bottomLeft.y);
	ofDrawLine(bottomLeft.x, bottomLeft.y, topLeft.x, topLeft.y);
}
