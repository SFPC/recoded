createPath(currentPainter);

void paintTime(){
  if (longevity < 500) {
    if (ofRandom(2) > 1) {
      angle += ofDegToRad((int)ofRandom(-[[angleVariance]], [[angleVariance]]));
    }
  }
  xpos += cos([[angleVariance]]) / speed;
  ypos += sin([[angleVariance]]) / speed;
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