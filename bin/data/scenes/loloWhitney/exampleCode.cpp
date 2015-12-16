void draw() {
  for (int i = 0; i < ellipses.size; i++) {
    ellipse = ellipses[i];
    setColor(ellipse.color);
    setRotation(ellipse.rotation);

    setDistortion([[Disort]]);
    setWaveSize([[Wave Size]]);
    scale([[Ellipse Size]]);
    ellipse.draw();
  }
}
