void draw() {
  // Change the camera position and rotation
  translateCamera([[CAM_Z_POS]]);
  rotateCamera([[rotation]]);

  // Draw each line at least once...
  for(int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < [[EXTRUDE_LINES]]; j++) {
      line.translate([[lineZVariance]]);
      line.draw();
    }
  }
}
