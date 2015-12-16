
#include "chrisMurielCooper.h"

void chrisMurielCooper::setup(){
  
    cameraRotationX.set("cameraRotationX", 0, 0, 360);
    parameters.add(cameraRotationX);
    
    cameraRotationY.set("cameraRotationY", 0, 0, 360);
    parameters.add(cameraRotationY);
    
    cameraRotationZ.set("cameraRotationZ", 0, 0, 360);
    parameters.add(cameraRotationZ);
    
    cameraZoom.set("cameraZoom", 100, 0, 10000);
    parameters.add(cameraZoom);
    
    text1Opacity.set("text1Opacity", 255, 0, 255);
    parameters.add(text1Opacity);
    text2Opacity.set("text2Opacity", 0, 0, 255);
    parameters.add(text2Opacity);
    text1PlaneOpacity.set("text1PlaneOpacity", 100, 0, 255);
    parameters.add(text1PlaneOpacity);
    text2PlaneOpacity.set("text2PlaneOpacity", 100, 0, 255);
    parameters.add(text2PlaneOpacity);
    
    text1.text.push_back("I guess I'm never sure that print is truly linear.");
    text1.text.push_back("It’s more a simultaneous medium.");
    text1.text.push_back("Designers know a lot about how to control perception,");
    text1.text.push_back("how to present information in some way that helps");
    text1.text.push_back("you find what you need, or what it is they think you need.");
    text1.text.push_back("Information is only useful when it can be understood.");
    text1.pos = ofVec3f(0, 0, 300);
    text1.rotAxis = ofVec3f(0, 1, 0);
    text1.rotAmt = 20;
    text1.planeColor = ofColor(255, 0, 0);
    text1.textOpacity = &text1Opacity;
    text1.planeOpacity = &text1PlaneOpacity;

    text2.text.push_back("When you start talking about design in relation to computers,");
    text2.text.push_back("you're not just talking about how information appears on the screen,");
    text2.text.push_back("you’re talking about how it’s designed into the architecture");
    text2.text.push_back("of the machine and of the language.");
    text2.text.push_back("You have different capabilities, different constraints and");
    text2.text.push_back("variables than you have in any other medium,");
    text2.text.push_back("and nobody even knows what they are yet.");
    text2.pos = ofVec3f(0, 0, 300);
    text2.rotAxis = ofVec3f(0, 1, 0);
    text2.rotAmt = 70;
    text2.planeColor = ofColor(0, 0, 255);
    text2.textOpacity = &text2Opacity;
    text2.planeOpacity = &text2PlaneOpacity;
    
    ttf.load("scenes/chrisMurielCooper/OpenSans-Regular.ttf", 32);

    setAuthor("Chris Anderson");
    setOriginalArtist("Muriel Cooper");
    loadCode("scenes/chrisMurielCooper/exampleCode.cpp");
}

void chrisMurielCooper::update(){
    // Horrible, horrible constant hell. To be replaced when we have good animations.

    float t = getElapsedTimef() / 4.0;
    cameraRotationX.set(((sin(t) * 0.5) + 0.5) * 360);
    cameraRotationY.set(((cos(t) * 0.5) + 0.5) * 360);
    cameraRotationZ.set(((cos(t + PI / 4.0) * 0.5) + 0.5) * 360);
    cameraZoom.set(((sin(t) * 0.5) + 0.5) * 2000 + 500);
    
    t *= 5;

    text1Opacity.set(((sin(t) * 0.5) + 0.5) * 255 / 2);
    text2Opacity.set(((sin(t + PI / 2.0) * 0.5) + 0.5) * 255 / 2);
    text1PlaneOpacity.set(((sin(t + PI) * 0.5) + 0.5) * 60 + 10);
    text2PlaneOpacity.set(((sin(t + 3.0 * PI / 2.0) * 0.5) + 0.5) * 60 + 10);
    
    cam.setPosition(ofVec3f(cameraRotationX, cameraRotationY, cameraRotationZ));
    cam.lookAt(ofVec3f(0, 0, 0));
    cam.setDistance(cameraZoom);
}

void spaceText::drawLeftPlane() {
    ofPlanePrimitive plane;
    float tp1W = 300;
    plane.set(tp1W, 800, 2, 2);
    plane.setPosition(-tp1W/2.0, -200, 0);
    
    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y, pos.z);
    ofRotate(rotAmt, rotAxis.x, rotAxis.y, rotAxis.z);
    ofSetColor(planeColor, *planeOpacity);
    
    plane.draw();
        
    ofPopMatrix();
}

void spaceText::drawText(const ofTrueTypeFont& ttf) {
    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y, pos.z);
    ofRotate(rotAmt, rotAxis.x, rotAxis.y, rotAxis.z);
    
    ofDisableDepthTest();
    
    ofSetColor(255, *textOpacity);
    for (auto line : text) {
        float height = ttf.stringHeight(line);
        
        ttf.drawString(line, 0, height/2);
        ofTranslate(0, -70);
    }
    
    ofEnableDepthTest();
    
    ofPopMatrix();
}

void spaceText::drawRightPlane() {
    ofPlanePrimitive plane;
    float tp2W = 1500;
    plane.set(tp2W, 800, 2, 2);
    plane.setPosition(tp2W/2.0, -200, 0);

    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y, pos.z);
    ofRotate(rotAmt, rotAxis.x, rotAxis.y, rotAxis.z);
    ofSetColor(planeColor, *planeOpacity);
    
    plane.draw();
    
    ofPopMatrix();
}

void chrisMurielCooper::draw(){
    cam.begin();
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableAntiAliasing();

    text1.drawLeftPlane();
    text2.drawRightPlane();
    text1.drawText(ttf);
    text2.drawText(ttf);
    text1.drawRightPlane();
    text2.drawLeftPlane();
    
    ofDisableAntiAliasing();
    ofDisableBlendMode();
    ofDisableDepthTest();
    cam.end();
}