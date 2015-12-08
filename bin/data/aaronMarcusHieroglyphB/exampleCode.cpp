update(){
	defaultSpacing = tan(PI/6) + [[lineSpacing]]/4;
	
	//moveLines
	for(line in lines){
		line.currSpeed += (line.targetSpeed - line.currSpeed) * .01;
		line.currOffset += line.currSpeed * frameTimeSeconds;
		int nextGlyphIndex = line.startIndex - 1;
		if (line.currOffset >= line.glyphs[nextGlyphIndex].width){
			line.currOffset -= line.glyphs[nextGlyphIndex].width;
			line.startIndex--;
			line.glyph[line.startIndex - 1] = randomGlyph();
		}
	}
}

draw(){
	setLineWidth([[lineWeight]]);
	pushMatrix();
	translate([[border]], (dimensions.height - [[lineSpacing]] * [[numberLines]] + [[lineSpacing]]) / 2);
	for(line in lines){
		drawLine(line);
		translate(0, [[lineSpacing]]);
	}
	popMatrix();	
}

drawLine(line){
	lineWidth = dimensions.width - [[border]] * 2;
	pushMatrix();
	translate(line.currOffset, 0);
	int currOffset = line.currOffset;
	int index = line.startIndex;
	while(currOffset <= lineWidth){
		if (currOffset + line.glyphs[index].width > lineWidth){
			break;
		}
		drawGlyph(line.glyphs[index]);
		currOffset += line.glyphs[index].width + defaultSpacing;
		ofTranslate(line.glyphs[index].width + defaultSpacing);
		glyphIndex++;
	}
	popMatrix();
	
	if ([[horizontalLines]]){
		drawLine(0, 0, lineWidth, 0);
	}
	if ([[vericalLines]]){
		float position = [[lineSpacing]] / 2;
		while (position <= lineWidth){
			drawLine(position, -[[lineSpacing]]/2, position, [[lineSpacing]]/2);
			position += [[lineSpacing]];
		}
	}
}
