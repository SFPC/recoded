setUnitSize([[Unit Size]]);

void drawGridOfEllipses(){
  // Loop across screen, unitSize is our grid interval.
  for(x = 0; x < screenWidth; x+=[[Unit Size]]) {
    for(y = 0; y < screenHeight; y+=[[Unit Size]]) {
      // IF x AND y are EVEN
      if (x/[[Unit Size]] % 2 == 0 && y/[[Unit Size]] % 2 == 0) {
        // Is current position inside hidden object boundaries
        if ((x0 > x < x1) AND (y0 > y < y1) OR
            (x2 > x < x3) AND (y2 > y < y3) OR
            (x4 > x < x5) AND (y4 > y < y5) OR
            (x6 > x < x7) AND (y6 > y < y7)) {
        // If inside, draw rectangles
          rectangle(x+[[Unit Size]],y+[[Unit Size]],[[Unit Size]],[[Unit Size]]);
          rectangle(x, y, [[Unit Size]], [[Unit Size]]);
        } else {
          // If outside, draw ellipses
          ellipse(x,y,[[Unit Size]],[[Unit Size]]);
          ellipse(x + [[Unit Size]] / 2 + [[Unit Size]],
                        y + [[Unit Size]] / 2 + [[Unit Size]],
                        [[Unit Size]],
                        [[Unit Size]]);
        }
      }
    }
  }
}
