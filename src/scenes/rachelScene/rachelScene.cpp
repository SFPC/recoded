
#include "rachelScene.h"

void rachelScene::setup(){
   
    // setup pramaters
    // param.set("param", 5, 0, 100);
    // parameters.add(param);
    
    scale.set("scale", 0, 1, 0.01);
    parameters.add(scale);

    loadCode("rachelScene/exampleCode.cpp");
}

void rachelScene::update(){
    
    // just for live updating shader.frag
    if(ofGetFrameNum() % 60 == 0) {
        shader.load("rachelScene/shader");
    }
    
    float t = ofGetElapsedTimef() / 18.0;
    scale.set(ofMap(sin(t), -1, 1, 0, 1));
}

void rachelScene::draw(){
    float resolution[] = { dimensions.width, dimensions.height };
    ofFill();
    
    shader.begin();
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("scale", scale.get());
    shader.setUniform1f("posx", sin(ofGetElapsedTimef()));
    shader.setUniform1f("posy", cos(ofGetElapsedTimef()));
    shader.setUniform1f("time", sin(ofGetElapsedTimef()));
    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}
