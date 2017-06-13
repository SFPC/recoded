setColor(255, [[Opacity]]);
setLineWidth([[Line Width]]);

draw_circles(centerX, centerY, radius, size, currentIteration) {
  i = 0;
  numCircles = [[Number Of Circles]] * pow(2, currentIteration);
  angleOffset = ellapsedTime * pow(2, currentIteration) * [[Speed]];
  while( i < numCircles ) {
    float angle = 360 * (i/numCircles) + angleOffset;
    if (currentIteration < 2) {
      drawCircles(centerX + [[Radius]]*sin(angle),
                  centerY + [[Radius]]*cos(angle),
                  [[Size]] * [[multiplier]],
                  [[Radius]] / [[multiplier]]),
                  currentIteration + 1);
    } else {
      drawCircle(centerX + radius*sin(angle),
                 centerY + radius*cos(angle),
                 size);
    }

    i = i + 1;
  }
}
