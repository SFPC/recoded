draw() {
  for (int row = 0; row < [[numWide]]; row++){
    for (int column = 0; column < [[numWide]]; column++){
      drawTrapezium(row, column);
    }
  }
}

drawTrapezium(int row, int column){
  point startCenter = gridCenter(row, column);
  targets myTargets = getTargets[row][column];
  float center =
    startCenter * (1. - [[centerNoise]]) +
    myTargets.center * [[centerNoise]];

  point topLeft = {center.x - [[baseSize]] / 2, center.y - [[baseSize]] / 2};
  point topRight = {center.x + [[baseSize]] / 2, center.y - [[baseSize]] / 2};
  point bottomRight = {center.x + [[baseSize]] / 2, center.y + [[baseSize]] / 2};
  point bottomLeft = {center.x - [[baseSize]] / 2, center.y + [[baseSize]] / 2};

  float cornerMagnitude = [[cornerNoise]] * [[baseSize]];
  topLeft.x += myTargets.topLeft * cornerMagnitude;
  topRight.x += myTargets.topRight * cornerMagnitude;
  bottomRight.x += myTargets.bottomRight * cornerMagnitude;
  bottomLeft.x += myTargets.bottomLeft * cornerMagnitude;

  drawLine(topLeft, topRight);
  drawLine(topRight, bottomRight);
  drawLine(bottomRight, bottomLeft);
  drawLine(bottomLeft, topLeft);
}
