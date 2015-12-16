void draw() {
  setLineWidth([[lineWidth]])
  scale([[zoom]]);

  for (int i = 0; i < numberOfFs; i++) {
    for (int j = 0; j < numberOfFs; j++) {
      translate(i, j);
      addMargin([[margin]]);

      // Sometimes flip the Fs
      if (random() < [[frequency]]) {
        if (random() < 1/3) {
          flipX();
        } else if (random() < 2/3) {
          flipY();
        } else {
          flipX();
          flipY();
        }
      }

      drawF();
    }
  }
}
