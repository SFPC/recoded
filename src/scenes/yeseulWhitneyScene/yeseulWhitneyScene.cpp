
#include "yeseulWhitneyScene.h"

void yeseulWhitneyScene::setup(){
    
    parameters.add(spinSpeed.set("spinSpeed", 20, 20, 70));
    parameters.add(diffusionInterval.set("diffusionInterval", 5, 5, 10));
    parameters.add(diffusionSize.set("diffusionSize", 1.3, 1, 3));
    
    lastDiffusionTime = 0;
    
    integratedTime = 0;
    lastTime = 0;

    loadCode("scenes/yeseulWhitneyScene/exampleCode.cpp");
    
    setAuthor("Yeseul Song");
    setOriginalArtist("John Whitney");

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
    if (lastTime == 0) {
        lastTime = now;
    }
    float dt = now - lastTime;
    lastTime = now;
    
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
    
    float t = getElapsedTimef();

    if (lastDiffusionTime == 0 || diffusionInterval <= t - lastDiffusionTime) {
        diffs.push_back(circlesDiffusion(t, diffusionSize));
        cout << "add difff" << diffusionInterval << endl;
        lastDiffusionTime = t;
    }
    
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i].bKill){
            cout << "kill diff: " << i << endl;
            diffs.erase(diffs.begin() + i);
            i--;
        }
    }
    
    for(int i = 0; i < diffs.size(); i++){
        diffs[i].draw(t);
    }
}

