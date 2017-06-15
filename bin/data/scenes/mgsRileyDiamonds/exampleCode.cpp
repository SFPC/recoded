void draw(){
  clearScreen();
  for(float x = 0; x < width+gw; x += gw){
    for(float y = 0; y < height+gh; y += gh){
      color c = ofColor(random(0, [[Red Amount]]),
                          random(0, [[Green Amount]]),
                          random(0, [[Blue Amount]]),
                          255);
      color g = color(random(0,255),
                          255);
      
      if([[grayscale]]){
        setColor(g);
        fill();
      } else {
        setColor(c);
        sill();
      }
      beginShape();
      vertex(x-gw, y+gh);
      vertex(x, y+gh);
      vertex(x+gw, y);
      vertex(x, y);
      vertex(x-gw, y+gh);
      endShape(true);
    }
  }
}
