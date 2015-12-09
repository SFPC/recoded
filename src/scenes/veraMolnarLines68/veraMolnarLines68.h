//
// veraMolnarLines68.h
// re-coding of Vera Molnar's simple line works from 1968
// for reference:
//  http://dam.org/artists/phase-one/vera-molnar/artworks-bodies-of-work/works-from-the-1960s-70s
//
// Translated by Quin Kennedy on Dec 8, 2015
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraMolnarLines68 : public baseScene {

public:
	
	struct Square{
		float alpha;
		float targetAlpha;
		float startAlpha;
		float angle;
		float targetAngle;
		float startAngle;
		uint64_t animStartTime;
	};
	vector<vector<Square>> squares;
	vector<int> angleCounts, anglesAddressed;
	vector<float> angleWeights;
	float weightTotal;

	void updateSquare(Square& square);
	void drawSquare(Square& square);
	int getAngleIndex(float angle, float alpha);
	void replaceSquare(Square& square, int myAngleIndex, float percentageMyAngle, float targetPercentMyAngle, float percentageOne, int numSquares);
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
	ofParameter<float> weight0;
	ofParameter<float> weight45;
	ofParameter<float> weight90;
	ofParameter<float> weight135;
	ofParameter<float> weightNone;
	ofParameter<int> numWide;
	ofParameter<float> squareSize;
	ofParameter<bool> squareSizedSpacing;
	ofParameter<float> spacing;
	ofParameter<float> tweenTimeSec;
};
