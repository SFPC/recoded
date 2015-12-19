void draw() {
  for (int j = 0; j < [[number-of-group]]; j++) {
    for (int i = 0; i < [[number-of-ball]]; i++) {
      // Lissajous, a product of two sine waves
      float x = [[rotation-radius]] * -sin([[speed]] * time - PI/2.0));
      float y = [[rotation-radius]] *  sin([[speed]] * time - PI/2.0));
      drawCircle(x, y, [[ball-radius]]);
    }
  }
}
