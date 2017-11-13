
for (int layer = 0; layer < burger.size(); i++) {
    
    image burgerLayer = burger[i];
    
    float xOffset = [[xAmp]] * sin(xTime + layer);
    float yOffset = [[yAmp]] * cos(yTime + layer);
    
    burgerLayer.translate(xOffset, yOffset);
    
    burgerLayer.draw();
    
}

xTime += xFreq;
yTime += yFreq;
