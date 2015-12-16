draw(){
	pushMatrix();
	scale([[scale]], [[scale]], [[scale]]);
	for each row{
		for each column{
			drawComposition(row, column);
		}
	}
	popMatrix();
}

drawComposition(int row, int column){
	indexA = getIndexA(row, column);
	indexB = indexA + 1;

	//calculate center cube rotations
	rotationCenterA = 
		zeroVector * (1. - [[cubeARotationPercent]]) +
		rotations[0] * [[cubeARotationPercent]];
	rotationCenterB =
		zeroVector * (1. - [[cubeBRotationDiffPercent]]) +
		rotations[1] * [[cubeBRotationDiffPercent]];
	
	//calculate this particular cube's rotations
	rotationA =
		rotationCenterA * (1. - [[cubeOthersRotationDiffPercent]]) +
		rotations[indexA] * [[cubeOthersRotationDiffPercent]];
	rotationB =
		rotationCenterB * (1. - [[cubeOthersRotationDiffPercent]]) +
		rotations[indexB] * [[cubeOthersRotationDiffPercent]];

	pushMatrix();
	translate([[spacing]] * column, [[spacing]] * row, 0);
	
	//draw background line
	setColor(foregroundColor, [[rearLineOpacity]]);
	drawLine(0, -[[spacing]]/2, 0, [[spacing]]/2);

	//draw cube A
	// restrict drawing to top half of composition
	glScissor(screenSpaceRight, screenSpaceBottom, screenSpaceWidth, screenSpaceHeight/2);
	// draw invisible cube to obscure background line
	setColor(backgroundColor);
	fill();
	drawCube(rotationA);
	// draw wireframe
	setColor(foregroundColor);
	noFill();
	drawCube(rotationA);

	//draw cube B
	// restrict drawing to bottom half of composition
	glScissor(screenSpaceRight, screenSpaceBottom + screenSpaceHeight/2, screenSpaceWidth, screenSpaceHeight/2);
	// draw invisible cube to obscure background line
	setColor(backgroundColor);
	fill();
	drawCube(rotationB);
	// draw wireframe
	setColor(foregroundColor);
	noFill();
	drawCube(rotationB);

	//draw inner bg
	// restrict drawing to center of composition
	glScissor(
		screenSpaceRight + (int)((screenSpaceWidth - [[scale]]) / 2),
		screenSpaceBottom + (int)((screenSpaceWidth - [[scale]]) / 2),
		scale, scale);
	// draw off-color background square
	setColor(backgroundHighlightColor);
	fill();
	drawCube(zeroVector);

	//set up for heavy-weight wireframes
	setLineWidth(highlightLineWidth);

	//draw inner cube A
	// restrict drawing to top half of center of composition
	glScissor(
		screenSpaceRight + (int)((screenSpaceWidth - [[scale]]) / 2),
		screenSpaceBottom + (int)((screenSpaceWidth - [[scale]]) / 2),
		scale, scale/2);
	// draw heavy-weight wireframe
	noFill();
	drawCube(rotationA);

	//draw inner cube B
	// restrict drawing to top half of center of composition
	glScissor(
		screenSpaceRight + (int)((screenSpaceWidth - [[scale]]) / 2),
		screenSpaceBottom + (int)(screenSpaceWidth / 2),
		scale, scale/2);
	// draw heavy-weight wireframe
	noFill();
	drawCube(rotationB);

	//draw foreground dividing line
	setLineWidth(1);
	drawLine(-[[spacing]]/2, 0, [[spacing]]/2, 0);

	popMatrix();
}

drawCube(float4 rotation){
	pushMatrix();
	rotate(rotation);
	drawUnitCube();
	popMatrix();
}
