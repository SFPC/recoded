setCircleResolution(100);

pushMatrix();
translate(WW/2, HH/2);

//egg white
//        ofSetColor(255,150);
int radius = 200;
drawCircle(ofSignedNoise(ofGetElapsedTimef()+10)*[[move]], -HH/14, radius); //upper
drawCircle(ofSignedNoise(ofGetElapsedTimef())*[[move]], HH/14, radius); //lower
drawCircle(-WW/14, ofSignedNoise(ofGetElapsedTimef()+20)*[[move]], radius); //Left
drawCircle(WW/14, ofSignedNoise(ofGetElapsedTimef()+5)*[[move]], radius); //Right

//yellow egg
pushMatrix();
//        ofSetColor(255, 150);
rotateZ([[deg]]*360);
yolk.draw(0, 0, yolk.getWidth()*0.48+sin(ofGetElapsedTimef())*40, yolk.getHeight()*0.48+sin(ofGetElapsedTimef())*40);
popMatrix();

//mouth
pushMatrix();
translate(0, HH/30);
//        rotateZ([[deg]]1b);
rotateZ([[deg]]*360);
mouth.draw(0, 0, mouth.getWidth()*0.48, mouth.getHeight()*0.48);
popMatrix();

//eyes
pushStyle();
setColor(0);
drawCircle(0-WW/18, 0-HH/18, (sin(ofGetElapsedTimef()*5)*3)+10);
drawCircle(0+WW/18, 0-HH/18, (cos(ofGetElapsedTimef()*5)*3)+10);
ofPopStyle();

popMatrix();
