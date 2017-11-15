
#include "zzEggScene.h"

void zzEggScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzEggScene.h
    //parameters.add(param.set("param", 5, 0, 100));

   
    
    
    yolk.load("zzScenes/zzEggScene/yolk_specular.png");
    //    orig.load("Instagram_D_98_00000_original.png");
    mouth.load("zzScenes/zzEggScene/mouth.png");
    
    yolk.setAnchorPercent(0.5, 0.5);
    //    orig.setAnchorPercent(0.5, 0.5);
    mouth.setAnchorPercent(0.5, 0.5);
    
    WW = dimensions.width;
    HH = dimensions.height;
    
    curTime = 0;
    curSpeed = 0;
    
    deg_ = 0;
    
    //Gui
    parameters.add(move.set("move", 100.0, 0.0, 200.0));
    parameters.add(deg.set("deg", 0, 0, 0.5));
   
    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");
    loadCode("zzScenes/zzEggScene/exampleCode.cpp", false);
    
}

void zzEggScene::update(){
    deg_ += deg;
    
    // 0.5秒に一回止める
    int T = ofGetElapsedTimef() * (1.0 / 0.5); //経過時間の2倍になる計算
    static int oldT = T;
    if (T != oldT)
    {
        oldT = T;
        //        cout << "clock:          " << T << endl;
        
        curSpeed = T % 2 == 0 ? 0 : 1; //条件 ?  trueのときの式１ : falseのときの式２
        //        cout << "   curSpeed:            " << curSpeed << endl;
    }
    
    // curSpeedを使ってcurTimeを更新
    curTime += ofGetLastFrameTime() * curSpeed;
}

void zzEggScene::draw(){
    
    
    ofBackground(ofColor::darkMagenta);
    float d = curTime * 2;
    
    //original image
    //    ofPushMatrix();
    //    ofTranslate(-9, -3);
    //    ofPushStyle();
    //    ofSetColor(255, 150);
    //    orig.draw(WW/2, HH/2, orig.getWidth()*0.53, orig.getHeight()*0.53);
    //    ofPopStyle();
    //    ofPopMatrix();
    
    ofSetCircleResolution(100);
    
    ofPushMatrix();
    ofTranslate(WW/2, HH/2);
    
    //egg white
    //        ofSetColor(255,150);
    int radius = 200;
    ofDrawCircle(ofSignedNoise(ofGetElapsedTimef()+10)*move, -HH/14, radius); //upper
    ofDrawCircle(ofSignedNoise(ofGetElapsedTimef())*move, HH/14, radius); //lower
    ofDrawCircle(-WW/14, ofSignedNoise(ofGetElapsedTimef()+20)*move, radius); //Left
    ofDrawCircle(WW/14, ofSignedNoise(ofGetElapsedTimef()+5)*move, radius); //Right
    
    //yellow egg
    ofPushMatrix();
    //        ofSetColor(255, 150);
    ofRotateZ(deg*360);
    yolk.draw(0, 0, yolk.getWidth()*0.48+sin(ofGetElapsedTimef())*40, yolk.getHeight()*0.48+sin(ofGetElapsedTimef())*40);
    ofPopMatrix();
    
    //mouth
    ofPushMatrix();
    ofTranslate(0, HH/30);
    //        ofRotateZ(deg1b);
    ofRotateZ(deg*360);
    mouth.draw(0, 0, mouth.getWidth()*0.48, mouth.getHeight()*0.48);
    ofPopMatrix();
    
    //eyes
    ofPushStyle();
    ofSetColor(0);
    ofDrawCircle(0-WW/18, 0-HH/18, (sin(ofGetElapsedTimef()*5)*3)+10);
    ofDrawCircle(0+WW/18, 0-HH/18, (cos(ofGetElapsedTimef()*5)*3)+10);
    ofPopStyle();
    
    ofPopMatrix();
}
