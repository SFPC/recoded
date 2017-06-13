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

	ofCamera orthoCam;
	int numWide, numHigh;
	ofVec4f zeroVector;
	void drawCube(ofVec4f rotation);
	int getIndexA(int rowNum, int columnNum);
	void drawComposition(int rowNum, int columnNum);
	int foregroundColor, backgroundColor, backgroundHighlightColor, highlightLineWidth;
	vector<ofVec4f> rotations;

public:
    
    void setup();
    void update();
    void draw();
	
    float scale;
    
	ofParameter<float> cubeARotationPercent;
	ofParameter<float> cubeBRotationDiffPercent;
	ofParameter<float> cubeOthersRotationDiffPercent;
	ofParameter<float> scaleParam;
	ofParameter<bool> whiteBackground;
	ofParameter<float> rearLineOpacity;
	ofParameter<float> spacing;
};
