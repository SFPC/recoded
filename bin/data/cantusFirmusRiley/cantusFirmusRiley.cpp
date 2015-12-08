void setup(){
    for (int i = 0; i <= size; i++){
        if(i == size/2) stripes.push_back(w);
        
        else if(abs(i-size/2)% 8 == 1) stripes.push_back(y);
        else if(abs(i-size/2)% 8 == 2) stripes.push_back(p);
        else if(abs(i-size/2)% 8 == 3) stripes.push_back(b);
        
        else if(abs(i-size/2)% 8 == 5) stripes.push_back(b);
        else if(abs(i-size/2)% 8 == 6) stripes.push_back(p);
        else if(abs(i-size/2)% 8 == 7) stripes.push_back(y);
        
        else if(abs(i-size/2)%12 == 0) stripes.push_back(w);
        else if(abs(i-size/2)%12 == 4) stripes.push_back(g);
        else if(abs(i-size/2)%12 == 8) stripes.push_back(k);
    }
}


void draw(){
    //midline
    stripes[size/2].x = -stripes[size/2].width/2;
    ofSetColor(stripes[size/2].c);
    ofDrawRectangle(stripes[size/2].x, 0, stripes[size/2].width, ofGetWidth()*2);

    //stripes on the left
    for (int i = (size/2)-1; i> 0; i--){
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i+1].x - stripes[i].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, ofGetHeight()*2);
    }

    //stripes on the right
    for (int i = (size/2)+1; i< stripes.size();i++) {
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i-1].x + stripes[i-1].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, ofGetHeight()*2);
    }
}