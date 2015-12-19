void draw() {
  for (int i = 0; i < [[numberOfLines]]; i++) {
    for (int x = 0; x < screenWidth; x++) {
      // Blue waves
      float blueY = sin([[frequency]] * i + x);

      // Red just a little bit offset
      float redY  = sin([[frequency]] * i + x * offset(i));

      setColor(BLUE);
      drawLine(x, blueY);

      setColor(RED);
      drawLine(x, redY);
    }
  }
}
