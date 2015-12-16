update(){
	if ([[squareSizedSpacing]]){
		[[spacing]] = [[squareSize]];
	}

	weightTotal = [[weight0]] + [[weight45]] + [[weight90]] + [[weight135]] + [[weightNone]];
	angleWeights = {[[weightNone]], [[weight0]], [[weight45]], [[weight90]], [[weight135]]};
	for(column in columns){
		for(square in column){
			updateSquare(square);
		}
	}
}

updateSquare(square){
	if (square.animEnd <= currTime()){
		square.angle = square.targetAngle;
		square.alpha = square.targetAlpha;
	} else {
		animTime = currTime() - square.animStart;
		linearProgress = animTime / [[tweenTimeSec]];
		//ease in/out the tween
		easedProgress = (cos(linearProgress * PI) + 1) / 2;
		square.angle =
			square.targetAngle * (1. - easedProgress) +
			square.startAngle * easedProgress;
		square.alpha =
			square.targetAlpha * (1. - easedProgress) +
			square.startAlpha * easedProgress;
	}

	myAngleIndex = getAngleIndex(square.targetAngle, square.targetAlpha);
	percentAngle = angleCounts[myAngleIndex] / numSquares;
	targetPercentAngle = angleWeights[myAngleIndex] / weightTotal;
	if (percentAngle - percentageOne > targetPercentAngle){
		replaceSquare(square);
	}
}

draw(){
	pushMatrix();
	translate(
		(dimensions.width - [[spacing]] * [[numWide]]) / 2,
		(dimensions.height - [[spacing]] * [[numWide]]) / 2);
	for(column in columns){
		pushMatrix();
		for(square in column){
			drawSquare(square);
			translate(0, [[spacing]]);
		}
		popMatrix();
		translate([[spacing]], 0);
	}
	popMatrix();
}

drawSquare(square){
	pushMatrix();
	translate([[spacing]]/2, [[spacing]]/2);
	x = getX(square.angle);
	y = getY(square.angle);
	setColor(255, square.alpha);
	drawLine(x, y, -x, -y);
	popMatrix();
}
