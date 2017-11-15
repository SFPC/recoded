// donut wave !

translate(dimensions.width*0.5, dimensions.height*0.5);
scale(0.9, 0.9);
for (int i = 0; i < 100; i+=2){
    pushMatrix();
    translate(sin(i*[[xSpeed]]+ ofGetElapsedTimef()*2.0)*300.0, sin(i*[[ySpeed]]+ getElapsedTimef()*0.9)*300.0);
    
    //ofRotateX(ofGetMouseX());
    rotateZ(i*0.1 + getElapsedTimef()*200);
    scale([[donutScale]], [[donutScale]]);
    images[(int)(getFrameNum()*0.03 + i * 0.1)%images.size()].draw(0,0, 300,300);
    popMatrix();
}

