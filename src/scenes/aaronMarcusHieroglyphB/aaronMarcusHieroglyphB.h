//
// aaronMarcusHieroglyphB.h
// re-coding of Aaron Marcus' Hieroglyphs Series
// based on pieces published in Computer Graphics and Art
//  volume 3 number 2 in May 1978
// for reference:
//  http://recodeproject.com/artwork/v3n2untitled-3-marcus
//  http://recodeproject.com/artwork/v3n2untitled-marcus1
//  http://recodeproject.com/artwork/v3n2untitled-2-marcus
//
// Translated by Quin Kennedy on Dec 7, 2015
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class aaronMarcusHieroglyphB : public baseScene {

private:

	struct Glyph{
		int id;
		bool toTheRight;
		int lowerId;
		bool lowerToTheRight;
	};

	struct Line{
		float targetSpeed, currSpeed;
		float currOffset;
		int startIndex, endIndex;
		vector<Glyph> glyphs;
	};

	//used to control whether lines are created with symbols
	// or are created blank
	bool prepopulateLines;
	float defaultSpacing;
	int numGlyphs;
	vector<float> glyphWeights;
	float totalGlyphWeight;
	vector<Line> lines;
	void updateGlyph(vector<Glyph>& glyphs, int index);
	void drawLine(Line line);
	float getGlyphWidth(Glyph glyph);
	void drawSymbol(Glyph id);
	void drawSymbol(int glyphId);
	uint64_t lastFrameMicros;
    
public:
    
    void setup();
    void update();
    void draw();
    
//    ofParameter<float> param;
	ofParameter<float> symbolDensity;
	ofParameter<float> lineSpeedMin;
	ofParameter<float> lineSpeedDelta;
	ofParameter<float> lineSpacing;
	ofParameter<int> numberLines;
	ofParameter<int> lineWeight;
	ofParameter<float> border;
	ofParameter<bool> horizontalLines;
	ofParameter<bool> verticalLines;
	ofParameter<float> allowedVerticalOffset;

};
