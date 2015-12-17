
#include "olegVeraV.h"

void olegVeraV::setup(){
  
    parameters.add(elementsAmount.set("elementsAmount", 25, 1, 36));
    parameters.add(thickness.set("thickness", 4, 0.001, 100));
    parameters.add(thicknessMultiplier.set("thicknessMultiplier", 1.01, 0.9, 1.1));
    parameters.add(curveHeight.set("heartBeat", 5, 1, 100));

    setAuthor("Oleg Pashkovsky");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/olegVeraV/exampleCode.cpp");
}

void olegVeraV::update(){

}

void olegVeraV::draw(){
    curveHeight=pow(abs(sin(ofGetElapsedTimef())),0.3)*30+14;
    
    ofBackground(0);
    ofSetColor(255);
    ofFill();
    ofPath circ;
    
    int shapes_amount=elementsAmount;
    float _thickness = thickness;
    float step=10;
    float min_w=10;
    
    
    ofPushMatrix();
    ofTranslate(dimensions.width/4*3,0);
    ofRotateZ(-45);
    
    
    for (int k=0; k<shapes_amount; k++)
    {
        
        
        
        _thickness*=thicknessMultiplier;
        step=_thickness;
        
        int _w = min_w+(k+1)*(_thickness+step)*2;
        float _h = 100;
        float y_offset=_w/2;
        
        float curve_max_h=curveHeight/100*_w/2;
        
        _h=curve_max_h*k/shapes_amount;
        
        ofPoint p1=  ofPoint(-_w/2,y_offset,0);
        ofPoint p2=  ofPoint(0,_h+y_offset,0);
        ofPoint p3= ofPoint(_w/2,y_offset,0);
        circ.setCurveResolution(20);
        circ.quadBezierTo(p1,p2,p3);
        
        p1.y+=_thickness;
        p1.x-=_thickness;
        p2.y+=_thickness;
        p3.y+=_thickness;
        p3.x+=_thickness;
        
        circ.lineTo(p3);
        circ.quadBezierTo(p3,p2,p1);
        
        p1.y-=_thickness;
        circ.lineTo(p1);
        
        
        p1=  ofPoint(-_w/2,y_offset,0);
        p2=  ofPoint(-_w/2-_h, y_offset-_w/2,0);
        p3= ofPoint(-_w/2,y_offset-_w,0);
        circ.setCurveResolution(20);
        circ.quadBezierTo(p1,p2,p3);
        p1.y+=_thickness;
        p1.x-=_thickness;
        p2.x-=_thickness;
        p3.x-=_thickness;
        p3.y-=_thickness;
        circ.lineTo(p3);
        circ.quadBezierTo(p3,p2,p1);
        
        p1.y-=_thickness;
        
        circ.lineTo(p1);
        circ.draw();
        circ.close();
        
        
        
    }
    ofPopMatrix();
}