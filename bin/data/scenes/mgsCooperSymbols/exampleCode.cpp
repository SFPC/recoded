// Muriel Cooper - Cover of 'A Primer Of Visual Literacy'

int numberOfShapes = [[Number of Shapes]];

void mgsCooperSymbols::drawFullGrid(float x, float y) {
  // useRandomStrokeP is a predicate, if it's true, we draw using a random color stroke
  setLineWidth([[Line Width]]);
  if(useRandomStroke == [[Random Colored Stroke]]){
    setRandomStroke();
  } else {
    ofSetColor([[Red Amount]], [[Green Amount]], [[Blue Amount]]);
  }
  float shapeWidth = dimensions.width/shapeSize;
  // We divide the viewspace into a grid of cells sized by the shapeSize parameter
  for(float x = 0; x < dimensions.width+gw; x += shapeWidth){
    for(float y = 0; y < dimensions.height+gh; y += dimensions.height/shapeSize){
      switch((int)ofRandom(1, numberOfShapes+1)) {
        case 1:
          drawSquare(x+shiftCounter, y+rowCounter, gw);
          break;
        case 2:
          drawTri(x+shiftCounter, y+rowCounter, gw);
          break;
        case 3:
          drawCircle(x+shiftCounter+gw/2, y+rowCounter+gh/2, gw/2);
          break;
      }
    }
  }
}