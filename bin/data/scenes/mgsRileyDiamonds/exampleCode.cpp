void draw(){
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
      vertex(x-gw, y+gh);
      vertex(x, y+gh);
      vertex(x+gw, y);
      vertex(x, y);
      vertex(x-gw, y+gh);
      ofEndShape(true);
    }
  }
}
