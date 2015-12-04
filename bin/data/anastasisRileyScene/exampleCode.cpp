for (int i = 0; j < numberOfLines; i++) {
    float alpha = MAX_ALPHA*(1-abs(peakRedLine-j)/float(peakRedLine));
    for (int j = 0; j < dimensions.width; j++) {
        float y = i*LINE_DISTANCE+sin(j*[[frequency]]-i*PI/8)*LINE_DISTANCE;
        float thickness = abs(sin(j*[[frequency]]*0.5-i*PI/16)*(MAX_THICKNESS-MIN_THICKNESS))+MIN_THICKNESS;
        ofSetColor(77, 72, 104);
        ofDrawRectangle(j, y, 1, thickness);
        ofSetColor(255, 0, 0, alpha*255);
        ofDrawRectangle(j, y, 1, thickness/2);
    }
}
