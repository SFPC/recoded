#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "appConstants.h"


class VeraLinePath : public ofPoint
{
    
public:
    
    ofPoint guide;
    ofPoint d_guide;
    float   guide_counter;
    float   guide_vel;
    vector<ofPoint>   q_guide;
    vector<ofPoint>   q_guide_d;
    
    float   easing;
    float   e_d;
    float   e;
    float   guide_step;
    float   line_fill_counter;
    int     current_point;
    float   guide_point_dis,guide_angle;
    int     update_bang;
    float   sizeh;
    float   l_width;
    
    VeraLinePath(){};
    ~VeraLinePath(){};
    
    void    setup(float _r,float y,int _update_bang,float    _easing,float   _sizeh)
    {
        
        set(0.0,y);
        update_bang = _update_bang;
        easing = _easing;
        sizeh = _sizeh;
        guide_counter = 0.0;
        guide_vel = .1;
        guide = d_guide = ofPoint(VISUALS_WIDTH/2,y);
        
        
        int q_guide_size = ofRandom(20,50);
        
        float n_counter = 0.0;
        
        for(int i=0;i<q_guide_size;i++)
        {
            ofPoint _p = ofPoint();
            
            
            _p.x = ofMap(i, 0.0, q_guide_size-1, 0,VISUALS_WIDTH);
            _p.y = y+(ofNoise(_r,n_counter,i/q_guide_size)*_sizeh)-_sizeh/2;
            q_guide.push_back(_p);
            q_guide_d.push_back(_p);
            n_counter+=.9;
        }
        
        
        guide.set(q_guide.at(0).x, q_guide.at(0).y);
        current_point = 1;
        guide_counter = 0.0;
        guide_point_dis = guide_angle;

    };
    
    void    update(float    _rfactor,int    _bang, float redSpeed)
    {
        if(ofGetFrameNum() % _bang == 0){
            
            for(int i=1;i<q_guide.size()-1;i++)
            {
                q_guide_d.at(i).x=ofMap(i, 0.0, q_guide.size()-1, 0,VISUALS_WIDTH)+ofRandom(-1,1)*_rfactor;
                q_guide_d.at(i).y=y+ofRandom(-1,1)*_rfactor;
            }
            
        }
        
        for(int i=0;i<q_guide.size();i++)
        {
            q_guide.at(i)+=(q_guide_d.at(i)-q_guide.at(i))*easing;
            
        }
        
        
        guide.set(q_guide.at(current_point-1).x, q_guide.at(current_point-1).y);
        
        
        guide_angle = atan2(guide.y-q_guide.at(current_point).y, guide.x-q_guide.at(current_point).x);
        
        guide_point_dis = ofDist(guide.x, guide.y, q_guide.at(current_point).x, q_guide.at(current_point).y);
        guide_step =(guide_point_dis * ofMap(redSpeed, 0, 10, 0.25, 0));
        guide_counter+=guide_step;
        
        d_guide.x = guide.x+cos(guide_angle)*-guide_counter;
        d_guide.y = guide.y+sin(guide_angle)*-guide_counter;
        
        if(guide_counter >= guide_point_dis)
        {
            e = 0.0;
            e_d = 1.0;
            guide_counter = 0.0;
            guide.set(q_guide.at(current_point).x, q_guide.at(current_point).y);
            current_point++;
            if(current_point > q_guide.size()-1)
            {
                guide.set(q_guide.at(0).x, q_guide.at(0).y);
                current_point = 1;
            }
            d_guide.set(guide.x,guide.y);

        }
        
        e +=(e_d-e)*.2;
    };
    
    void    draw()
    {
        ofPushStyle();
        ofEnableAlphaBlending();
        
        ofSetColor(255,100);
        
        for(int i=1;i<q_guide.size();i++)
        {
            ofSetLineWidth(l_width);
            
            ofDrawLine(q_guide.at(i-1).x, q_guide.at(i-1).y, q_guide.at(i).x, q_guide.at(i).y);
        }
        
        ofSetLineWidth(l_width+1);
        
        ofSetColor(255, 0, 0);
        
        ofDrawLine(guide.x, guide.y, d_guide.x,d_guide.y);
        
        ofSetColor(255);
        for (int i=0; i<q_guide.size(); i++) {
            ofDrawCircle(q_guide.at(i).x,q_guide.at(i).y, 2);
        }
        
        ofSetColor(255, 0, 0,100);
        ofDrawCircle(q_guide.at(current_point-1).x, q_guide.at(current_point-1).y, e*20.0);
        
        ofDisableAlphaBlending();
        ofPopStyle();
    };
    
    
};

class loloVera2 : public baseScene {
    
public:
    
    
    void setup();
    void update();
    void draw();
    
    ofImage texture;
    float   size_bloq;
    
    
    vector<VeraLinePath>    vera_paths;
    
    
    ofParameter<float>      random_factor;
    ofParameter<float>      line_width;
    ofParameter<float>      redSpeed;

    ofParameter<int>        u_bang;
};
