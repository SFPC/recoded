void draw() {
  setLineWidth([[LINE WEIGHT]]);

  for (int line = 0; line < 4; line++) {
    drawLine(line);
    drawRedLine(line);
  }

  if (time > [[UPDATE PATHS]]) {
    randomizePaths([[RANDOM FACTOR]]);
  }

  if (time > [[redSpeed]]) {
    advanceRedDots();
    drawRedLines();
  }
}
