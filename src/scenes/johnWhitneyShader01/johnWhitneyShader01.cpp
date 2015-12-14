
#include "johnWhitneyShader01.h"
#include "appConstants.h"

void johnWhitneyShader01::setup(){
  
// setup pramaters
    time.set("time", 0, 0, PI);
    parameters.add(time);
    
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
    
    shader.load("johnWhitneyShader01/shader");

    setAuthor("Chris Anderson");
    setOriginalArtist("John Whitney");
    loadCode("johnWhitneyShader01/exampleCode.cpp");
}

void johnWhitneyShader01::update() {
    time.set(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, PI));
}

void johnWhitneyShader01::draw() {
    float resolution[] = { dimensions.width, dimensions.height };

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