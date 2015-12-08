void veraInterruptions::draw() {
    ofBackground(0);
    ofSetLineWidth([[lineWidth]]);
    
    for (int i = 0; i < N_XY; ++i) {
        for (int j = 0; j < N_XY; ++j) {
            if (!lineGrid[i][j]) continue;
            
            ofPushMatrix();
            
            ofTranslate(i * gridMarginX + gridStartX, j * gridMarginY + gridStartY);
            ofRotate(lineGrid[i][j] + ofGetElapsedTimef() * [[rotationSpeed]]);
            ofDrawLine(-[[lineLength]] / 2.0, 0, [[lineLength]] / 2.0, 0);
            
            ofPopMatrix();
        }
    }
}
