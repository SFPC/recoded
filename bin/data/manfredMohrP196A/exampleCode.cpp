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
	pushMatrix();
	translate([[spacing]] * column, [[spacing]] * row, 0);
	drawLine(0, -[[spacing]]/2, 0, [[spacing]]/2);
	glScissor(screenSpaceRight, screenSpaceBottom, screenSpaceWidth, screenSpaceHeight/2);
	drawCube([[cubeARotationX]], [[cubeARotationY]], [[cubeARotationZ]]);
	glScissor(screenSpaceRight, screenSpaceBottom + screenSpaceHeight/2, screenSpaceWidth, screenSpaceHeight/2);
	drawCube([[cubeBRotationX]], [[cubeBRotationY]], [[cubeBRotationZ]]);
	popMatrix();
}

drawCube(float rotationX, rotationY, rotationZ){
	pushMatrix();
	rotate(rotationX, rotationY, rotationZ);
	drawUnitCube();
	popMatrix();
}
