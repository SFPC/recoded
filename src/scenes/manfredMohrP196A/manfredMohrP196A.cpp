
#include "manfredMohrP196A.h"

void manfredMohrP196A::setup(){

	zeroVector = ofVec4f(0., 0., 0., 0.);

	orthoCam = ofCamera();
	//Manfred Mohr commonly used an orthographic perspective
	orthoCam.enableOrtho();
	//push out clipping planes so we don't cut off the geometry
	orthoCam.setFarClip(1000);
	orthoCam.setNearClip(-1000);
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	cubeARotationPercent.set("cubeARotationPercent", 0., 0., 1.);
	cubeBRotationDiffPercent.set("cubeBRotationDiffPercent", 0., 0., 1.);
	cubeOthersRotationDiffPercent.set("cubeOthersRotationDiffPercent", 0., 0., 1.);
	scaleParam.set("scale", 0.8, 0, 1);
	whiteBackground.set("whiteBackground", true);
	rearLineOpacity.set("rearLineOpacity", 0, 0, 255);
	//~1.75 spacing is the smallest before overlap starts occuring
	spacing.set("spacing", 2, 1.75, 10);
	parameters.add(cubeARotationPercent);
	parameters.add(cubeBRotationDiffPercent);
	parameters.add(cubeOthersRotationDiffPercent);
	parameters.add(scaleParam);
	parameters.add(whiteBackground);
	parameters.add(rearLineOpacity);
	parameters.add(spacing);

    setAuthor("Quin Kennedy");
    setOriginalArtist("Manfred Mohr");
    loadCode("scenes/manfredMohrP196A/exampleCode.cpp");
}

void manfredMohrP196A::update(){
    scale = ofMap(sqrt(1.0-scaleParam), 1, 0, 10, 200);

	numWide = ceil((float)dimensions.width / scale / spacing);
	if (numWide % 2 == 0){
		numWide++;
	}
	numHigh = ceil((float)dimensions.height / scale / spacing);
	if (numHigh % 2 == 0){
		numHigh++;
	}

	//I want the first 'A' rotation to be significant
	// this will allow the animation to be apparent
	int minRotation = 0;
	if (rotations.size() == 0){
		minRotation = 180;
	}
	while(rotations.size() < (numWide * numHigh * 2)){
		rotations.push_back(ofVec4f(ofRandom(minRotation, 360), ofRandom(180), ofRandom(180), ofRandom(180)));
		minRotation = 0;
	}
}

int manfredMohrP196A::getIndexA(int rowNum, int columnNum){
	int ringNum = max(abs(rowNum), abs(columnNum));
	int startIndex = max(((ringNum-1)*8+1) * 2, 0);
	int ringDiameter = ringNum*2+1;
	int indexAOffset = 0;
	if (rowNum == -ringNum){
		indexAOffset += columnNum + ringDiameter/2;
	} else {
		indexAOffset += ringDiameter - 1;
		if (columnNum == ringNum){
			indexAOffset += rowNum + ringDiameter/2;
		} else {
			indexAOffset += ringDiameter - 1;
			if (rowNum == ringNum){
				indexAOffset += -columnNum + ringDiameter/2;
			} else {
				indexAOffset += ringDiameter - 1;
				indexAOffset += -rowNum + ringDiameter/2;
			}
		}
	}
	indexAOffset *= 2;
	return startIndex + indexAOffset;
}

