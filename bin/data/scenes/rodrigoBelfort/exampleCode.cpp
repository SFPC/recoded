void update() {
  if (timeSinceLine < [[timeBtwnLines]]) {
    // Copy all the lines down one
    for (int i = ROWS - 1; i >= 1; i--) {
      copyLine(i, i-1);
    }

    // Sometimes randomly replace the first line
    if (random() < [[pNewLine]]) {
      randomLine();
    }
  }
}

void draw(){
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Skip if there's no rectangle to draw
      if (!dots[i][j]) continue;

      ofDrawRectangle(i, j, rectSize);
    }
  }
}
