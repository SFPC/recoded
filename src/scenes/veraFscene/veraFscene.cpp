
#include "veraFscene.h"


int numcells = 10;
float sizecell;
float lastValue = 0;

void veraFscene::setup(){
  
    scale.set("scale", 10, 10,400);
    parameters.add(scale);

    loadCode("veraFscene/exampleCode.cpp");
}

void veraFscene::update(){
    
}

void veraFscene::draw(){
    
    
    sizecell = (float)dimensions.height/(float)scale;
    //println("draw vera " + sizecell);
    //background(255);
    //stroke(0);
    
    ofSetColor(255);
    
    
    for (int i = 0; i< sizecell; i++){
        
        for (int j = 0; j< sizecell; j++) {
            ofPushMatrix();
            ofTranslate(i*(scale + 10), j*(scale+10));
            if (ofNoise(i,j, getElapsedTimef())< 0.5) {
                drawf();
            } else {
                drawf2();
            }
            
            ofPopMatrix();
        }
    }
    
}



void veraFscene::drawf()
{
    ofDrawLine(0, 0, 0, scale);
    ofDrawLine(0, 0, scale, 0);
    ofDrawLine(0, scale/2.0, scale, scale/2.0);
}


void veraFscene::drawf2()
{
    ofDrawLine(0, 0, 0, scale);
    ofDrawLine(0, scale, scale, scale);
    ofDrawLine(0, scale/2.0, scale, scale/2.0);
}