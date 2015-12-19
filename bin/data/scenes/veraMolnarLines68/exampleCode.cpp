void draw() {
  for (int x = 0; x < [[num_wide]]; x++) {
    for (int y = 0; y < [[num_wide]]; y++) {
      scale([[squareSize]]);

      // Draw randomly, but weight towards different lines
      if (random() < [[weight0]]) {
        drawHorizontallLine();
      } else if (random() < [[weight45]]) {
        drawDiagonalLine(RIGHT);
      } else if (random() < [[weight90]]) {
        drawVerticalLine();
      } else if (random() < [[weight135]]) {
        drawDiagonalLine(LEFT);
      }
    }
  }
}
