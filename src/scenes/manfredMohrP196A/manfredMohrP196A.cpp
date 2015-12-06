
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
	cubeARotationX.set("cubeARotationX", 10, 0, 365);
	cubeARotationY.set("cubeARotationY", 20, 0, 365);
	cubeARotationZ.set("cubeARotationZ", 30, 0, 365);
	cubeBRotationX.set("cubeBRotationX", 40, 0, 365);
	cubeBRotationY.set("cubeBRotationY", 50, 0, 365);
	cubeBRotationZ.set("cubeBRotationZ", 60, 0, 365);
	scale.set("scale", 200, 1, 1000);
	whiteBackground.set("whiteBackground", true);
	parameters.add(cubeARotationX);
	parameters.add(cubeARotationY);
	parameters.add(cubeARotationZ);
	parameters.add(cubeBRotationX);
	parameters.add(cubeBRotationY);
	parameters.add(cubeBRotationZ);
	parameters.add(scale);
	parameters.add(whiteBackground);

    loadCode("manfredMohrP196A/exampleCode.cpp");
}

void manfredMohrP196A::update(){
    
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
	if (whiteBackground){
		ofBackground(255);
		ofSetColor(0);
	} else {
		ofSetColor(255);
	}
	ofSetLineWidth(1);
	ofNoFill();
	orthoCam.begin();
	{
		//set appropriate scale
		ofPushMatrix();
		{
			ofScale(scale, scale, scale);
			glEnable(GL_SCISSOR_TEST);  
			{
				//draw cube A
				glScissor(0, 0, dimensions.width, dimensions.height/2);
				drawCube(cubeARotationX, cubeARotationY, cubeARotationZ);

				//draw cube B
				glScissor(
					0, 
					dimensions.height/2, 
					dimensions.width, 
					dimensions.height/2);
				drawCube(cubeBRotationX, cubeBRotationY, cubeBRotationZ);
				
				//draw inner bg
				glScissor(
					(dimensions.width-scale)/2, 
					(dimensions.height-scale)/2,
					scale,
					scale);
				if(whiteBackground){
					ofSetColor(250);
				} else {
					ofSetColor(5);
				}
				ofFill();
				drawCube(0, 0, 0);
				
				if(whiteBackground){
					ofSetColor(0);
				} else {
					ofSetColor(255);
				}
				ofSetLineWidth(3);
				ofNoFill();
				//draw inner cube A
				glScissor(
					(dimensions.width-scale)/2, 
					(dimensions.height-scale)/2,
					scale,
					scale/2);
				drawCube(cubeARotationX, cubeARotationY, cubeARotationZ);

				//draw inner cube B
				glScissor(
					(dimensions.width-scale)/2, 
					dimensions.height/2,
					scale,
					scale/2);
				drawCube(cubeBRotationX, cubeBRotationY, cubeBRotationZ);
			}
			glDisable(GL_SCISSOR_TEST);  
			
			//draw dividing line
			ofSetLineWidth(1);
			ofDrawLine(-1, 0, 1, 0);
		}
		ofPopMatrix();
	}
	orthoCam.end();
}
