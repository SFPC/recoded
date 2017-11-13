    ofSetCircleResolution(8);
    ofSetColor(100);

    time = time + ofGetLastFrameTime()*[[speed]];


    for(int i = 0; i < [[amount]]; i++){
        float x = ofGetWidth()/2 + 200 * cos((time+i)*[[cosine]]);
        float y = ofGetHeight()/2 + 200 * sin((time+i)*sinVal);

        breath =  ofMap(sin(ofGetElapsedTimef()*1.5), -1, 1, 8,15);
        ofDrawCircle(x,y,cirSize*sin(i*0.05)*2.3+cirSize+breath);
    }
