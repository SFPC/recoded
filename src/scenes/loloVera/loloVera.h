#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"


class LineS : public ofVec3f
{
public:
    LineS(){};
    ~LineS(){};
    float   angle;
    float   lon;
};

class loloVera : public baseScene {
    
public:
    
    
    
    
    void setup();
    void update();
    void draw();
    ofParameter<float>  fog_min;
    ofParameter<float>  fog_max;
    ofParameter<float>  z_cam;

    ofParameter<int>    extrude;
    
    ofParameter<float>  lineZVariance;
    ofParameter<float>  rotation;
    
    
    int l_index;
    vector<LineS>   lines;
    float   d_zcam,cam_vel;
    
    
    float   show_original_limit;
    float   show_original_current;
    bool    show_original;
    float   show_original_val;
    float   show_original_d;
    
    
    
};

