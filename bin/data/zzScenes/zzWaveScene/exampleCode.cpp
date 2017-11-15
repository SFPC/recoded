int colors[] = {0xffceff, 0xffffb8, 0x88b8ff,0xceff9f,0xcea0fe,
                0x55e5e5,0xffe5a0,0x6fff70,0xffa0ce,0xa0ffe4};

ofSetHexColor(0xffceff);
ofFill();
ofDrawRectangle(dimensions);

for (int i =0; i < 8; i++){
    adders[i] += ofGetLastFrameTime() * [[movementScale]] * (i % 2 == 0 ? -1 : 1);
}
//
float h = dimensions.height / 8.0;

for (int i = 7; i >= 0; i--){
    
    ofSetHexColor(colors[i+1]);
    
    float amt = sin(i) * 10 + 20;
    
    float amt2 = sin(i*0.4 + ofGetElapsedTimef()) * 0.2 + 0.8;
    ofMesh m;
    m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for (int j = 0; j < 100; j++){
        float pct = ofMap(j, 0, 99, 0, 1);
        
        
        m.addVertex( ofPoint(pct*dimensions.width, dimensions.height));
        m.addVertex( ofPoint(pct*dimensions.width, (dimensions.height - h*i*[[heightScale]]) + sin(pct*amt +  adders[i]) * (h/2.0)*powf([[heightScale]], 0.3)*amt2));
        
    }
    m.draw();
}
