
#include "johnWhitneyShader02.h"

void johnWhitneyShader02::setup(){
    
    // setup pramaters
    speed.set("speed", 0.18, 0, 2.5);
    parameters.add(speed);
    
    thickness.set("thickness", 0.26, 0.001, 0.6);
    parameters.add(thickness);
    
    integratedTime = 0;
    lastTime = 0;
    
    shader.load("scenes/johnWhitneyShader02/shader");
    
    setAuthor("Chris Anderson");
    setOriginalArtist("John Whitney");
    loadCode("scenes/johnWhitneyShader02/exampleCode.cpp");
}

void johnWhitneyShader02::reset() {
    lastTime = 0;
    integratedTime = 0;
}

void johnWhitneyShader02::update() {
    float now = getElapsedTimef();
    if (lastTime == 0) {
        lastTime = now;
    }
    float dt = now - lastTime;
    lastTime = now;
    
    integratedTime += speed * dt;
}

void johnWhitneyShader02::draw() {
    float resolution[] = { dimensions.width, dimensions.height };
    
    float time = ofMap(sin(integratedTime / 2.0), -1, 1, 0, 0.55);
    
    ofFill();
    shader.begin();
    shader.setUniform1f("time", time);
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("thickness", thickness);
    ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
    shader.end();
}