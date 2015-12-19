
#include "veraMolnarLines68.h"

void veraMolnarLines68::setup(){
	angleCounts = vector<int>(5, 0);
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	weight0.set("weight0", .2, 0, 1);
	weight45.set("weight45", .2, 0, 1);
	weight90.set("weight90", .2, 0, 1);
	weight135.set("weight135", .2, 0, 1);
	weightNone.set("weightNone", .2, 0, 1);
	numWide.set("numWide", 50, 0, 100);
	squareSize.set("squareSize", 23, 14, 50);
	squareSizedSpacing.set("squareSizedSpacing", true);
	spacing.set("spacing", squareSize, 0, 1000);
	tweenTimeSec.set("tweenTimeSec", 1, 0, 10);

	parameters.add(weight0);
	parameters.add(weight45);
	parameters.add(weight90);
	parameters.add(weight135);
	parameters.add(weightNone);
	parameters.add(numWide);
	parameters.add(squareSize);
	//parameters.add(squareSizedSpacing);
	//parameters.add(spacing);
	//parameters.add(tweenTimeSec);

    setAuthor("Quin Kennedy");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/veraMolnarLines68/exampleCode.cpp");
}

void veraMolnarLines68::update(){
	if (squareSizedSpacing){
		spacing = squareSize;
	}

    //make sure we have enough Square data
	for(int i = 0; i < squares.size(); i++){
		while(squares[i].size() < numWide){
			squares[i].push_back({0, 0, 0, 0, 0, 0, 0});
			angleCounts[0]++;
		}
	}
	while(squares.size() < numWide){
		squares.push_back(vector<Square>(numWide, {0, 0, 0, 0, 0, 0, 0}));
		angleCounts[0] += numWide;
	}

	//calculate angle weights
	weightTotal = weight0 + weight45 + weight90 + weight135 + weightNone;
	angleWeights = {weightNone, weight0, weight45, weight90, weight135};
	
	//update any animations
	anglesAddressed = vector<int>(5, 0);
	for(int i = 0; i < squares.size(); i++){
		for(int j = 0; j < squares.size(); j++){
			updateSquare(squares[i][j]);
		}
	}
}

void veraMolnarLines68::updateSquare(Square& square){
	//calculate the current angle position
	uint64_t microsPerSec = 1000000;
	uint64_t tweenTimeMicros = (uint64_t)(tweenTimeSec * microsPerSec);
	uint64_t animEndTime = square.animStartTime + tweenTimeMicros;
	uint64_t currMicros = ofGetSystemTimeMicros();
	if (animEndTime <= currMicros){
		square.angle = square.targetAngle;
		square.alpha = square.targetAlpha;
	} else {
		uint64_t animTime = currMicros - square.animStartTime;
		float linearProgress = (float)(animTime) / (float)(tweenTimeMicros);
		float easedProgress = (cos(linearProgress * PI) + 1) / 2;
		square.angle = 
			square.targetAngle * (1. - easedProgress) + 
			square.startAngle * easedProgress;
		square.alpha = 
			square.targetAlpha * (1. - easedProgress) +
			square.startAlpha * easedProgress;
	}

	//change the target angle if the distributions are off
	int numSquares = squares.size()*squares.size();
	float percentageOne = 1./numSquares;
	int myAngleIndex = getAngleIndex(square.targetAngle, square.targetAlpha);
	int numMyAngle = angleCounts[myAngleIndex];
	float percentageMyAngle = (float)numMyAngle/(float)numSquares;
	float targetPercentMyAngle = angleWeights[myAngleIndex]/weightTotal;
	//if there are too many of my angles
	// lets select a new one to replace it (maybe)
	if (percentageMyAngle - percentageOne > targetPercentMyAngle){
		replaceSquare(square, myAngleIndex, percentageMyAngle, targetPercentMyAngle, percentageOne, numSquares);
	}
	myAngleIndex = getAngleIndex(square.targetAngle, square.targetAlpha);
	anglesAddressed[myAngleIndex]++;
}

