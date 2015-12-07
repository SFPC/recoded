
#include "veraMolnarTrapezium.h"

void veraMolnarTrapezium::setup(){

	iCenterX = 0;
	iCenterY = 1;
	iTopLeftOffsetX = 2;
	iTopRightOffsetX = 3;
	iBottomLeftOffsetX = 4;
	iBottomRightOffsetX = 5;
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	baseSize.set("baseSize", 100, 10, dimensions.width);
	spacing.set("spacing", baseSize + 10, 0, dimensions.width/2);
	numWide.set("numWide", 10, 1, 100);
	cornerNoise.set("cornerNoise", 0., 0., 1.);
	centerNoise.set("centerNoise", 0., 0., 1.);
	parameters.add(baseSize);
	parameters.add(spacing);
	parameters.add(numWide);
	parameters.add(cornerNoise);
	parameters.add(centerNoise);

    loadCode("veraMolnarTrapezium/exampleCode.cpp");
}

void veraMolnarTrapezium::update(){
    while(placements.size() < numWide*numWide){
		//centerX, centerY, 
		//topLeftOffsetX, topRightOffsetX,
		//bottomLeftOffsetX, bottomRightOffsetX
		placements.push_back({
			ofRandom(dimensions.width), 
			ofRandom(dimensions.height),
			ofRandom(-1, 1),
			ofRandom(-1, 1),
			ofRandom(-1, 1),
			ofRandom(-1, 1)});
	}
}

void veraMolnarTrapezium::draw(){
	for(int row = 0; row < numWide; row++){
		for(int column = 0; column < numWide; column++){
			drawTrapezium(row, column);
		}
	}
}

void veraMolnarTrapezium::drawTrapezium(int row, int column){
	int index = row * numWide + column;
	float gridLeft = (dimensions.width - numWide * spacing) / 2;
	float centerX =  gridLeft + spacing / 2 + column * spacing;
	centerX =
		centerX * (1. - centerNoise) +
		placements[index][iCenterX] * centerNoise;
	float gridTop = (dimensions.height - numWide * spacing) / 2;
	float centerY = gridTop + spacing / 2 + row * spacing;
	centerY = 
		centerY * (1. - centerNoise) +
		placements[index][iCenterY] * centerNoise;

	float top = centerY - baseSize / 2;
	float bottom = centerY + baseSize / 2;
	float left = centerX - baseSize / 2;
	float right = centerX + baseSize / 2;

	ofVec2f topLeft = ofVec2f(top, left);
	topLeft.x += placements[index][iTopLeftOffsetX] * cornerNoise * baseSize;
	ofVec2f topRight = ofVec2f(top, right);
	topRight.x = placements[index][iTopRightOffsetX] * cornerNoise * baseSize;
	ofVec2f bottomRight = ofVec2f(bottom, right);
	bottomRight.x = placements[index][iBottomRightOffsetX] * cornerNoise * baseSize;
	ofVec2f bottomLeft = ofVec2f(bottom, left);
	bottomLeft.x = placements[index][iBottomLeftOffsetX] * cornerNoise * baseSize;

	ofDrawLine(topLeft.x, topLeft.y, topRight.x, topRight.y);
	ofDrawLine(topRight.x, topRight.y, bottomRight.x, bottomRight.y);
	ofDrawLine(bottomRight.x, bottomRight.y, bottomLeft.x, bottomLeft.y);
	ofDrawLine(bottomLeft.x, bottomLeft.y, topLeft.x, topLeft.y);
}
