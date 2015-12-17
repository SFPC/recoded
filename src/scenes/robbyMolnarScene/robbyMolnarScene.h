//
//  triangleScene.hpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class veraRect : public baseScene{
    
public:
    void setup(int numberOfRectangles, float radius);
    void draw(int numRects, float disarray);
    
    veraRect();
    
    int numRectangles;
    float centerX;
    float centerY;
    vector < float > radius;
    vector < float > perturb;
    
    vector < float > an;

    void drawPerturbedRect(float x, float y, float width, float height,
                           float X_PERTURB_TL, float Y_PERTURB_TL,
                           float X_PERTURB_TR, float Y_PERTURB_TR,
                           float X_PERTURB_BR, float Y_PERTURB_BR,
                           float X_PERTURB_BL, float Y_PERTURB_BL);
};

class robbyMolnarScene : public baseScene {
    
    void setup();
    void update();
    void draw();
    
    ofParameter<int> numRectangles;
    ofParameter<float> disarray;
    vector <veraRect> veraRects;
    veraRect vRect;
    
    int bigScreenScale;
    ofFbo bigScreen;
};