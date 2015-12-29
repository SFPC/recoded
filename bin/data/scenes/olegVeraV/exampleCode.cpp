void draw() {
  for (int k = 0; k < [[elementsAmount]]; k++) {
    // Make the Vs breathe
    scaleWithHeartbeat();

    // Draw a V with a set thickness
    setThickness([[thickness]]);
    drawV();

    // Move to the next V by a certain percent
    translate([[thicknessMultiplier]]);
  }
}
