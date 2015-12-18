void draw() {
  for (int i = 0; i < [[Density]]; i++) {
    float x = [[Amplitude]] * cos([[Lissajous Ratio X]] * i);
    float y = [[Amplitude]] * sin([[Lissajous Ratio Y]] * i);

    drawEmojiAnimated(x, y);
  }
}
