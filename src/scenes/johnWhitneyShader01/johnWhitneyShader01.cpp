
#include "johnWhitneyShader01.h"
#include "appConstants.h"

void johnWhitneyShader01::setup(){
  
// setup pramaters
    speed.set("speed", 1, 0, 4);
    parameters.add(speed);
    
    redOffset.set("pinkOffset", 0.0, 0.0, 9.0);
    parameters.add(redOffset);
    greenOffset.set("redOffset", 2.0, 0.0, 9.0);
    parameters.add(greenOffset);
    blueOffset.set("yellowOffset", 4.0, 0.0, 9.0);
    parameters.add(blueOffset);
    
    redScale.set("pinkScale", 0.15, 0, 0.5);
    parameters.add(redScale);
    greenScale.set("redScale", 0.15, 0, 0.5);
    parameters.add(greenScale);
    blueScale.set("yellowScale", 0.15, 0, 0.5);
    parameters.add(blueScale);
    
    shader.load("scenes/johnWhitneyShader01/shader");

    integratedTime = 0;
    lastTime = 0;
    
    setAuthor("Chris Anderson");
    setOriginalArtist("John Whitney");
    loadCode("scenes/johnWhitneyShader01/exampleCode.cpp");
}

void johnWhitneyShader01::reset() {
    lastTime = 0;
    integratedTime = 0;
}

void johnWhitneyShader01::update() {
    float now = getElapsedTimef();
    if (lastTime == 0) {
        lastTime = now;
    }
    float dt = now - lastTime;
    lastTime = now;
    
    integratedTime += speed * dt;
}

void johnWhitneyShader01::draw() {
    float resolution[] = { dimensions.width, dimensions.height };
    float time = ofMap(sin(integratedTime), -1, 1, 0, PI);

    ofFill();
    shader.begin();
    shader.setUniform1f("time", time);
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("redOffset", redOffset);
    shader.setUniform1f("greenOffset", greenOffset);
    shader.setUniform1f("blueOffset", blueOffset);
    shader.setUniform1f("redScale", redScale);
    shader.setUniform1f("greenScale", greenScale);
    shader.setUniform1f("blueScale", blueScale);
    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}