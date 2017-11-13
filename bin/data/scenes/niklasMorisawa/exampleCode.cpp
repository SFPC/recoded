for (int i = 0; i < 9 ; i++) {
    float numElements ;
    if(numElements < 6){
        numElements += 1;
    }    if(numElements > 6){
        numElements /= 2;
    }
    
    float grid = width / numElements;
    float scale = grid / myText.bound1.getWidth();
    
    float x = 0;
    
    for (int j = 0; j < numElements; j++) {
        counter += 1;
        
        ofPushMatrix();
        // position in grid
        ofTranslate(x , y);
        
        //align top and left
        ofTranslate(scale * myText.bound1.getWidth() * 0.5,
                    scale * (myText.bound1.getHeight()*1.1) * 0.5);
        
        //draw from center and scale
        ofScale(scale, scale);
        ofTranslate(-myText.bound1.getWidth() * 0.5, -(myText.bound1.getHeight()*1.1) * 0.5);
        
        if([[pattern]] == 1){
            myText.draw(counter % 2);
        }
        if(counter % [[pattern]] == 1 {
            myText.draw(counter % 2);
        }
        ofPopMatrix();
        x += scale * myText.bound1.getWidth();
    }
    y += scale * (myText.bound1.getHeight()*1.1);
    totalHeight += (myText.bound1.getHeight()*1.1) * scale;
    
    
}

}
