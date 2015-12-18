void drawPixel(int x, int y) {
  float centerDistance = distanceFromCenter(x, y);
  float zoom = [[speed]] * time;

  // Three colors, offset just slightly
  float color1 = cos((centerDistance - 0.3) * zoom);
  float color2 = cos((centerDistance - 0.4) * zoom);
  float color3 = cos((centerDistance - 0.5) * zoom);

  setThickness([[thickness]]);

  // Mix the colors equally, then draw
  drawPixelColor(mix(color1, color2, color3));
}
