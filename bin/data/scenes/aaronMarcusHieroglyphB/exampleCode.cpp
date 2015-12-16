void draw() {
  setLineWidth([[lineWeight]]);

  for (int line = 0; line < [[numberLines]]; line++) {
    lineWidth = screenWidth - [[border]] * 2;
    drawLine(lineWidth);

    for (int glyph = 0; glyph < NUM_GLYPHS; glyph++) {
      drawGlyphAtSpeed(glyph, [[lineSpeedMin]]);
      translate(1.0 - [[symbolDensity]]);
    }
  }
}
