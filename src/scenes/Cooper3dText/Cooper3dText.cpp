
#include "Cooper3dText.h"
#include "appConstants.h"
float distToCameraToFit(const ofRectangle &r, const ofCamera& cam){
    
    
  //  ofRectangle v(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
    
    ofRectangle rr(r);
    rr.scaleFromCenter(1.1);
    float h = ((rr.width/rr.height)>=1)?rr.width:rr.height;
    float d = h / (2.0f * tanf(PI * cam.getFov()/ 360.0f)) ;
//    cout << d << endl;
    return d;
}

//--------------------------------------------------------------
void Cooper3dText::setup(){
    
    
    font.load("Helvetica Neue", 50, true, true, true);
    
    
    distWords = 60;

//    parameters.add(distWords.set("Distance Blocks",40,  0, 4000));
    parameters.add(tweenDuration.set("Tween Duration", 4000,0,10000));
    parameters.add(pauseDuration.set("Pause Duration", 1000,0,5000));
//    parameters.add(tweenVal.set("tweenVal", 0,0,1));
//    parameters.add(camPos.set("camPos", ofVec3f(0), ofVec3f(-10000), ofVec3f(10000)));
//    parameters.add(camOrientation.set("camOrientation", ofVec4f(0), ofVec4f(-1),ofVec4f(1)));
//    parameters.add(camStartOrientationParam.set("camStartOrientation", ofVec4f(0), ofVec4f(-1),ofVec4f(1)));
//    parameters.add(camEndOrientationParam.set("camEndOrientation", ofVec4f(0), ofVec4f(-1),ofVec4f(1)));
//    distWords.addListener(this, &Cooper3dText::distWordsChange);

    setupSurfaces();
    
    ofEnableAlphaBlending();
    
    ofRectangle v =ofGetCurrentViewport();
    
  //  cam.setAspectRatio(v.width/v.height);

    blend = ofBlendMode(3);
    ofAddListener(tween.end_E, this, &Cooper3dText::tweenEnded);
    nextSurface();

    setAuthor("Roy MacDonald");
    setOriginalArtist("Muriel Cooper");
    loadCode("Cooper3dText/exampleCode.cpp");
    

}
//--------------------------------------------------------------
void Cooper3dText::setupSurfaces(){
    
    string text;// = "SCHOOL FOR POETIC COMPUTATION";
    text = ofBufferFromFile("Cooper3dText/cooperLetter.txt").getText();
    ofStringReplace(text, "\r", "\n");
    vector<string> txts = ofSplitString(text, "\n\n");
  //  cout << "txts.size(): " <<txts.size() << endl;
    surfaces.clear();
    
    for (int i = 0 ; i < txts.size(); i++) {
        
        ofColor c;
        c.setHsb(ofRandom(255), ofRandom(230, 255), ofRandom(180, 255));
        surfaces.push_back(textSurface());
        surfaces.back().setTextAndFont(txts[i], font,c);
        surfaces.back().axis = ofVec3f::zero();
        surfaces.back().axis[(int)round(ofRandom(0, 2))] = ((ofRandom(1) > 0.5)? 1:-1);
        
        surfaces.back().sign = ((ofRandom(1) > 0.5)? 1:-1);
        
        if (i > 0) {
            if (surfaces.back().axis.y != 0 && surfaces[i-1].axis.y != 0) {
                surfaces.back().axis = ofVec3f::zero();
                surfaces.back().axis[(int)round(ofRandom(1))?0:2] = ((ofRandom(1) > 0.5)? 1:-1);
            }
            ofRectangle prevRect =font.getStringBoundingBox(txts[i-1],0,0);
            surfaces.back().rotate(90*surfaces.back().sign , surfaces.back().axis);
            ofVec3f m(prevRect.width + distWords + prevRect.height*((surfaces.back().axis.z*surfaces.back().sign == -1)?1:0), 0,0);
            surfaces.back().move(m);
            cout << m << endl;
        }
    }
    
    for (int i = 1 ; i < surfaces.size(); i++) {
        surfaces[i].setParent(surfaces[i-1]);
    }
    currentSurface = surfaces.size()-1;
}
////--------------------------------------------------------------
//void Cooper3dText::distWordsChange(float & f){
//    setupSurfaces();
//}
//--------------------------------------------------------------
void Cooper3dText::update(){

}

//--------------------------------------------------------------
void Cooper3dText::draw(){
  //      cout << __PRETTY_FUNCTION__ << endl;
    updateCameraTween();
    ofBackground(ofColor::black);
    ofEnableDepthTest();
//    ofEnableBlendMode(blend);
        cam.begin();
        for (auto s: surfaces) {
            s.draw();
        }
        cam.end();
//    ofDisableBlendMode();
    ofDisableDepthTest();
}
//--------------------------------------------------------------
void Cooper3dText::tweenEnded(int &i){
    nextSurface();
}
//--------------------------------------------------------------
void Cooper3dText::nextSurface(bool bTween){
    if (bTween) {
        tween.setParameters(easing, ofxTween::easeInOut, 0, 1, tweenDuration, pauseDuration);
        tween.start();
    }
    prevSurface = currentSurface;
    currentSurface++;
    currentSurface %= surfaces.size();
    
    camStartPos = cam.getGlobalPosition();
    camStartOrientation = cam.getGlobalOrientation();
    
    camEndOrientation =  surfaces[currentSurface].getGlobalOrientation();
//    camEndOrientationParam.set(ofVec4f(camEndOrientation.x(), camEndOrientation.y(), camEndOrientation.z(), camEndOrientation.w()));
//    camStartOrientationParam.set(ofVec4f(camStartOrientation.x(), camStartOrientation.y(), camStartOrientation.z(), camStartOrientation.w()));
//    
    ofRectangle rc = font.getStringBoundingBox(surfaces[currentSurface].text, 0, 0);
    ofVec3f offset (rc.width/2,-rc.height/2,0 );
    
    camEndPos = surfaces[currentSurface].getGlobalPosition() + ofVec3f(0,0, distToCameraToFit(rc, cam))*camEndOrientation + offset*camEndOrientation;
    
    if (!bTween) {
        cam.setPosition(camEndPos);
        cam.setOrientation(camEndOrientation);
    }
}
//--------------------------------------------------------------
void Cooper3dText::updateCameraTween(){
    float f = tween.update();
//    tweenVal.set(f);
    if (tween.isTweening()) {
        ofQuaternion q;
        q.slerp(f, camStartOrientation, camEndOrientation);
        cam.setPosition(camStartPos.getInterpolated(camEndPos, f));
        cam.setOrientation(q);
        surfaces[currentSurface].transition = f;
        if (currentSurface >0) {
        surfaces[currentSurface-1].transition = 1 - f;
        }

//        camOrientation.set(ofVec4f(q.x(), q.y(), q.z(), q.w()));
//        camPos.set(cam.getPosition());
    }
}
