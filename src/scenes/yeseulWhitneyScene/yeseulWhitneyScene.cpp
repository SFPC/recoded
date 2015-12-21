
#include "yeseulWhitneyScene.h"

void yeseulWhitneyScene::setup(){
    
    setAuthor("Yeseul Song");
    setOriginalArtist("John Whitney");
    
    parameters.add(spinSpeed.set("spinSpeed", 10, 10, 70));
    parameters.add(diffusionInterval.set("diffusionInterval", 5, 5, 10));
    parameters.add(diffusionSize.set("diffusionSize", 0.1, 0.1, 1.5));
    
    lastDiffusionTime = 0;
    
    integratedTime = 0;
    lastTimeBg = 0;
    lastTimeFg = 0;
    
    loadCode("scenes/yeseulWhitneyScene/exampleCode.cpp");
    
}


void yeseulWhitneyScene::update(){
    
}


void yeseulWhitneyScene::draw(){
    
    ofPushMatrix();
    
    ofTranslate(dimensions.width/2, dimensions.height/2);
    
    drawPattern();
    
    diffusion();
    
    ofPopMatrix();
    
}


void yeseulWhitneyScene::drawPattern(){
    
    ofSetColor(255);
    ofFill();
    
    float now = getElapsedTimef();
    if (lastTimeBg == 0) {
        lastTimeBg = now;
    }
    float dt = now - lastTimeBg;
    if (dt < 0 || dt > 0.2)
        dt = 0;
    lastTimeBg = now;
    
    integratedTime += spinSpeed * dt;
    float k = integratedTime;
    
    for (int r=0; r<35; r+=1) {
        ofRotate(k*sin(r));
        for (int a=0; a<20; a+=1) {
            ofRotate(360/20);
            ofDrawCircle(0, r*10, 1);
            
        }
    }
    
}


void yeseulWhitneyScene::diffusion() {
    
    float now = getElapsedTimef();
    if (lastTimeFg == 0) {
        lastTimeFg = now;
    }
    float dt = now - lastTimeFg;
    if (dt < 0 || dt > 0.2)
        dt = 0;
    lastTimeFg = now;
    integratedFgTime += dt;
    
    if (diffusionInterval <= integratedFgTime - lastDiffusionTime) {
        diffs.push_back(circlesDiffusion(integratedFgTime, diffusionSize));
        lastDiffusionTime = integratedFgTime;
    }
    
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i].bKill){
            cout << "kill diff: " << i << endl;
            diffs.erase(diffs.begin() + i);
            i--;
        }
    }
    
    for(int i = 0; i < diffs.size(); i++){
        diffs[i].draw(integratedFgTime);
    }
}

