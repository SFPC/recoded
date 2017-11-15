// watermelon lock

bg.draw(0,0,dimensions.width, dimensions.height);

ofSetRectMode(OF_RECTMODE_CENTER);

ofTranslate(dimensions.width/2, dimensions.height/2);
for (int i = 0; i < 6; i++){
    ofPushMatrix();
    ofRotateZ( getElapsedTimef() * 40 +  sin(fmod(getElapsedTimef()*(i*0.1 + 1), TWO_PI)) * 300 * [[lockPct]]);
    imgs[i].draw(0,0,dimensions.width, dimensions.height);
    ofPopMatrix();
    
}

ofSetRectMode(OF_RECTMODE_CORNER);
