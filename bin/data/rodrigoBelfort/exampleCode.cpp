void belfort::update() {
    float time = ofGetElapsedTimef();
    
    if (lastLineTime + [[timeBtwnLines]] < time) {
        lastLineTime = time;
        // Copy all the lines down one
        for (int i = BELFORT_ROWS - 1; i >= 1; i--) {
            memcpy(dots[i], dots[i-1], sizeof(int) * BELFORT_COLS);
        }
        
        // Sometimes randomly replace the first line
        if (ofRandomuf() < [[pNewLine]]) {
            for (int i = 0; i < BELFORT_COLS; i++) {
                dots[0][i] = round(ofRandomuf());
            }
        }
    }
}

void belfort::draw(){
    for (int i = 0; i < BELFORT_ROWS; i++) {
        for (int j = 0; j < BELFORT_COLS; j++) {
            if (!dots[i][j]) continue;
            
            ofFill();
            ofSetLineWidth(0);
            ofDrawRectangle(j*(rectSize+paddingSizeX)+WINDOW_PADDING,
                            i*(rectSize+paddingSizeY)+WINDOW_PADDING,
                            rectSize, rectSize);
        }
    }
}
