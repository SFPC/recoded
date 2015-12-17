void drawPixel(int x, int y) {
  // Make it go nuts
  float factor_one = [[time]] * y * sin(y) * [[posY]] / y;
  float factor_two = [[posX]] / x + [[posY]] / y;

  // Tangent looks cool
  float tangent = tan(factor_one / factor_two);

  // Output color
  setPixelBrightness(tangent);
}
