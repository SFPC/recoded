drawBlackSquare() {
  for (each grid on background) {
    // draw a black square if
    // the random value is smaller than the amountOfSquares value
    if (random(0, 5) < [[amountOfSquares]]) {
      ofDrawRectangle(x, y, unitSize*2, unitSize*2);
    }
    counter++;
  }
}

drawBrickTile() {
  bool b = true;
  for ([[numberOfBricks]]) {
    for (each unit of 4*4 square grid) {
      // switch between white and black color and
      // draw a rectangle with the chosen color
      if (b) {
        fill(0);
      } else {
        fill(255);
      }
      drawRectangle(gridX, gridY, unitSize, unitSize);
      b = !b;
    }
  }
}
