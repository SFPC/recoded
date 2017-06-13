void draw() {
  clearBackground();
  setLineWidth([[lineWidth]]);

  for (int x = 0; x < N_XY; x++) {
    for (int y = 0; y < N_XY; y++) {
      int angle = lineGrid[x][y];

      if (!angle) continue;

      translate(x * X_SIZE, y * Y_SIZE);
      rotate(angle + time * [[rotationSpeed]]);
      drawLine(-[[lineLength]] / 2.0, 0, [[lineLength]] / 2.0, 0);
    }
  }
}
