void draw() {
  scale([[scale]]);
  drawLines();

  for (cube in cubes) {
    translate([[spacing]], [[spacing]]);

    // Double the rotations, double the fun!
    cube.rotate([[cubeARotationPercent]]);
    cube.rotateBottom([[cubeBRotationDiffPercent]]);

    // Don't rotate the middle for this one
    if (!cube.isMiddle()) {
      cube.rotate([[cubeOthersRotationDiffPercent]]);
    }

    cube.draw();
  }
}
