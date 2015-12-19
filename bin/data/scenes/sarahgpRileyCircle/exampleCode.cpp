void draw() {
  setBrightness([[brightness]]);

  for (int i = 0; i < [[numCircles]]; i++) {
    scale(i);

    weeArc.moveTo(centerX, centerY - radius);
    weeArc.drawArc(0  - [[angle]], 90  - [[angle]]);
    weeArc.drawArc(92 - [[angle]], 190 - [[angle]]);
    weeArc.drawArc(80 - [[angle]], 260 - [[angle]]);
  }
}
