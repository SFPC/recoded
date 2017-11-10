
float time = ofGetElapsedTimef();
ofSetColor(ofMap(sin(time*2), -1,1, 0, 255),
           ofMap(sin(time*10), -1,1, 100, 255),
           ofMap(cos(time*4), -1,1, 0, 255));


for (int i = 0; i < count; i++){
    for (int j = 0; j < count; j++){
        float x = ofMap(i + 1, 0, count + 1, 0, MIN(dimensions.width, dimensions.height));
        float y = ofMap(j + 1, 0, count + 1, 0, MIN(dimensions.width, dimensions.height));
        ofBeginShape();
        ofVertex(x + ofRandom(-xOffset, xOffset) + ofMap(sin(time*5), -1, 1, 0, 10), y + ofRandom(-yOffset, yOffset));
        ofVertex(x + ofMap(cos(time) * 2, -1, 1, -0, 0) + ofRandom(-xOffset, xOffset), y + ofMap(cos(time * 10), -1, 1, -10, 10));
        ofVertex(x + ofMap(sin(time), -1, 1, -20, 0) + ofRandom(-xOffset, xOffset), y + ofMap(sin(time * 2) * 2, -1, 1, 0, 10) + ofRandom(-yOffset, yOffset));
        ofVertex(x + ofRandom(-xOffset, xOffset), y + ofMap(cos(time * 20), -1, 1, -10, 0) + ofRandom(-yOffset, yOffset));
        ofEndShape();
    }
}
