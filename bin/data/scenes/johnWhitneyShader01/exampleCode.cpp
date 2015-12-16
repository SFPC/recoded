void drawPixel(int x, int y) {
  float pinkYVal = sin([[time]] * (x + [[pinkOffset]])) * [[pinkScale]];
  color += PINK * abs(y - pinkYVal);

  float redYVal = sin([[time]] * (x + [[redOffset]])) * [[redScale]];
  color += RED * abs(y - redYVal);

  float yellowYVal = sin([[time]] * (x + [[yellowOffset]])) * [[yellowScale]];
  color += YELLOW * abs(y - yellowYVal);

  setPixelColor(color);
}
