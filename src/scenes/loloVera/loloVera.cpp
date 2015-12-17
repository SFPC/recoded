
#include "loloVera.h"

void loloVera::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
    
    
    fog_min.set("Fog min",200.0,0.0,2048.0);
    fog_max.set("Fog max",600.0,0.0,2048.0);
    extrude.set("EXTRUDE_LINES",1,1,20);
    z_cam.set("CAM_Z_POS",0.0,-500.0,860.0);
    parameters.add(z_cam);
  //  parameters.add(fog_max);
    parameters.add(extrude);
    
    lineZVariance.set("lineZVariance", 0, 0, 1);
    parameters.add(lineZVariance);
    rotation.set("rotation", 0, 0, 1);
    parameters.add(rotation);
    
     float z = ofRandom(-500,500);
    
    for(int i=0;i<300;i++)
    {
        LineS   line = LineS();
        line.angle = ofDegToRad(((int)ofRandom(0,3))*90.0);
        line.lon = ofRandom(20,100);
        
        if(ofRandom(100) > 90)
        {
            z = ofRandom(-500,500);
        }
        
        line.set(ofRandom(-VISUALS_WIDTH/4,VISUALS_WIDTH/4), ofRandom(-VISUALS_HEIGHT/4,VISUALS_HEIGHT/4),z);
        lines.push_back(line);
    }
    
//    l_index = (int) ofRandom(0,lines.size()-1);
    
    

    
    show_original_current = ofGetElapsedTimef();
    show_original_limit = ofRandom(1,3);
    show_original = true;
    show_original_val = 0.0;

    setAuthor("Marcelo Armendáriz");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/loloVera/exampleCode.cpp");
}

void loloVera::update(){
    
//    if(fabs(show_original_current-ofGetElapsedTimef()) > show_original_limit)
//    {
//        show_original = !show_original;
//        
//        if(show_original)
//        {
//            show_original_limit = ofRandom(1,3);
//
//        }else{
//            show_original_limit = ofRandom(5,20);
//            extrude = ofRandom(1,20);
//
//        }
//        show_original_current = ofGetElapsedTimef();
//
//    }
    
    
    
//    if(ofGetFrameNum() % 20 == 0)
//    {
//        
//        l_index =(int) ofRandom(0,lines.size()-1);
//        
//    }
    
    
//    if(ofGetFrameNum() % 30 == 0)
//    {
//       
//        d_zcam+=ofRandom(-500,500);
//    }
//    if(show_original)
//    {
//        show_original_d = 1.0;
//        d_zcam = 0.0;
//    }else{
//        show_original_d = 0.0;
//    }
//
//    cam_vel+=(d_zcam-z_cam)*.015;
//    cam_vel*=.8;
//    z_cam+=cam_vel;
//    show_original_val+=(show_original_d-show_original_val)*.1;
//    
    
    
}

void loloVera::draw(){
    

    ofPushStyle();
    ofSetLineWidth(2);
    ofEnableDepthTest();
    
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    GLfloat fogColor[4]= {0, 0, 0, 1.0};
    glFogfv(GL_FOG_COLOR, fogColor);
    glHint(GL_FOG_HINT, GL_FASTEST);
    glFogf(GL_FOG_START, fog_min);
    glFogf(GL_FOG_END, fog_max);

    
    ofPushMatrix();
    
    //z_cam = ofClamp(z_cam, 0, 800.0);
    
    ofTranslate(VISUALS_WIDTH/2,VISUALS_HEIGHT/2,z_cam);
    ofRotate(rotation * 90, 1, 0, 0);

//    ofRotateZ(cameraZ);
    //ofRotateY(cam_vel+(ofGetFrameNum()*.1)*(1.0-show_original_val));
    //ofRotateZ(-z_cam);
    //ofRotateX(z_cam*0.999);
    
    for(int i=0;i<lines.size();i++)
    {
       // if(abs(l_index-i) < 20){
        
        int _e_limit = extrude;//*(1.0-show_original_val);
        float _l_z = ofMap(lineZVariance, 1.0, 0.0, lines.at(i).z, 200.0);
        
        for(int e=0;e<_e_limit;e++){
            ofPushMatrix();
            ofTranslate(lines.at(i).x, lines.at(i).y,_l_z+(e*(4.0)));
            
            float x0 = cos(lines.at(i).angle);
            float y0 = sin(lines.at(i).angle);
            float x1 = cos(lines.at(i).angle)*lines.at(i).lon;
            float y1 = sin(lines.at(i).angle)*lines.at(i).lon;
            
            float _col = /*sin((i+(e/extrude))+ofGetFrameNum()*.1)*/255.0;
            float _final_col =(255*_col)+(show_original_val*255.0);
            _final_col = ofClamp(_final_col, 0.0, 255.0);
            
            ofSetColor(_final_col);
            
            ofDrawLine(x0, y0, x1, y1);
            ofPopMatrix();

        }
    }
    
    ofPopMatrix();
    glDisable(GL_FOG);
    
    
    ofDisableDepthTest();
    ofPopStyle();
}
