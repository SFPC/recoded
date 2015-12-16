
#include "rachelScene.h"

void rachelScene::setup(){
    
    posX.set("posX", 0.001, -0.01, 0.01);
    parameters.add(posX);
    posY.set("posY", 0.002, -0.01, 0.01);
    parameters.add(posY);
    time.set("time", 0.1, 0, 2*PI);
    parameters.add(time);

    shader.load("scenes/rachelScene/shader");
    setAuthor("Rachel Ulgado");
    setOriginalArtist("John Whitney");
    loadCode("scenes/rachelScene/exampleCode.cpp");
}

void rachelScene::update(){
    
}

void rachelScene::draw(){
    float resolution[] = { dimensions.width, dimensions.height };
    ofFill();
    
    shader.begin();
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("posx", posX);
    shader.setUniform1f("posy", posY);
    shader.setUniform1f("time", time);
    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}
