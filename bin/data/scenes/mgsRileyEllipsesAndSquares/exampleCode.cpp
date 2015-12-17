// Bridget Riley - Hidden Squares
for (float x = 0; x < dimensions.width; x+=unitSize) {
  for (float y = 0; y < dimensions.height; y+=unitSize) {
    if (x/unitSize % 2 == 0 && y/unitSize % 2 == 0) {
      if ((x > px0 && x < px1 && y > py0 && y < py1)  ||
          (x > px2 && x < px3 && y > py2 && y < py3)  ||
          (x > px4 && x < px5 && y > py4 && y < py5)  ||
          (x > px6 && x < px7 && y > py6 && y < py7)) {
        ofDrawRectangle(x+unitSize, y+unitSize, unitSize, unitSize);
        ofDrawRectangle(x, y, unitSize, unitSize);
      } else { 
        ofDrawEllipse(x+unitSize/2, y+unitSize/2, unitSize, unitSize);
        ofDrawEllipse(x+unitSize/2+unitSize, y+unitSize/2+unitSize, unitSize, unitSize);
      }
    }      
  }
}