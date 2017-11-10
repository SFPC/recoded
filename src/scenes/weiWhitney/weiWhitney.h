#pragma once

#include "ofMain.h"


#include "baseScene.h"



typedef struct {
    
    float     x;
    float     y;
    bool     bBeingDragged;
    bool     bOver;
    float     radius;
    
}draggableVertex;


class weiWhitney : public baseScene{

	public:
		void setup();
		void update();
		void draw();
    
    
    int nCurveVertices;
    draggableVertex curveVertices[7];
    draggableVertex bezierVertices[4];
    
    
		
};
