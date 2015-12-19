// Vera Molnar - Hommage à Dürer - 1989/2004
setSquareSize([[Square Size]]);
setGridSize([[Grid Size]]);

void drawVeraLines(){
  if(numberOfLines < [[Number Of Lines]]) {
    drawVeraLines([[columnCounter]], [[rowCounter]])
    increment(currentColumn);
  } else if ([[rowCounter]] < [[gridHeight]]) {
    columnCounter = 0;
    rowCounter++;
  } else {
    rowCounter = 0;
    columnCounter = 0;
  }
}