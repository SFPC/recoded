//
// veraMolnarTrapezium.h
// re-coding of Vera Molnar's Trapezium series
// based on pieces published in Computer Graphics and Art
//  volume 3 number 2 in May 1978
// for reference: 
//  http://recodeproject.com/artwork/v3n2unimaginable-images
//  http://recodeproject.com/artwork/v3n2untitled-veramolnar
//
// Translated by Quin Kennedy on Dec 7, 2015
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraMolnarTrapezium : public baseScene {

private:

	void drawTrapezium(int row, int column);
	vector<vector<float>> placements;
	int iCenterX, iCenterY;
	int iTopLeftOffsetX, iTopRightOffsetX;
	int iBottomLeftOffsetX, iBottomRightOffsetX;
    
public:
    
    void setup();
    void update();
    void draw();
    
    int fboScale;
    ofFbo bigScreen;
    
//    ofParameter<float> param;
	ofParameter<float> baseSize;
	ofParameter<float> spacingPercent;
	ofParameter<float> spacingPercentX, spacingPercentY;
	ofParameter<bool> unifiedSpacing;
	ofParameter<bool> whiteBackground;
	ofParameter<int> numWide;
	ofParameter<float> cornerNoise;
	ofParameter<float> centerNoise;
};
