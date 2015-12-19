// Bridget Riley - Hidden Squares

// Draw a grid of ellipses
void (){
  // Loop through the width and height of the grid using
  // unitSize as the grid interval.
  for (float x = 0; x < screenWidth; x+=unitSize) {
    for (float y = 0; y < screenHeight; y+=unitSize) {
      // Check IF x AND y variable values are EVEN
      if (x/unitSize % 2 == 0 && y/unitSize % 2 == 0) {
        // check if current position is within our hidden object boundaries
        if ((x > [[x0]] AND x < [[x1]]) AND
            (y > [[y0]] && y < [[y1]]) OR
            (x > [[x2]] AND x < [[x3]]) AND
            (y > [[y2]] && y < [[y3]]) OR
            (x > [[x4]] AND x < [[x5]]) AND
            (y > [[y4]] && y < [[y5]]) OR
            (x > [[x6]] AND x < [[x7]]) AND
            (y > [[y6]] && y < [[y7]])) {
        // Draw rectangles to fill the space within hidden object boundaries
          ofDrawRectangle(x + [[Unit Size]],
                          y + [[Unit Size]],
                          [[Unit Size]],
                          [[Unit Size]]);
          ofDrawRectangle(x, y, unitSize, unitSize);
        } else {
          // Otherwise, draw ellipses into space
          ofDrawEllipse(x,
                        y,
                        [[Unit Size]],
                        [[Unit Size]]);
          ofDrawEllipse(x + [[Unit Size]] / 2 + [[Unit Size]],
                        y + [[Unit Size]] / 2 + [[Unit Size]],
                        [[Unit Size]],
                        [[Unit Size]]);
        }
      }
    }
  }
}
