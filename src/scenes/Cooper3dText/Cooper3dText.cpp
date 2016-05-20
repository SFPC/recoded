
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
    setSceneEnd(126);
    
    font.load("Helvetica Neue", 50, true, true, true);
    
    
    distWords = 60;

//    parameters.add(distWords.set("Distance Blocks",40,  0, 4000));
    parameters.add(tweenDuration.set("Tween Duration", 3000,0,10000));
    parameters.add(pauseDuration.set("Pause Duration", 200,0,5000));
    parameters.add(minAngle.set("min angle", 80,0, 360));
    parameters.add(maxAngle.set("max angle", 120, 0,360));

    maxAngle.addListener(this, &Cooper3dText::angleChanged);
    minAngle.addListener(this, &Cooper3dText::angleChanged);
    
    setupSurfaces();
    
    ofEnableAlphaBlending();
    
 //   ofRectangle v =ofGetCurrentViewport();
    
  //  cam.setAspectRatio(v.width/v.height);

    blend = ofBlendMode(3);
    ofAddListener(tween.end_E, this, &Cooper3dText::tweenEnded);
    //prevSurface = 0;
    //currentSurface = 0;
    nextSurface();

    setAuthor("Roy MacDonald");
    setOriginalArtist("Muriel Cooper");
    loadCode("scenes/Cooper3dText/exampleCode.cpp");
    

}
//--------------------------------------------------------------
void Cooper3dText::reset(){
    cam = ofCamera();
    currentSurface = surfaces.size()-1;
    nextSurface();
}
//--------------------------------------------------------------
void Cooper3dText::setupSurfaces(){
    
    string text;// = "SCHOOL FOR POETIC COMPUTATION";
    text = ofBufferFromFile("scenes/Cooper3dText/cooperLetter.txt").getText();
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
        if (i == 1) {
        surfaces.back().axis[2] = 1;
        }else{
        surfaces.back().axis[(int)round(ofRandom(0, 2))] = ((ofRandom(1) > 0.5)? 1:-1);
        }
        surfaces.back().sign = ((ofRandom(1) > 0.5)? 1:-1);
        
        if (i > 0) {
            if (surfaces.back().axis.y != 0 && surfaces[i-1].axis.y != 0) {
                surfaces.back().axis = ofVec3f::zero();
                surfaces.back().axis[(int)round(ofRandom(1))?0:2] = ((ofRandom(1) > 0.5)? 1:-1);
            }
            ofRectangle prevRect =font.getStringBoundingBox(txts[i-1],0,0);
            ofRectangle r = font.getStringBoundingBox(txts[i],0,0);
            surfaces.back().moveVector.set(prevRect.width + distWords + r.height*((surfaces.back().axis.z != 0)?1:0), 0,0);
            surfaces.back().rotationFactor = ofRandom(0, 1);
        }
    }
    rotateSurfaces();

    for (int i = 1 ; i < surfaces.size(); i++) {
        surfaces[i].setParent(surfaces[i-1]);
    }
    currentSurface = surfaces.size()-1;
}
//--------------------------------------------------------------
void Cooper3dText::angleChanged(float& f){
    rotateSurfaces();
}
//--------------------------------------------------------------
void Cooper3dText::rotateSurfaces(){
    for (int i = 1; i < surfaces.size(); i++) {
        surfaces[i].resetTransform();
        surfaces[i].rotate(ofMap(surfaces[i].rotationFactor, 0,1, minAngle, maxAngle)*surfaces[i].sign , surfaces[i].axis);
        surfaces[i].move(surfaces[i].moveVector);
    }
}
//--------------------------------------------------------------
void Cooper3dText::update(){

}

//--------------------------------------------------------------
void Cooper3dText::draw(){
  //      cout << __PRETTY_FUNCTION__ << endl;
    updateCameraTween();
    ofBackground(ofColor::black);
 //   ofDisableDepthTest();
    //ofEnableAlphaBlending();
    ofEnableDepthTest();
   // ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        cam.begin();
    for (int i = 0; i < surfaces.size(); i++) {
        surfaces[i].setIsMain(false);
        if(i != prevSurface && i != currentSurface){
                surfaces[i].draw();
            }
        }
    ofDisableDepthTest();
    surfaces[prevSurface].setIsMain(true);
    surfaces[currentSurface].setIsMain(true);
    surfaces[prevSurface].draw();
    surfaces[currentSurface].draw();
        cam.end();
    //ofDisableBlendMode();
    
    
//    ofDrawBitmapStringHighlight("curent time: " + ofToString(getElapsedTimef()), 100,100);
    
}
//--------------------------------------------------------------
void Cooper3dText::tweenEnded(int &i){
    nextSurface();
}
//--------------------------------------------------------------
void Cooper3dText::nextSurface(bool bTween){
    if (bTween) {
        int numSpaces = ofStringTimesInString(surfaces[currentSurface].text, " ");
        if (currentSurface == surfaces.size()-1) {
            tween.setParameters(easing, ofxTween::easeInOut, 0, 1, tweenDuration, 1000+pauseDuration*numSpaces + 7500);
        }else{
            tween.setParameters(easing, ofxTween::easeInOut, 0, 1, tweenDuration, 1000+pauseDuration*numSpaces);
        }
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
