void rileyCascando::draw() {
    ofScale([[triScale]], [[triScale]]);
    
    bool odd = false;
    for (int y = startY; y < endY; y += TRI_HEIGHT) {
        odd = !odd;
        
        for (int x = startX; x < endX; x += TRI_SIDE_LENGTH) {
            ofPushMatrix();
            
            ofTranslate(x, y);
            
            // Bump us over half a triangle on odd rows
            if (odd)
                ofTranslate(TRI_SIDE_LENGTH / 2.0, 0);
            
            // Add horizontal animation and loop it.
            float time = ofGetElapsedTimef() * [[animSpeed]];
            float xDelta = fmod(time, TRI_SIDE_LENGTH);
            float r = ofNoise((x + time) * (1.0/[[noiseScale]]), y * (1.0/[[noiseScale]]));
            
            if (r < [[pStraight]]) {
                diamondStraightBlack.draw();
                diamondStraightWhite.draw();
            } else if (r < [[pStraight]] + (1.0 - [[pStraight]]) / 2.0) {
                diamondStraightWhite.draw();
                diamondArcBlack.draw();
            } else {
                diamondStraightBlack.draw();
                diamondArcWhite.draw();
            }
            
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    ofDisableAntiAliasing();
}