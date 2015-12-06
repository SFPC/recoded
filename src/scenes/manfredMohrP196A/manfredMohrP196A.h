//
// manfredMohrP196A.h
// re-coding of Manfred Mohr's piece P196A
// published in Computer Graphics and Art volume 3 number 1 in February 1978
// for reference: http://recodeproject.com/artwork/v3n1p196a
// 
// Created by Quin Kennedy on Dec 6, 2015
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class manfredMohrP196A : public baseScene {

private:

	ofBoxPrimitive cube;
	ofCamera orthoCam;
	void drawCube(float rotX, float rotY, float rotZ);

public:
    
    void setup();
    void update();
    void draw();
	
	ofParameter<float> cubeARotationX, cubeARotationY, cubeARotationZ;
	ofParameter<float> cubeBRotationX, cubeBRotationY, cubeBRotationZ;
	ofParameter<float> scale;
	ofParameter<bool> whiteBackground;
	
    
//    ofParameter<float> param;
};
