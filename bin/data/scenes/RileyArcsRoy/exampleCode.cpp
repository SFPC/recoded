// default line width
float stripWidth = width/16.0 - minWidth - minSpacing;
//float wide = (1 - [[thinWideRatio]]) * stripWidth;
//float thin = [[thinWideRatio]] * stripWidth;

float top = height * 0.66;
float center = width * 0.5;

// cet starting points
ofVec3f pp[2];
pp[0].set(center, top);
pp[1].set(center, top);

// draw 8 lines
for (int i = 0; i < 8; i++) {
  // setup points for where arcs meet on forward stroke
  ofVec3f p0[3];
  // setup points for where arcs meet on back stroke
  ofVec3f p1[3];
  // forward stroke centers
  ofVec3f c1[3];
  // back stroke centers
  ofVec3f c0[3];
  // radius values
  float r0[3];
  float r1[3];
  // ??? odd number
  int i0 = i*2 -1;
  // ?? even number
  int i1 = i*2;
  
  // set begin points for forward/back strokes
  p0[0].set(i * (minSpacing+minWidth) , top);
  p1[0].set(i * (minSpacing+minWidth) + minWidth , top);

  // set second and third points for forwarc/back strokes
  p0[1] = pp[0];
  p1[1] = pp[0];
  p0[2] = pp[1];
  p1[2] = pp[1];
  
  // set line thickness for first 4 lines
  if(i < 4) {
    p0[1].x -= (1 - [[thinWideRatio]]) * stripWidth;
    p1[1].x -= (1 - [[thinWideRatio]]) * stripWidth * 2;

    p0[2].x += [[thinWideRatio]] * stripWidth;
    p1[2].x += [[thinWideRatio]] * stripWidth * 2;

  // set up line thickness for last 4 lines
  } else {
    p0[1].x -= [[thinWideRatio]] * stripWidth;
    p1[1].x -= [[thinWideRatio]] * stripWidth * 2;

    p0[2].x += (1 - [[thinWideRatio]]) * stripWidth;
    p1[2].x += (1 - [[thinWideRatio]]) * stripWidth * 2;
  }

  // set third point
  p0[3].set(width - p0[0].x, h);
  p1[3].set(width - p1[0].x, h);

  // calculate the center points and radius
  // for each of the arcs (3 of each on the forward
  // stroke, 3 on the back)
  for (int j = 0; j< 3; j++) {
    r0[j] = p0[j].distance(p0[j+1])/2;
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
