void drawRileyDiamonds(){
  clearScreen();
  for(float x = 0; x < width+gw; x += gw){
    for(float y = 0; y < height+gh; y += gh){
      ofColor c = ofColor(ofRandom(0, [[Red Amount]]),
                          ofRandom(0, [[Green Amount]]),
                          ofRandom(0, [[Blue Amount]]),
                          255);
      ofColor g = ofColor(ofRandom(0,255),
                          255);
      
      if([[grayscale]]){
        ofSetColor(g);
        ofFill();
      } else {
        ofSetColor(c);
        ofFill();
      }
      ofBeginShape();
      ofVertex(x-gw, y+gh);
      ofVertex(x, y+gh);
      ofVertex(x+gw, y);
      ofVertex(x, y);
      ofVertex(x-gw, y+gh);
      ofEndShape(true);
    }
  }
}