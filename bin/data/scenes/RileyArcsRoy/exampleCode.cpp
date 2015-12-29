// draw 8 lines
for (int i = 0; i < 8; i++) {
  // the first 3 points are one side of the stroke,
  // the second 3 are the other side
  points[0].set(i * (minSpacing+minWidth), top);
  points[3].set(i * (minSpacing+minWidth) + minWidth, top);
  // set line thickness for first 4 lines
  if(i < 4) {
    points[1].x -= (1 - [[thinWideRatio]]) * lineWidth;
    points[4].x -= (1 - [[thinWideRatio]]) * lineWidth * 2;
    points[2].x += [[thinWideRatio]] * lineWidth;
    points[5].x += [[thinWideRatio]] * lineWidth * 2;
  // set up line thickness for last 4 lines
  } else {
    points[1].x -= [[thinWideRatio]] * lineWidth;
    points[4].x -= [[thinWideRatio]] * lineWidth * 2;
    outPoints[2].x += (1 - [[thinWideRatio]]) * lineWidth;
    backPoints[5].x += (1 - [[thinWideRatio]]) * lineWidth * 2;
  }
  points[3].set(width - points[0].x, h);
  points[6].set(width - points[3].x, h);
  
  drawLine(points);
}

// draw the line!
drawLine(points) {
  for (int j = 0; j < 6; j++) {
    radii[j] = points[j].distance(points[j+1])/2;
    centers[j] = points[j].getMiddle(points[j+1]);
  }
  // draw one side of line
  path.moveTo(points[0]);
  path.arc(centers[0], radii[0], radii[0], 0, 180);
  path.arc(centers[1], radii[1], radii[1], 180, 360);
  path.arc(centers[2], radii[2], radii[2], 0, 180);
  // draw other side of line
  path.arc(centers[3], radii[3], radii[3], 0, 180);
  path.arc(centers[4], radii[4], radii[4], 180, 360);
  path.arc(centers[5], radii[5], radii[5], 0, 180);
  path.lineTo(points[0]);
}

