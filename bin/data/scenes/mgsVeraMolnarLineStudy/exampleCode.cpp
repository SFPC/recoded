setSquareSize([[Square Size]]);
setLineWidth([[Line Width]]);

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