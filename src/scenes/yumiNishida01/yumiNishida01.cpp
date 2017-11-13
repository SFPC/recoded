
#include "yumiNishida01.h"

void yumiNishida01::reset(){
    lines.clear();
    x = 0;
    line_number = 0;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    lines.push_back(mesh);
}


void yumiNishida01::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

   
    ofSetBackgroundAuto(false);
    ofBackground(255);
    
    reset();
    
    //Gui
    x_.set("x_", -20.0, -50.0, 20.0);
    y_.set("y_", 30.0, 20.0, 200.0);
    color.set("color", 0, 0, 255.0);
    parameters.add(x_);
    parameters.add(y_);
    parameters.add(color);
    parameters.add(lineWidth.set("line width", 1, 0, 2));

    setAuthor("Yumi Nishida");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/yumiNishida01/exampleCode.cpp");
}

void yumiNishida01::update(){
    
    ofColor c = ofColor::fromHsb(0, 255, 255);
    c.setHue(color);
    
    int y = dimensions.height*0.01 + dimensions.height*0.12*line_number;
    
    lines[line_number].addVertex(ofVec3f(x+ofRandom(x_, 20), y+ofRandom(20, y_)));
    lines[line_number].addColor(c);
    
    x+=10;
    
    if(x > dimensions.width){
        x = 0;
        line_number++;
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
        lines.push_back(mesh);
    }
    if(y > dimensions.height*0.9){
        reset();
    }
}

void yumiNishida01::draw(){
    
    //ofBackground(255);
    ofSetLineWidth(lineWidth);
    for (int i = 0; i < lines.size(); i++) {
        lines[i].draw();
    }
}
