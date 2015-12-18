void draw() {
  rotate([[speed]]);

  for (point in points) {
    scale([[size]]);

    point.drawLine();
    point.drawHead();

    // Bounce!
    point.bounce();
  }
}
