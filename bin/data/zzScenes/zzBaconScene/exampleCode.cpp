// sine wave bacon

ofRotateZ(-45);
ofTranslate(- 6 * (bacon.width + bacon.height),0);

for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 6; j ++){
        float offset = 0;
        float move;
        if(j % 2 == 1) offset = bacon.width/2;
            
            ofPushMatrix();
            ofTranslate(i * (bacon.width + bacon.height) + offset + pos,
                        j * (bacon.height * 2) + 7 * sin(ofGetElapsedTimef()+ i*0.1));
            bacon.draw([[sineAmp]]);
            ofPopMatrix();
            }
    }
}
