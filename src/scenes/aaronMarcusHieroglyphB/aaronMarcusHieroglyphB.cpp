
#include "aaronMarcusHieroglyphB.h"

void aaronMarcusHieroglyphB::setup(){
	glyphWeights = {1, 1, 1, .5, .5, .5, .25};
	numGlyphs = glyphWeights.size();
	totalGlyphWeight = 0;
	for(int i = 0; i < numGlyphs; i++){
		totalGlyphWeight += glyphWeights[i];
	}
	
	prepopulateLines = false;
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
	symbolDensity.set("symbolDensity", .5, 0., 1.);
	lineSpeedMin.set("lineSpeedMin", 100, 0, 1000);
	lineSpeedDelta.set("lineSpeedDelta", 50, 0, 500);
	lineSpacing.set("lineSpacing", 45, 10, 500);
	border.set("border", 20, 0, 500);
	numberLines.set(
		"numberLines", 
		(int)((dimensions.height - border * 2) / lineSpacing), 
		1, 100);
	lineWeight.set("lineWeight", 2, 1, 10);
	horizontalLines.set("horizontalLines", true);
	verticalLines.set("verticalLines", false);

	parameters.add(symbolDensity);
	parameters.add(lineSpeedMin);
	parameters.add(lineSpeedDelta);
	parameters.add(lineSpacing);
	parameters.add(numberLines);
	parameters.add(lineWeight);
	parameters.add(border);
	parameters.add(horizontalLines);
	parameters.add(verticalLines);

	lastFrameMicros = ofGetSystemTimeMicros();
    setAuthor("Quin Kennedy");
    setOriginalArtist("Aaron Marcus");
    loadCode("scenes/aaronMarcusHieroglyphB/exampleCode.cpp");
}

void aaronMarcusHieroglyphB::update(){

	//diagonal lines are 30 degrees off vertical
	// and a short diagonal line spans one "spacing unit"
	defaultSpacing = tan(PI/6) * lineSpacing/4;

	//create lines that may be necessary this frame 
	// (if "numberLines" was increased)
	while(lines.size() < numberLines){
		float speed = lineSpeedMin + ofRandom(lineSpeedDelta);
		//add two for good measure
		int maxNumGlyphs = (int)(dimensions.width / defaultSpacing + 2);
		lines.push_back({
			speed, speed, 
			0,
			0, 0, 
			vector<Glyph>(maxNumGlyphs, {0, true, 0, true})});
		if (prepopulateLines){
			for(int i = 0; i < maxNumGlyphs; i++){
				updateGlyph(lines[lines.size() - 1].glyphs, i);
			}
		}
	}

	//move all the lines based on their speeds
	//using time-based animation
	uint64_t frameMicros = ofGetSystemTimeMicros() - lastFrameMicros;
	lastFrameMicros = ofGetSystemTimeMicros();
	for(int i = 0; i < lines.size(); i++){
		Line& line = lines[i];
		//update speed if it is outside the current range
		if (line.targetSpeed < lineSpeedMin || line.targetSpeed > lineSpeedMin + lineSpeedDelta){
			line.targetSpeed = ofRandom(lineSpeedDelta) + lineSpeedMin;
		}
		//tween current line speed to match target line speed
		line.currSpeed += (line.targetSpeed - line.currSpeed) * .01;
		if (abs(line.currSpeed - line.targetSpeed) < .001){
			line.currSpeed = line.targetSpeed;
		}
		//update the glyph offset for movement
		line.currOffset += (float)(line.currSpeed * frameMicros) / 1000000.;
		int nextGlyphIndex = line.startIndex - 1;
		if (nextGlyphIndex < 0){
			nextGlyphIndex = line.glyphs.size() - 1;
		}
		float nextGlyphSize = 
			getGlyphWidth(line.glyphs[nextGlyphIndex]) + 
			defaultSpacing;
		//if the next glyph now fits on the line
		// lets update indices, and create the next next glyph
        if (line.currOffset > dimensions.width + 30)
            line.currOffset = dimensions.width + 30;

		if(line.currOffset >= nextGlyphSize){
			line.currOffset -= nextGlyphSize;
			line.startIndex = line.endIndex = nextGlyphIndex;
			int nextNextGlyphIndex = nextGlyphIndex - 1;
			if (nextNextGlyphIndex < 0){
				nextNextGlyphIndex = line.glyphs.size() - 1;
			}
			updateGlyph(line.glyphs, nextNextGlyphIndex);
		}
	}	
}

