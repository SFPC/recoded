
#include "johnWhitneyShader02.h"

void johnWhitneyShader02::setup(){
    
    // setup pramaters
    time.set("time", 0, 0, 1);
    parameters.add(time);
    
    loadCode("johnWhitneyShader02/exampleCode.cpp");
    
    shader.load("johnWhitneyShader02/shader");
}

void johnWhitneyShader02::update() {
    float t = ofGetElapsedTimef() / 3.0;
    time.set(ofMap(sin(t), -1, 1, 0, 1));
}

void johnWhitneyShader02::draw() {
    float resolution[] = { dimensions.width, dimensions.height };
    
    ofFill();
    shader.begin();
    shader.setUniform1f("time", time.get());
    shader.setUniform2fv("resolution", resolution);
    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}