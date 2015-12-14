
#include "johnWhitneyShader02.h"

void johnWhitneyShader02::setup(){
    
    // setup pramaters
    time.set("time", 0.18, 0, 1);
    parameters.add(time);
    
    thickness.set("thickness", 0.26, 0.0001, 0.4);
    parameters.add(thickness);
    
    shader.load("johnWhitneyShader02/shader");
    
    loadCode("johnWhitneyShader02/exampleCode.cpp");
}

void johnWhitneyShader02::update() {
}

void johnWhitneyShader02::draw() {
    float resolution[] = { dimensions.width, dimensions.height };
    
    ofFill();
    shader.begin();
    shader.setUniform1f("time", time);
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("thickness", thickness);
    ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
    shader.end();
}