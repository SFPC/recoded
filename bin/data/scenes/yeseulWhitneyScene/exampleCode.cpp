ofPushMatrix();

ofTranslate(x, y);
ofRotate([[angle]]);

ofColor c = ofColor::fromHsb([[color]], 255, 255);
ofSetColor(c);
ofFill();

for (int i=0; i<21*(ceil(numberOfPattern/1.7)); i++){
    for (int j=0; j<120/([[number of pattern]]; j+=[[number of pattern]]){
        ofRotate(PI/[[number of pattern]]*2);
        ofDrawCircle(j*5, j*5, 5/[[number of pattern]]);
    }
}
