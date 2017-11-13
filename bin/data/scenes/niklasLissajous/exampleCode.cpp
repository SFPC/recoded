void lissajous(xIn, yIn, widthIn, heightIn, angleIn){
    
    sinAngle = ofGetElapsedTimef() * [[rotationSpeed]];
    cosAngle = ofGetElapsedTimef() * [[rotationSpeed]] * [[sinAdder]};
    for (int i =0; i < 500; i++) {
        float increment = (float)i * 0.01;
        myLine.addVertex(xOrigin + radius * sin(angleIn + increment * [[rotationSpeed]] * (int) adder + sinAngle),
                         yOrigin + radius * cos(increment * [[rotationSpeed]]));
    }
    myLine.draw();
}

void draw(){
    
    for (int i = 0; i < [[numElement]]; i++) {
        for (int j = 0; j < [[numElement]]; j++) {
            for (int k = 0; k < [[innerCopys]]; k++) {
                
                ofSetColor(240 - k * 10);
                
                lissajous(container.getX() + k * ofMap(sin(ofGetElapsedTimef() * 1.25), -1, 1, -container.getWidth() * 0.025, container.getWidth() * 0.025),
                          container.getY(),
                          container.getWidth(),
                          container.getHeight(),
                          i * 0.25 + (j * 0.5));
            }
        }
    }
}

