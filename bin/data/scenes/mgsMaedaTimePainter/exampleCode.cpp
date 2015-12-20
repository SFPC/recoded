createPath(currentPainter);

void paintTime(){
  if (longevity < 500) {
    if (ofRandom(10) > 7) {
      angle += ofDegToRad((int)ofRandom(-av, av));
    }
  }
  xpos += cos(angle) / speed;
  ypos += sin(angle) / speed;
  longevity--;
  ofSetColor(stroke);
  ofFill();
  glLineWidth(lineWidth);
  path.begin();
  path.addVertex(ofPoint(xpos, ypos));
  path.end();
  path.draw();
  
  if (longevity == 0) {
    ofDrawEllipse(xpos, ypos, size*2, size*2);
  }
}