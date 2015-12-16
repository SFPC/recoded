void update() {
  float progress = time * [[speed]];
  for (int i=0; i < [[num_points]]; i++) {
    float x = WIDTH / [[num_points]] * i;
    float y = [[animation_height]] *
    sin(progress / [[num_points]] * (i+1));
    Particle p = particles.at(i);
    p.update(x, y);
  }

  setLineLength([[line_max_length]]);
  setLineAlpha([[line_alpha]]);
}
