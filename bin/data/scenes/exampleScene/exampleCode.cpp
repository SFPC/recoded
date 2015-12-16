ofSetRectMode(OF_RECTMODE_CENTER);
ofPushMatrix();

ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
ofRotate([[angle]]);
ofDrawRectangle(0, 0, [[width]], 40);

ofPopMatrix();
ofSetRectMode(OF_RECTMODE_CORNER);
