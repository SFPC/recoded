void ofApp::draw(){
    for (int column=0;column<columns;column++){
        int possibleAngleVariation = calculateAngleRangeForColumn(column);

        for (int row=0;row<rows;row++){
            ofPoint lineStart = calculateStartCoordinates(column, row);

            ofPushMatrix();
            int thickness = midPoint - abs(column - midPoint);
            drawLineWithAngleAndThickness([[minAngle]], [[maxMidpointAngle]], [[thickness]]);
            ofPopMatrix();
        }
    }
}

void ofApp::drawLineWithAngleAndThickness(int minAngle, int maxMidpointAngle, int thickness){
    ofRotateZ(ofRandom([[minAngle]], [[maxMidpointAngle]]));
    scaleLineWidth([[thickness]]);

    ofDrawLine();
}

int ofApp::calculateAngleRangeForColumn(int columnPosition){
    float distanceFromEdge = midPoint - abs(columnPosition - midPoint);

    if(distanceFromEdge == 0) {
        return 0;
    } else {
        int possibleRange = maxMidpointAngle-minAngle;
        return (possibleRange/midPoint)*distanceFromEdge;
    }
}

