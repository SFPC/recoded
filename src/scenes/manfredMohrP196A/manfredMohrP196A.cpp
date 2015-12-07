
#include "manfredMohrP196A.h"

void manfredMohrP196A::setup(){

	cube = ofBoxPrimitive(1, 1, 1, 1, 1, 1);
	cube.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	
	orthoCam = ofCamera();
	//Manfred Mohr commonly used an orthographic perspective
	orthoCam.enableOrtho();
	//push out clipping planes so we don't cut off the geometry
	orthoCam.setFarClip(1000);
	orthoCam.setNearClip(-1000);
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	cubeARotationX.set("cubeARotationX", 10, 0, 360);
	cubeARotationY.set("cubeARotationY", 20, 0, 360);
	cubeARotationZ.set("cubeARotationZ", 30, 0, 360);
	cubeBRotationX.set("cubeBRotationX", 40, 0, 360);
	cubeBRotationY.set("cubeBRotationY", 50, 0, 360);
	cubeBRotationZ.set("cubeBRotationZ", 60, 0, 360);
	scale.set("scale", 200, 10, 1000);
	whiteBackground.set("whiteBackground", true);
	rearLineOpacity.set("rearLineOpacity", 0, 0, 255);
	spacing.set("spacing", 2, 1, 10);
	parameters.add(cubeARotationX);
	parameters.add(cubeARotationY);
	parameters.add(cubeARotationZ);
	parameters.add(cubeBRotationX);
	parameters.add(cubeBRotationY);
	parameters.add(cubeBRotationZ);
	parameters.add(scale);
	parameters.add(whiteBackground);
	parameters.add(rearLineOpacity);
	parameters.add(spacing);

    loadCode("manfredMohrP196A/exampleCode.cpp");
}

void manfredMohrP196A::update(){
    
}

void manfredMohrP196A::drawComposition(int rowNum, int columnNum){
	float screenSpaceWidth = scale * spacing;
	int screenSpaceBottom = -(int)(rowNum * screenSpaceWidth + screenSpaceWidth/2 - dimensions.height/2.);
	int screenSpaceRight = (int)(columnNum * screenSpaceWidth - screenSpaceWidth/2 + dimensions.width/2.);

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
			drawCube(cubeARotationX, cubeARotationY, cubeARotationZ);
			ofSetColor(foregroundColor);
			ofNoFill();
			drawCube(cubeARotationX, cubeARotationY, cubeARotationZ);
	
			//draw cube B
			glScissor(
				screenSpaceRight, 
				screenSpaceBottom + screenSpaceWidth/2, 
				screenSpaceWidth, 
				screenSpaceWidth/2);
			ofSetColor(backgroundColor);
			ofFill();
			drawCube(cubeBRotationX, cubeBRotationY, cubeBRotationZ);
			ofSetColor(foregroundColor);
			ofNoFill();
			drawCube(cubeBRotationX, cubeBRotationY, cubeBRotationZ);

			
			//draw inner bg
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)((screenSpaceWidth - scale)/2),
				scale,
				scale);
			ofSetColor(backgroundHighlightColor);
			ofFill();
			drawCube(0, 0, 0);
			
			ofSetColor(foregroundColor);
			ofSetLineWidth(highlightLineWidth);
			ofNoFill();
			//draw inner cube A
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)((screenSpaceWidth - scale)/2),
				scale,
				scale/2);
			drawCube(cubeARotationX, cubeARotationY, cubeARotationZ);
	
			//draw inner cube B
			glScissor(
				screenSpaceRight + (int)((screenSpaceWidth - scale)/2),
				screenSpaceBottom + (int)(screenSpaceWidth/2),
				scale,
				scale/2);
			drawCube(cubeBRotationX, cubeBRotationY, cubeBRotationZ);

		}
		glDisable(GL_SCISSOR_TEST);  
		
		//draw dividing line
		ofSetLineWidth(1);
		ofDrawLine(-spacing/2, 0, spacing/2, 0);
	}
	ofPopMatrix();
}

void manfredMohrP196A::drawCube(float rotX, float rotY, float rotZ){
	ofPushMatrix();
	{
		ofRotateX(rotX);
		ofRotateY(rotY);
		ofRotateZ(rotZ);
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
			int numWide = ceil((float)dimensions.width / scale / spacing);
			if (numWide % 2 == 0){
				numWide++;
			}
			int numHigh = ceil((float)dimensions.height / scale / spacing);
			if (numHigh % 2 == 0){
				numHigh++;
			}
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
