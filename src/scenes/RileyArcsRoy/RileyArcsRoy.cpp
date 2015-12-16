#include "appConstants.h"
#include "RileyArcsRoy.h"

void RileyArcsRoy::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    setAuthor("Roy MacDonald");
    setOriginalArtist("Bridget Riley");
    loadCode("scenes/RileyArcsRoy/exampleCode.cpp");
    
    minWidth = 1;
    minSpacing = 4;
    parameters.add(thinWideRatio.set("thinWideRatio", 0.2, 0,1));
//    parameters.add(oscMax.set("oscMax", 0.98, 0,1));
  //  parameters.add(speed.set("speed", 0.2, 0,1));
    
    initTime = TWO_PI*0.8;
    
    
}

void RileyArcsRoy::update(){
    
//    thinWideRatio.set((1+sin(initTime+getElapsedTimef()*speed)*oscMax)/2 );
    
}

void RileyArcsRoy::draw(){
    ofBackground(255);
    ofSetColor(ofColor::white);
    ofPath path;
    path.setCircleResolution(120);

    float stripW = VISUALS_WIDTH/16.0 - minWidth - minSpacing;
    float wide = (1 - thinWideRatio) * stripW;
    float thin = thinWideRatio * stripW;
    
    float h = VISUALS_HEIGHT * 0.66;
    float w2 = VISUALS_WIDTH *0.5;
    
    ofVec3f pp[2];
    pp[0].set(w2, h);
    pp[1].set(w2, h);

    for (int i = 0; i < 8; i++) {
        ofVec3f p0[4], p1[4], c1[3], c0[3];
        float r0[3], r1[3];
        int i0 = i*2 -1;
        int i1 = i*2;
        p0[0].set(i *(minSpacing+minWidth) , h);
        p1[0].set(i *(minSpacing+minWidth) + minWidth , h);
        
        p0[1] = pp[0];
        p1[1] = pp[0];
        p0[2] = pp[1];
        p1[2] = pp[1];
        if(i < 4){
            p0[1].x -= wide;
            p1[1].x -= wide*2;
            
            p0[2].x +=thin;
            p1[2].x +=thin*2;

        }else{
            p0[1].x -= thin;
            p1[1].x -= thin*2;
            
            p0[2].x +=wide;
            p1[2].x +=wide*2;
        }
        
        p0[3].set(VISUALS_WIDTH - p0[0].x, h);
        p1[3].set(VISUALS_WIDTH - p1[0].x, h);
        
        for (int j = 0; j< 3; j++) {
            r0[j] = p0[j].distance(p0[j+1])/2;
            r1[j] = p1[j].distance(p1[j+1])/2;
        
            c0[j] = p0[j].getMiddle(p0[j+1]);
            c1[j] = p1[j].getMiddle(p1[j+1]);
        }
        
        path.moveTo(p0[0]);
        path.arc( c0[0], r0[0], r0[0], 0, 180);
        path.arc( c0[1], r0[1], r0[1], 180, 360);
        path.arc( c0[2], r0[2], r0[2], 0, 180);
        path.lineTo(p1[3]);
        path.arc( c1[2], r1[2], r1[2], 0, 180);
        path.arc( c1[1], r1[1], r1[1], 180, 360);
        path.arc( c1[0], r1[0], r1[0], 0, 180);
        path.lineTo(p0[0]);
        path.close();
        
        pp[0] = p1[1];
        pp[1] = p1[2];
        
    }
    path.setFillColor(ofColor::black);
    path.draw();


}
