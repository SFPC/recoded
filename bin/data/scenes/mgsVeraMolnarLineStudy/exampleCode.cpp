// An Homage to Vera Molnar
//
gridWidth = [[dimensions.width]]
gridHeight = [[dimensions.height]]
squareSize = [[squareSize]]

columnCounter = [[shiftCounter]]
rowCounter = [[rowCounter]]

if(columnCounter < [[gridWidth]]) {
  drawVeraLines([[columnCounter]], [[rowCounter]])
  columnCounter++;
} else if ([[rowCounter]] < [[gridHeight]]) {
  columnCounter = 0;
  rowCounter++;
} else {
  rowCounter = 0;
  columnCounter = 0;
}