void veraMolnarLines68::replaceSquare(Square& square, int myAngleIndex, float percentageMyAngle, float targetPercentMyAngle, float percentageOne, int numSquares){
	//how many of this angle do we need to get rid of?
	int numOver = (int)((percentageMyAngle - targetPercentMyAngle)/percentageOne);
	//how many of this angle have not been handled this frame?
	int numRemaining = angleCounts[myAngleIndex] - anglesAddressed[myAngleIndex];
	//my probability of being changed is
	float probabilityChange = ((float)numOver)/numRemaining;
	//lets see if I get chosen
	if (ofRandom(1) >= probabilityChange){
		//nope
		return;
	}
	
	//now we need to choose a new angle
	// first set up the tween
	square.animStartTime = ofGetSystemTimeMicros();
	square.startAngle = square.angle;
	square.startAlpha = square.alpha;
	// then figure out who needs more squares
	vector<float> currPercentages, targetPercentages;
	vector<int> angleOptions, angleOptions2;
	for(int i = 0; i < 5 ; i++){
		currPercentages.push_back(((float)(angleCounts[i]))/numSquares);
		targetPercentages.push_back(angleWeights[i]/weightTotal);
		if (currPercentages[i] + percentageOne < targetPercentages[i]){
			angleOptions.push_back(i);
		}
		if (currPercentages[i] < targetPercentages[i]){
			angleOptions2.push_back(i);
		}
	}
	if (angleOptions.size() == 0){
		ofLog() << "[replaceSquare] - " << "no other strong angle option";
		angleOptions = angleOptions2;
		if (angleOptions.size() == 0){
			ofLog() << "[replaceSquare] - " << "no other angle options??";
			return;
		}
	}
	
	// now update this square from the options
	angleCounts[myAngleIndex]--;
	int selectedOption = angleOptions[(int)ofRandom(angleOptions.size())];
	angleCounts[selectedOption]++;
	

	if (selectedOption == 0){
		square.targetAlpha = 0;
	} else {
		square.targetAlpha = 255;
		switch(selectedOption){
			case 1:
				square.targetAngle = 0;
				break;
			case 2:
				square.targetAngle = 45;
				break;
			case 3:
				square.targetAngle = 90;
				break;
			case 4:
				square.targetAngle = 135;
				break;
		}
	}
}


int veraMolnarLines68::getAngleIndex(float angle, float alpha){
	if (alpha == 0){
		return 0;
	} else if (angle == 0) {
		return 1;
	} else if (angle == 45) {
		return 2;
	} else if (angle == 90) {
		return 3;
	} else {// if (angle == 135) {
		return 4;
	}
}
void veraMolnarLines68::draw(){
	ofPushMatrix();
	{
		ofTranslate(
			(dimensions.width - spacing * numWide) / 2,
			(dimensions.height - spacing * numWide) / 2);
		for(int i = 0; i < numWide; i++){
			ofPushMatrix();
			for(int j = 0; j < numWide; j++){
				drawSquare(squares[i][j]);
				ofTranslate(0, spacing);
			}
			ofPopMatrix();
			ofTranslate(spacing, 0);
		}
	}
	ofPopMatrix();
}

void veraMolnarLines68::drawSquare(Square& square){
	ofPushMatrix();
	{
		ofTranslate(squareSize/2, squareSize/2);
		float calcAngle = square.angle;
		while(calcAngle > 45){
			calcAngle -= 90;
		}
		calcAngle = abs(calcAngle);
		float calcDistance = tan(ofDegToRad(calcAngle)) * squareSize / 2;
		float x, y;
		if (square.angle <= 45){
			x = squareSize/2;
			y = calcDistance;
		} else if (square.angle <= 90){
			y = squareSize/2;
			x = calcDistance;
		} else if (square.angle <= 135){
			y = squareSize/2;
			x = -calcDistance;
		}
		ofSetColor(255, square.alpha);
		ofDrawLine(x, y, -x, -y);
	}
	ofPopMatrix();
}
