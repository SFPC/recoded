
#include "johnWhitneyShader01.h"

void johnWhitneyShader01::setup(){
  
// setup pramaters
    time.set("time", 0, 0, 3);
    parameters.add(time);

    loadCode("johnWhitneyShader01/exampleCode.cpp");
    
    shader.load("johnWhitneyShader01/shader");
}

void johnWhitneyShader01::update() {
    time.set(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, PI));
}

void johnWhitneyShader01::draw() {
    float resolution[] = { dimensions.width, dimensions.height };

    ofFill();
    shader.begin();
    shader.setUniform1f("time", time.get());
    shader.setUniform2fv("resolution", resolution);
    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}