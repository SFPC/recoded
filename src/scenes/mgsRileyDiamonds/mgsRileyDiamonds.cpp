
#include "mgsRileyDiamonds.h"
#include "appConstants.h"

void mgsRileyDiamonds::setup(){
  setAuthor("Michael Simpson");
  setOriginalArtist("Bridget Riley");
  
  parameters.add(grayscale.set("grayscale", false));
  //parameters.add(sequentialShading.set("Sequential Shading", false));
  parameters.add(height.set("Diamond Height", 25.0, 1, 50));
  parameters.add(width.set("Diamond Width", 25.0, 1, 50));
  parameters.add(red.set("Red Amount", 255, 50, 255));
  parameters.add(green.set("Green Amount", 255, 50, 255));
  parameters.add(blue.set("Blue Amount", 255, 50, 255));
  parameters.add(alpha.set("Alpha Amount", 255, 0.5, 255));
  parameters.add(animated.set("Animated", true));
  parameters.add(discoMode.set("Disco Mode", false));
  width.addListener(this, &mgsRileyDiamonds::redrawFloat);
  height.addListener(this, &mgsRileyDiamonds::redrawFloat);
  alpha.addListener(this, &mgsRileyDiamonds::redraw);
  red.addListener(this, &mgsRileyDiamonds::redraw);
  green.addListener(this, &mgsRileyDiamonds::redraw);
  blue.addListener(this, &mgsRileyDiamonds::redraw);
  grayscale.addListener(this, &mgsRileyDiamonds::redrawBool);
  animated.addListener(this, &mgsRileyDiamonds::redrawBool);
  discoMode.addListener(this, &mgsRileyDiamonds::redrawBool);
  //sequentialShading.addListener(this, &mgsRileyDiamonds::redrawBool);
  
  loadCode("scenes/mgsRileyDiamonds/exampleCode.cpp");
  
  gh = dimensions.height/height;
  gw = dimensions.width/width;
  
  frame.allocate(dimensions.width, dimensions.height, GL_RGBA32F_ARB);
  
  frame.begin();
  ofClear(0);
  frame.end();
  drawFullRiley();
  drawRiley();
}

void mgsRileyDiamonds::update(){
  gh = dimensions.height/height;
  gw = dimensions.width/width;
}

void mgsRileyDiamonds::draw(){
  drawRiley();
  frame.draw(0,0);
}

void mgsRileyDiamonds::drawFullRiley(){
  frame.begin();
  //ofClear(0);
  for(float x = 0; x < dimensions.width+gw; x += gw){
    for(float y = 0; y < dimensions.width+gh; y += gh){
      ofColor c = ofColor(ofRandom(0,red),ofRandom(0, green), ofRandom(0,blue),255);

      ofSetColor(c);
      ofFill();

      gh = dimensions.height/height;
      gw = dimensions.width/width;
      
      ofBeginShape();
      ofVertex(x-gw, y+gh);
      ofVertex(x, y+gh);
      ofVertex(x+gw, y);
      ofVertex(x, y);
      ofVertex(x-gw, y+gh);
      ofEndShape(true);
    }
  }
  frame.end();
}

void mgsRileyDiamonds::redraw(float& i){
  if(!animated){
  } else {
    gh = dimensions.height/height;
    gw = dimensions.width/width;
  }
}

void mgsRileyDiamonds::redrawFloat(float& i){

}

void mgsRileyDiamonds::redrawBool(bool& i){
  gh = dimensions.height/height;
  gw = dimensions.width/width;
}

void mgsRileyDiamonds::drawRiley(){
  frame.begin();
  
  ofSetColor(0, 0.5);
  ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
  ofColor c = ofColor(ofRandom(0,red),ofRandom(0, green), ofRandom(0,blue),255);
  ofSetColor(c);
  ofFill();

  float x = shiftCounter;
  float y = rowCounter;
  
  ofBeginShape();
  ofVertex(x-gw, y+gh);
  ofVertex(x, y+gh);
  ofVertex(x+gw, y);
  ofVertex(x, y);
  ofVertex(x-gw, y+gh);
  ofEndShape(true);
  
  if(shiftCounter <= dimensions.width) {
    shiftCounter+=gw;
  } else {
    if(rowCounter < dimensions.height){
      shiftCounter = 0;
      rowCounter+=gh;
    } else if (rowCounter >= dimensions.height) {
      shiftCounter = 0;
      rowCounter = 0;
    }
  }
  frame.end();
}