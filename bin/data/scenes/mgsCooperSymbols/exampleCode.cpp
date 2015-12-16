void mgsCooperSymbols::drawFullGrid(float x, float y) {
  ofSetColor(0);
  ofFill();
  ofDrawRectangle(x,y,dimensions.width,dimensions.height);
  ofSetColor(255);
  if(randomStrokeP){
    randomStroke();
  }
  ofNoFill();
  for(float x = 0; x < dimensions.width+gw; x += gw){
    for(float y = 0; y < dimensions.width+gh; y += gh){
   
      if (!singleShapesP) {
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
      } else {
        switch(numberOfShapes) {
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
}

