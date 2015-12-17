
#include "loloVera2.h"

void loloVera2::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    random_factor.set("RANDOM FACTOR",1.0,0.0,30.0);
    u_bang.set("UPDATE PATHS",21,2,30);
    line_width.set("LINE WEIGHT",2.0,1.0,5.0);
    redSpeed.set("redSpeed",9,0,10);
    parameters.add(random_factor);
    parameters.add(u_bang);
    parameters.add(line_width);
    parameters.add(redSpeed);
    
    texture.load("scenes/loloVera2/tex.jpg");
    
    int vera_path_size = 5;
    int off_y = 100;
    
    for(int i=0;i<vera_path_size;i++)
    {
        VeraLinePath    v_line = VeraLinePath();
        size_bloq = VISUALS_HEIGHT/vera_path_size;
        int max_rand_hsize = size_bloq;
        float   sizeh = ofRandom(200,max_rand_hsize);

        v_line.setup(i+ofRandom(0,10000),(i*size_bloq)+size_bloq/2, (int)ofRandom(3, 10), ofRandom(.1,.3),sizeh);
        vera_paths.push_back(v_line);
    }

    setAuthor("Marcelo Armendáriz");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/loloVera2/exampleCode.cpp");
    
}

void loloVera2::update(){
     
    for (int i=0;i<vera_paths.size(); i++) {
        vera_paths.at(i).l_width = line_width;
        vera_paths.at(i).update(random_factor,u_bang, redSpeed);
    }
    
}

void loloVera2::draw(){
    
    //ofBackground(200);
    ofBackground(0);
    ofPushStyle();
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    //texture.draw(0.0, 0.0);
    
    //ofDisableBlendMode();
   
    for (int i=1;i<vera_paths.size(); i++) {
        float d = ofDist(vera_paths.at(i-1).d_guide.x, vera_paths.at(i-1).d_guide.y, vera_paths.at(i).d_guide.x, vera_paths.at(i).d_guide.y);
        float alpha = ofMap(d, 0.0, VISUALS_WIDTH, 1.0, 0.0);
        ofSetColor(255, 0, 0,alpha*255.0);
        ofDrawLine(vera_paths.at(i-1).d_guide.x,vera_paths.at(i-1).d_guide.y,vera_paths.at(i).d_guide.x,vera_paths.at(i).d_guide.y);
    }
    
    //ofEnableAlphaBlending();
    for (int i=0;i<vera_paths.size()-1; i++) {
        for(int j=0;j<vera_paths.at(i).q_guide.size();j++)
        {
            for(int k=0;k<vera_paths.at(i+1).q_guide.size();k++){
                ofPoint p0 = vera_paths.at(i).q_guide.at(j);
                ofPoint p1 = vera_paths.at(i+1).q_guide.at(k);
                float   d_points = p0.distance(p1);
                if(d_points < size_bloq){
                    float   factor_d_points = ofMap(d_points, 0.0, size_bloq*2, 1.0, 0.0,true);
                    ofSetColor(255,factor_d_points*100);
                    ofDrawLine(p0, p1);
                }
            }
        }
    }
    //ofDisableAlphaBlending();

    
    for (int i=0;i<vera_paths.size(); i++) {
        
        
        
        
        vera_paths.at(i).draw();
    }
    
    ofPopStyle();
    
    
}
