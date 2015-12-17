void update() {
  for (int j=0; j<[[number-of-group]]; j++) {
    for (int i = 0; i < [[number-of-ball]]; i++) {
      angleofangle[j][i] = - (i-1)*PI/20;
      angle[j][i] = [[speed]] * (5.0*sin((t-0.1) * PI/2.0 - PI/2.0) + 3.0 * angleofangle[j][i]);
    }
  }

}

void draw() {
  for (int j=0; j<[[number-of-group]]; j++) {
    for (int i = 0; i < [[number-of-ball]]; i++) {
      x[j][i] = xorigin + [[rotation-radius]] * -sin(1.0 * (angle[j][i] - PI/2.0));
      y[j][i] = yorigin + [[rotation-radius]] * sin(1.5 * (angle[j][i] - PI/2.0));
    }
  }

  for (int j=0; j<[[number-of-group]]; j++) {
    for (int i = 0; i < [[number-of-ball]]; i++) {
      ofDrawCircle(x[j][i], y[j][i], [[ball-radius]]);
    }
  }
}
