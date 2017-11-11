#pragma once

#include "ofMain.h"
#include "baseScene.h"

class Guillermo_Whitney_catalogue_1 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<float> speed;
	ofParameter<float> inRad;// = 180;
	ofParameter<float> midRad;// = 360;

	ofParameter<float> numLines;// = 16;

    ofImage img;
	float x, y;
	
//	float phiLines = 2*PI/numLines; //Span between lines centre

};
