
#include "aprilMenkman.h"

void aprilMenkman::setup(){
  

    stretch.set("stretch", 0.234, 0, 100);
    parameters.add(stretch);
    
    Ooo.set("Os", 1, 1, 5);
    parameters.add(Ooo);
    
    setAuthor("April Soetarman");
    setOriginalArtist("Rosa Menkman");
    
    loadCode("scenes/aprilMenkman/exampleCode.cpp");
    
    float fontSize = 60;
    
    font.load("fonts/AlrightSans-Bold.otf", fontSize);
}

void aprilMenkman::update(){
    
    //check
    
    
}

void aprilMenkman::draw(){
    
    ofBackground(0);
    
    string myString = "OH N";
    
    for (int i= 0; i<Ooo; i ++){
        myString += "O";

    }
    
    
    
    ofRectangle rect = font.getStringBoundingBox(myString, 0,0);
    
    float opacity = 100;
    float red = (255, 0, 0);
    float blue = (0, 0, 255);
    float yellow = (255, 255, 0);
//    
//    float height = ;
    float yspace = 2;
    float whymouse = stretch;
    
    for (int i = 0; i < 10; i ++){
        ofPushMatrix();
        //        ofRotateX(90);
        ofTranslate(dimensions.width/5,dimensions.height/4);
        
        ofSetColor(255,255,0,opacity); //yellow
        font.drawString(myString, 0,i*yspace*whymouse);
        
        ofSetColor(255,0,0,opacity); //red
        font.drawString(myString,0 ,i*2*yspace*whymouse);
        
        ofSetColor(0,0,255,opacity); //blue
        font.drawString(myString,0,i*3*yspace*whymouse);
        
        ofPopMatrix();
    }
}