void aaronMarcusHieroglyphB::updateGlyph(vector<Glyph>& glyphs, int index){
	bool populate = ofRandom(1.) < symbolDensity;
	//based on symbol density
	// sometimes just put a blank space in
	if (!populate){
		glyphs[index].id = 0;
		glyphs[index].lowerId = 0;
		return;
	}
	//otherwise, select an appropriate symbol 
	// (which may still be blank)
	float selected = ofRandom(totalGlyphWeight);
	int glyphId = 0;
	selected -= glyphWeights[glyphId];
	while(glyphId < numGlyphs && selected > 0){
		glyphId++;
		selected -= glyphWeights[glyphId];
	}
	if (glyphId >= numGlyphs){
		glyphId = numGlyphs - 1;
		ofLog() << 
			"[updateGlyph] - " <<
			"not sure why we ended up with a glyphId too high";
	}
	
	glyphs[index].id = glyphId;
	glyphs[index].toTheRight = ofRandomf() >= 0;
	switch(glyphs[index].id){
		case 0:
		case 1:
		case 2:
			glyphs[index].lowerId = (int)ofRandom(3);
			glyphs[index].lowerToTheRight = ofRandomf() >= 0;
			break;
	}
}

void aaronMarcusHieroglyphB::draw(){
	ofSetLineWidth(lineWeight);
	ofPushMatrix();
	{
		ofTranslate(border, (dimensions.height - lineSpacing * numberLines + lineSpacing) / 2);
		for(int i = 0; i < numberLines && i < lines.size(); i++){
			drawLine(lines[i]);
			ofTranslate(0, lineSpacing);
		}
	}
	ofPopMatrix();
}

void aaronMarcusHieroglyphB::drawLine(Line line){
	float lineWidth = dimensions.width - border * 2;
	ofPushMatrix();
	{
		ofTranslate(line.currOffset, 0);
		float currOffset = line.currOffset;
		int glyphIndex = line.startIndex;
		while (currOffset <= lineWidth){
			float glyphWidth = getGlyphWidth(line.glyphs[glyphIndex]);
			if (currOffset + glyphWidth <= lineWidth){
				drawSymbol(line.glyphs[glyphIndex]);
			} else {
				break;
			}
			glyphWidth += defaultSpacing;
			currOffset += glyphWidth;
			ofTranslate(glyphWidth, 0);
			glyphIndex = ((glyphIndex + 1) % line.glyphs.size());
			if (glyphIndex == line.endIndex){
				break;
			}
		}
	}
	ofPopMatrix();
	if (horizontalLines){
		ofDrawLine(0, 0, lineWidth, 0);
	}
	if (verticalLines){
		float position = lineSpacing/2;
		while(position <= lineWidth){
			ofDrawLine(position, -lineSpacing/2, position, lineSpacing/2);
			position += lineSpacing;
		}
	}
}

float aaronMarcusHieroglyphB::getGlyphWidth(Glyph glyph){
	switch(glyph.id){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		default:
			return 0;
		case 6:
			return lineSpacing;
	}
}

void aaronMarcusHieroglyphB::drawSymbol(Glyph glyph){
	ofPushMatrix();
	{
		if (!glyph.toTheRight){
			switch(glyph.id){
				case 6:
					//semi-circles are a special case
					// we use toTheRight to encode
					// whether the semi-circle is 
					// above or below the line
					ofScale(1, -1);
					break;
				default:
					ofScale(-1, 1);
					break;
			}
		}
		drawSymbol(glyph.id);
	}
	ofPopMatrix();
	switch(glyph.id){
		case 0:
		case 1:
		case 2:
			ofPushMatrix();
			{
				ofScale(1, -1);
				if (!glyph.lowerToTheRight){
					ofScale(-1, 1);
				}
				drawSymbol(glyph.lowerId);
			}
			ofPopMatrix();
			break;
	}
}
		
void aaronMarcusHieroglyphB::drawSymbol(int glyphId){
	switch(glyphId){
		case 0:
			//blank space
			return;
		case 1:
			//short vertical
			ofDrawLine(0, -lineSpacing/4, 0, 0);
			return;
		case 2:
			//short diagonal
			ofDrawLine(defaultSpacing, -lineSpacing/4, 0, 0);
			return;
		case 3:
			//long vertical
			ofDrawLine(0, -lineSpacing/2, 0, lineSpacing/2);
			return;
		case 4:
			//long diagonal
			ofDrawLine(
				defaultSpacing * 2, -lineSpacing/2, 
				-defaultSpacing * 2, lineSpacing/2);
			return;
		case 5:
			//small circle
			ofDrawCircle(0, -lineSpacing/4, lineSpacing/16);
			return;
		case 6:
			//large arc
			float diameter = lineSpacing;
			float radius = diameter/2.;
			ofGetCurrentRenderer()->getPath().clear();
			ofGetCurrentRenderer()->getPath().arc(
				radius, 0, radius, radius, 180, 360);
    		ofGetCurrentRenderer()->draw(ofGetCurrentRenderer()->getPath());
			return;
	}
}
