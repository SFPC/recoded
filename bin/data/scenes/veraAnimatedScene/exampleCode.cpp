void draw() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for(int k = 0; k < numShapes; k++) {
        int centerX = 150 + i * 110;
        int centerY = 150 + j * 110;

        // Add some randomness!
        scale([[size]]);
        rotate(random() * (1.0 - [[smoothing]]));
        translate(random() * (1.0 - [[smoothing]]),
                  random() * (1.0 - [[smoothing]]));
        color(255, [[opacity]]);
        drawRect(centerX, centerY, k);
      }
    }
  }
}
