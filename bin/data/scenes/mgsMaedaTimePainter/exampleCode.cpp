createPath(currentPainter);

void createTimePainter(){
  if (longevity < 500) {
    angle += random([[Angle Variance]], [[Angle Variance]]));
  }
  
  xpos += cos([[Angle Variance]]) / speed;
  ypos += sin([[Angle Variance]]) / speed;
  
  longevity--;
  
  setColor(stroke);
  ofFill();
  
  glLineWidth(lineWidth);
  
  path.begin();
  path.addVertex(ofPoint(xpos, ypos));
  path.end();
  path.draw();
  
  if (longevity == 0) {
    ellipse(xpos, ypos, size*2, size*2);
  }
}
