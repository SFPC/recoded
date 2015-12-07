#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"


class loloWhitney : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
  
    float         main_val;
    vector<float> q_main_val;
    int           q_limit;
    
    ofParameter<float>  ellipse_size;
    ofParameter<float>  main_speed;
    ofParameter<int>    q_insert_vel;
    ofParameter<float>  wave_size;
    ofParameter<float>  rotation_speed;
    ofParameter<float>  disor_am;

//    ofParameter<float> param;
    
    ofShader      shader_rip;
    ofFbo         main_fbo;
    ofFbo         small_fbo;
    
    
};
