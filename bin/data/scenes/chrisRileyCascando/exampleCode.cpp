void draw() {
  scale([[triScale]], [[triScale]]);

  for (int x = startX; x < endX; x++) {
    for (int y = startY; y < endY; y++) {
      translate(x, y);

      // Generate random value from a moving field
      float randomValue = getRandom(x, y, [[noiseScale]]);

      float pBentBlack = [[pStraight]] + (1.0 - [[pStraight]]) / 2.0;
      if (randomValue < [[pStraight]]) {
        drawStraightTriangles();
      } else if (randomValue < pBentBlack) {
        drawBentBlackTriangles();
      } else {
        drawBentWhiteTriangles();
      }
    }
  }
}
