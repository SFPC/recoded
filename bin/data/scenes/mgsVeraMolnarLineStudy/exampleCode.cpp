setSquareSize([[Square Size]]);
setLineWidth(1);

void drawVeraLines(){
  if(numberOfLines < [[Number of Lines]]) {
    drawRandomVeraLines(currentColumn, currentRow)
    incrementCurrentColumn();
  } else if ([[rowCounter]] < [[gridHeight]]) {
    columnCounter = 0;
    incrementCurrentRow();
  } else {
    rowCounter = 0;
    columnCounter = 0;
  }
}