draw() {
  // switch the direction of movement when speedVal gets bigger than 100 or smaller than 0
  if (direction == true) {
    speedVal+=[[speed]]/[[numberOfPatterns]];
  } else {
    speedVal-=[[speed]]/[[numberOfPatterns]];
  }
  if (speedVal*numberOfPatterns>=100 || speedVal*numberOfPatterns<=0) {
    direction != direction;
  }
  // rotate and draw shape
  rotate([[rotation]]);
  drawShape(speedVal);
}

drawShape(float speedVal) {
  // draw 4 arcs
  arc(x1, y1, radius-gap[i], radius-gap[i], -90, 0, 100);
  arc(x2, y2, radius-gap[i], radius-gap[i], 0, 90, 100);
  arc(x3, y3, radius-gap[i], radius-gap[i], 90, 180, 100);
  arc(x4, y4, radius-gap[i], radius-gap[i], 180, 270, 100);
}