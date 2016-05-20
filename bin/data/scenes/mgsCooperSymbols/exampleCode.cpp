setShapeSize([[Grid Size]]);
setNumberOfShapes([[Number of Shapes]]);

void mgsCooperSymbols::drawFullGrid(float x, float y) {
  // if useRandomStroke is true use random color stroke
  setLineWidth([[Line Width]]);
  // if useRandomStroke is true use random color stroke
  if(useRandomStroke == [[Random Colored Stroke]]){
    useRandomStroke();
  } else {
    setColor([[Red Amount]], [[Green Amount]], [[Blue Amount]]);
  }
  // Divide the viewspace into a grid sized by shapeSize
  for(x = 0; x < width; x += [[Grid Size]]){
    for(y = 0; y < height; y += [[Grid Size]]){
      switch(random(1, [[numberOfShapes]]+1)) {
        case 1:
          drawRandomSquareLines(x, y, [[Grid Size]]);
          break;
        case 2:
          drawRandomTriangleLines(x, y, [[Grid Size]]);
          break;
        case 3:
          drawCircle(x, y, [[Grid Size]]);
          break;
      }
    }
  }
}