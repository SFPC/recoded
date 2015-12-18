void drawPixel(int x, int y) {
  float offset = time * [[speed]];

  float pinkYVal = sin(offset * (x + [[pinkOffset]])) * [[pinkScale]];
  color += PINK * abs(y - pinkYVal);

  float redYVal = sin(offset * (x + [[redOffset]])) * [[redScale]];
  color += RED * abs(y - redYVal);

  float yellowYVal = sin(offset * (x + [[yellowOffset]])) * [[yellowScale]];
  color += YELLOW * abs(y - yellowYVal);

  setPixelColor(color);
}
