
#include "hyojinJohnWhitney.h"

void hyojinJohnWhitney::setup(){
  
    time = 0;
    cirSize = 13;
    sinVal = 2;
    breath = 0;
    
    amount.set("amount", 45, 3, 50);
    speed.set("speed", 0.1, -1.5, 1.5);
    cosine.set("cosine", 8.5, 3, 20);
    
    parameters.add(amount);
    parameters.add(speed);
    parameters.add(cosine);
    
    
    
    setAuthor("Hyojin Yoo");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/hyojinJohnWhitney/exampleCode.cpp");
}

void hyojinJohnWhitney::update(){
    
   
    
}

void hyojinJohnWhitney::draw(){
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofSetCircleResolution(8);
    ofSetColor(100);
    
    time = time + ofGetLastFrameTime()*speed;
    
    
    for(int i = 0; i < amount; i++){
        float x = dimensions.width/2 + 200 * cos((time+i)*cosine);
        float y = dimensions.height/2 + 200 * sin((time+i)*sinVal);
        
        breath =  ofMap(sin(ofGetElapsedTimef()*1.5), -1, 1, 8,15);
        ofDrawCircle(x,y,cirSize*sin(i*0.05)*2.3+cirSize+breath);
    }

}
