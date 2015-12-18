
#include "yeseulWhitneyScene.h"

void yeseulWhitneyScene::setup(){
    
    parameters.add(spinSpeed.set("spinSpeed", 5, 1, 70));
    parameters.add(diffusionInterval.set("diffusionInterval", 5, 5, 10));
    parameters.add(diffusionSize.set("diffusionSize", 1.5, 1, 3));
    
    setAuthor("Yeseul Song");
    setOriginalArtist("John Whitney");
    loadCode("yeseulWhitneyScene/exampleCode.cpp");
    
    lastDiffusionTime = 0;
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
    
    float y = getElapsedTimef();
    for (int r=0; r<35; r+=1) {
        ofRotate(y*spinSpeed*sin(r));
        for (int a=0; a<20; a+=1) {
            ofRotate(360/20);
            ofDrawCircle(0, r*10, 1);
            
        }
    }
    
}


void yeseulWhitneyScene::diffusion() {
    
    float t = getElapsedTimef();
    cout << t <<endl;
    cout << diffusionInterval << " " << lastDiffusionTime<< endl;
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