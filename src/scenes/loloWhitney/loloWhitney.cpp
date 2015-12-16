
#include "loloWhitney.h"

void loloWhitney::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
    
    ofSetCircleResolution(64);
    
    ellipse_size.set("Ellipse Size",500,2.0,500.0);
    main_speed.set("Main Speed",.03,.001,.1);
    q_insert_vel.set("Queue Insert Speed",1.0,1.0,10.0);
    wave_size.set("Wave Size", 0, 0, 100.0);
    rotation_speed.set("Rotation Val",1.2,1.0,8.0);
    disor_am.set("Disort",0.0,0,6.0);
    
    parameters.add(ellipse_size);
   // parameters.add(main_speed);
   // parameters.add(q_insert_vel);
    parameters.add(wave_size);
    //parameters.add(rotation_speed);
    parameters.add(disor_am);
    
    q_limit = 25;
    main_val = 0.0;
    
    shader_rip.load("scenes/loloWhitney/shaders/vhs_rip.vert", "scenes/loloWhitney/shaders/vhs_rip.frag");
    main_fbo.allocate(VISUALS_WIDTH,VISUALS_HEIGHT);
    main_fbo.begin();
    ofClear(0,0);
    main_fbo.end();
    
    small_fbo.allocate(main_fbo.getWidth()/1, main_fbo.getHeight()/1);
    small_fbo.begin();
    ofClear(0,0);
    small_fbo.end();
    
    shader_rip.load("scenes/loloWhitney/shaders/vhs_rip.vert", "scenes/loloWhitney/shaders/vhs_rip.frag");
    
    setAuthor("Marcelo Armendáriz");
    setOriginalArtist("John Whitney");
    loadCode("scenes/loloWhitney/exampleCode.cpp");
}

void loloWhitney::update(){
    
    
//    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));
    if(ofGetFrameNum() % q_insert_vel == 0)
    {
        
        shader_rip.load("scenes/loloWhitney/shaders/vhs_rip.vert", "scenes/loloWhitney/shaders/vhs_rip.frag");
        
    }
    
    if(ofGetFrameNum() % q_insert_vel == 0){
        q_main_val.insert(q_main_val.begin(), main_val);
        if (q_main_val.size() > q_limit-1) {
            q_main_val.pop_back();
        }
    }
    main_val = (ofGetFrameNum()*main_speed);
    
    main_fbo.begin();
    ofClear(0,0);
    
    ofPushStyle();
    ofSetLineWidth(4);
    
    ofVec2f center (VISUALS_WIDTH/2,VISUALS_HEIGHT/2);

    ofPushMatrix();
    ofTranslate(center.x,center.y);
    ofNoFill();
    for (int i=0; i<q_main_val.size(); i++) {
        //   ofSetColor(255);
        ofFloatColor _color = ofFloatColor(255);
        _color.setHsb(ofMap(i, 0, q_main_val.size(), 0.0, 1.0), 1.0, 1.0);
        float   _size = sin((float)i/q_main_val.size()*PI);
        ofRotateZ(q_main_val.at(i)*rotation_speed);
     //   ofRotateX(q_main_val.at(i)*.095);
        ofSetColor(_color);
        
//        float   _noi = ofNoise(q_main_val.at(i)*.1,ofGetFrameNum()*.01);
//        _noi*=100.0;
        
        float _noi = 0;
        
        ofDrawEllipse(-_noi+cos(q_main_val.at(i)*.2)*100.0, _noi+sin(q_main_val.at(i)*.2)*100.0, _size*ellipse_size/2.0, _size*ellipse_size);
    }
    ofPopMatrix();
    

    ofPopStyle();
    
    main_fbo.end();
    
    small_fbo.begin();
    ofClear(0,0);
    ofSetColor(255);
    main_fbo.draw(0, 0,small_fbo.getWidth(),small_fbo.getHeight());
    small_fbo.end();
    
}

void loloWhitney::draw(){
    
   // ofSetLineWidth(10);
    ofSetColor(255);
    small_fbo.draw(0, 0,VISUALS_WIDTH,VISUALS_HEIGHT);
  
   
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    shader_rip.begin();
    shader_rip.setUniformTexture("tex0", small_fbo, 0);
    shader_rip.setUniform1f("t", getElapsedTimef());
    shader_rip.setUniform1f("t_width", small_fbo.getWidth());
    shader_rip.setUniform1f("t_height", small_fbo.getHeight());
    shader_rip.setUniform1f("wave_am", wave_size);
    shader_rip.setUniform1f("disor", disor_am);
    ofSetColor(255);
    small_fbo.draw(0, 0,VISUALS_WIDTH,VISUALS_HEIGHT);
    
    shader_rip.end();
    ofDisableBlendMode();

    
}