void manfredMohrP196A::drawComposition(int rowNum, int columnNum){
	float screenSpaceWidth = scale * spacing;
	int screenSpaceBottom = -(int)(rowNum * screenSpaceWidth + screenSpaceWidth/2 - dimensions.height/2.);
	int screenSpaceRight = (int)(columnNum * screenSpaceWidth - screenSpaceWidth/2 + dimensions.width/2.);
	int indexA = getIndexA(rowNum, columnNum);
	int indexB = indexA + 1;
	ofVec4f rotationA, rotationB;
	
	ofVec4f rotationCenterA =
		zeroVector * (1. - cubeARotationPercent) +
		rotations[0] * cubeARotationPercent;
	ofVec4f rotationCenterB =
		rotationCenterA * (1. - cubeBRotationDiffPercent) +
		rotations[1] * cubeBRotationDiffPercent;
	if (rowNum == 0 && columnNum == 0){
		rotationA = rotationCenterA;
		rotationB = rotationCenterB;
	} else {
		rotationA =
			rotationCenterA * (1. - cubeOthersRotationDiffPercent) +
			rotations[indexA] * cubeOthersRotationDiffPercent;
		rotationB =
			rotationCenterB * (1. - cubeOthersRotationDiffPercent) +
			rotations[indexB] * cubeOthersRotationDiffPercent;
	}

	ofPushMatrix();
	{
		ofTranslate(spacing * columnNum, spacing * rowNum, 0);
		ofSetColor(foregroundColor, rearLineOpacity);
		ofDrawLine(0, -spacing/2, 0, spacing/2);
		glEnable(GL_SCISSOR_TEST);  
		{
			//draw cube A
			glScissor(
				screenSpaceRight, 
				screenSpaceBottom, 
				screenSpaceWidth, 
				screenSpaceWidth/2);
			ofSetColor(backgroundColor);
			ofFill();
			drawCube(rotationA);
			ofSetColor(foregroundColor);
			ofNoFill();
			drawCube(rotationA);
	
			//draw cube B
			glScissor(
				screenSpaceRight, 
				screenSpaceBottom + screenSpaceWidth/2, 
				screenSpaceWidth, 
				screenSpaceWidth/2);
			ofSetColor(backgroundColor);
			ofFill();
			drawCube(rotationB);
			ofSetColor(foregroundColor);
			ofNoFill();
			drawCube(rotationB);

			
			//draw inner bg
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)((screenSpaceWidth - scale)/2),
				scale,
				scale);
			ofSetColor(backgroundHighlightColor);
			ofFill();
			drawCube(zeroVector);
			
			ofSetColor(foregroundColor);
			ofSetLineWidth(highlightLineWidth);
			ofNoFill();
			//draw inner cube A
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)((screenSpaceWidth - scale)/2),
				scale,
				scale/2);
			drawCube(rotationA);
	
			//draw inner cube B
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)(screenSpaceWidth/2),
				scale,
				scale/2);
			drawCube(rotationB);

		}
		glDisable(GL_SCISSOR_TEST);  
		
		//draw dividing line
		ofSetLineWidth(1);
		ofDrawLine(-spacing/2, 0, spacing/2, 0);
	}
	ofPopMatrix();
}

void manfredMohrP196A::drawCube(ofVec4f rotation){
	ofPushMatrix();
	{
		ofRotate(rotation[0], rotation[1], rotation[2], rotation[3]);
		//use ofDrawBox instead of an ofBoxPrimitive
		// because the primitive wireframe shows triangles
		// and we don't want lines bisecting the faces
		ofDrawBox(1);
		//cube.drawWireframe();
	}
	ofPopMatrix();
}

void manfredMohrP196A::draw(){
	foregroundColor = whiteBackground ? 0 : 255;
	backgroundColor = whiteBackground ? 255 : 0;
	backgroundHighlightColor = whiteBackground ? 250 : 10;
	highlightLineWidth = 5;
	ofBackground(backgroundColor);
	ofSetColor(foregroundColor);
	ofSetLineWidth(1);
	ofNoFill();

	orthoCam.begin();
	{
		//set appropriate scale
		ofPushMatrix();
		{
			ofScale(scale, scale, scale);
			for(int row = -floor(numHigh/2.); row < ceil(numHigh/2.); row++){
				for(int col = -floor(numWide/2.); col < ceil(numWide/2.); col++){
					drawComposition(row, col);
				}
			}
		}
		ofPopMatrix();
	}
	orthoCam.end();
}
