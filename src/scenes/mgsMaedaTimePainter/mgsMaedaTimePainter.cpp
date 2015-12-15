#include "mgsMaedaTimePainter.h"

vector<TimePainter> painters;
int numberOfPainters = 50;
int currentPainter = 0;

void mgsMaedaTimePainter::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
  parameters.add(paintSpeed.set("Paint Speed", 0.8, 0.25, 10.0));
  paintSpeed.addListener(this, &mgsMaedaTimePainter::redrawFloat);
  parameters.add(baseLongevity.set("Longevity", 325, 100, 1000));
  baseLongevity.addListener(this, &mgsMaedaTimePainter::redrawInt);
  parameters.add(size.set("Ball Size", 3, 1, 50));
  size.addListener(this, &mgsMaedaTimePainter::redrawInt);
  parameters.add(lineWeight.set("Line Weight", 2.0, 0.25, 50));
  lineWeight.addListener(this, &mgsMaedaTimePainter::redrawFloat);
  
  loadCode("mgsMaedaTimePainter/exampleCode.cpp");
  //ofBackground(0);
  painters.clear();
  for (int i = 0; i < numberOfPainters; i++) {
    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
  }

  ofSetCircleResolution(100);
  frame.allocate(dimensions.width, dimensions.height);
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsMaedaTimePainter::update(){
  drawScene();
}

void mgsMaedaTimePainter::draw(){
  frame.draw(0,0);
}

void mgsMaedaTimePainter::redraw(int& i){
  drawScene();
}

void mgsMaedaTimePainter::redrawInt(int& i){
  ofClear(0);
  painters.clear();
  for (int i = 0; i < numberOfPainters; i++) {
    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
  }
  drawScene();
}

void mgsMaedaTimePainter::redrawFloat(float& i){
  ofClear(0);
  painters.clear();
  for (int i = 0; i < numberOfPainters; i++) {
    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
  }
  drawScene();
}

void mgsMaedaTimePainter::drawScene(){
  frame.begin();
  //for (int i = 0; i < numberOfPainters; i++) {
  if (currentPainter < numberOfPainters-1) {  
    if(painters[currentPainter].longevity > 0){
      painters[currentPainter].update(currentPainter);
    } else {
      painters[currentPainter].reset();
      currentPainter++;
    }
  } else {
    painters[currentPainter].reset();
    currentPainter = 0;
  }
    // } else {
    //   painters[currentPainter].reset();
    //   currentPainter = 0;
      //ofBackground(0);
      //}
//}  
  frame.end();
}

