// default line width
//float lineWidth = width/16.0 - minWidth - minSpacing;
//float wide = (1 - [[thinWideRatio]]) * stripWidth;
//float thin = [[thinWideRatio]] * stripWidth;

float top = height * 0.66;
float center = width * 0.5;

// cet starting points
startPoint1.set(center, top);
startPoint2.set(center, top);

// draw 8 lines
for (int i = 0; i < 8; i++) {
  
  // set begin points for forward/back strokes
  outStrokePoint1.set(i * (minSpacing+minWidth) , top);
  backStrokePoint1.set(i * (minSpacing+minWidth) + minWidth , top);

  // set second and third points for forwarc/back strokes
  outStrokePoint2 = startPoint1;
  backStrokePoint2 = startPoint1;
  outStrokePoint3 = startPoint2;
  outStrokePoint3 = startPoint2;
  
  // set line thickness for first 4 lines
  if(i < 4) {
    outStrokePoint2.x -= (1 - [[thinWideRatio]]) * lineWidth;
    backStrokePoint2.x -= (1 - [[thinWideRatio]]) * lineWidth * 2;

    outStrokePoint3.x += [[thinWideRatio]] * lineWidth;
    backStrokePoint3.x += [[thinWideRatio]] * lineWidth * 2;

  // set up line thickness for last 4 lines
  } else {
    outStrokePoint2.x -= [[thinWideRatio]] * stripWidth;
    backStrokePoint2.x -= [[thinWideRatio]] * stripWidth * 2;

    outStrokePoint3.x += (1 - [[thinWideRatio]]) * stripWidth;
    backStrokePoint3.x += (1 - [[thinWideRatio]]) * stripWidth * 2;
  }

  // set third point
  outStrokePoint4.set(width - outStrokePoint1.x, h);
  outStrokePoint4.set(width - backStrokePoint1.x, h);

  // calculate the center points and radius
  // for each of the arcs (3 of each on the forward
  // stroke, 3 on the back)
  for (int j = 0; j< 3; j++) {
    outStrokeRadius[j] = p0[j].distance(p0[j+1])/2;
    r1[j] = p1[j].distance(p1[j+1])/2;

    c0[j] = p0[j].getMiddle(p0[j+1]);
    c1[j] = p1[j].getMiddle(p1[j+1]);
  }

  // move to starting point
  path.moveTo(p0[0]);
  // path.arc(center, radiusX, radiusY, angleBegin, angleEnd
  // draw first arc
  path.arc( c0[0], r0[0], r0[0], 0, 180);
  // draw second arc
  path.arc( c0[1], r0[1], r0[1], 180, 360);
  // draw third arc
  path.arc( c0[2], r0[2], r0[2], 0, 180);
  // draw line where? this must be a tiny line
  path.lineTo(p1[3]);
  // arc back around the other way
  path.arc( c1[2], r1[2], r1[2], 0, 180);
  // second arc around the other way
  path.arc( c1[1], r1[1], r1[1], 180, 360);
  // last arc back around
  path.arc( c1[0], r1[0], r1[0], 0, 180);
  // connect to the starting point
  path.lineTo(p0[0]);
  // done!
  path.close();

  // move starting point over?
  pp[0] = p1[1];
  // move starting point over?
  pp[1] = p1[2];
}
