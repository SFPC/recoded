void setup() {
    layer text = createLayer(width, height);
    layer colors = createLayer(width, height);
}

void draw() {
    text.setAlphaMask(colors.getTexture());
    
    float time = getElapsedTime();
    
    int partyStart = 0;
    if (partyMode > 0) {
        partyStart = 127;
    }
    
    for (int i = 0; i < 700; i++){
        ofSetColor( 255 - abs( 255*sin(partyMode*i * 0.1)),
                   partyStart + partyStart * sin(partyMode*i * 0.11),
                   partyStart + partyStart * sin(partyMode*i * 0.12));
        ofDrawCircle(200 + i*2, yPos + xAmp * sin(i*0.03 + time*1.4), radius);
        
    }
    
    text.draw(text_image);
    
    text.drawLayer(0,0);
    colors.drawLayer(0,0);
}
