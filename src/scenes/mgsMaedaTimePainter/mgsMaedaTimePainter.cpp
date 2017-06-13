#include "mgsMaedaTimePainter.h"

vector<TimePainter> painters;
int numberOfPainters = 50;
int currentPainter = 0;
//<<<<<<< HEAD
//
//void mgsMaedaTimePainter::setup(){
//  
//// setup pramaters
////    param.set("param", 5, 0, 100);
////    parameters.add(param);
//  parameters.add(paintSpeed.set("Paint Speed", 0.8, 0.25, 10.0));
//  paintSpeed.addListener(this, &mgsMaedaTimePainter::redrawFloat);
//  parameters.add(baseLongevity.set("Longevity", 325, 100, 1000));
//  baseLongevity.addListener(this, &mgsMaedaTimePainter::redrawInt);
//  parameters.add(size.set("Ball Size", 4, 1, 50));
//  size.addListener(this, &mgsMaedaTimePainter::redrawInt);
//  parameters.add(lineWeight.set("Line Weight", 2.5, 0.25, 50));
//  lineWeight.addListener(this, &mgsMaedaTimePainter::redrawFloat);
//  
//  loadCode("mgsMaedaTimePainter/exampleCode.cpp");
//  //ofBackground(0);
//  painters.clear();
//  for (int i = 0; i < numberOfPainters; i++) {
//    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
//    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
//  }
//
//  ofSetCircleResolution(100);
//  frame.allocate(dimensions.width, dimensions.height);
//=======
int ellipseSize = 3;
int fadeCounter = 0;

void mgsMaedaTimePainter::setup(){
  parameters.add(paintSpeed.set("paintSpeed", 0.15, 2.0, 0.01));
  paintSpeed.addListener(this, &mgsMaedaTimePainter::redrawFloat);
  parameters.add(baseLongevity.set("baseLongevity", 120, 50, 500));
  baseLongevity.addListener(this, &mgsMaedaTimePainter::redrawInt);
  parameters.add(angleVariance.set("angleVariance", 5, 2, 10));
  angleVariance.addListener(this, &mgsMaedaTimePainter::redrawInt);
  parameters.add(animated.set("animated", true));
  animated.addListener(this, &mgsMaedaTimePainter::pause);
  parameters.add(lineWeight.set("lineWeight", 0.10, 0.10, 5.0));
  lineWeight.addListener(this, &mgsMaedaTimePainter::redrawFloat);
  
  parameters.add(fadeWhenDead.set("fadeWhenDead", true));
  fadeWhenDead.addListener(this, &mgsMaedaTimePainter::redrawBool);
  
  parameters.add(clearScreenP.set("clearScreen", false));
  clearScreenP.addListener(this, &mgsMaedaTimePainter::clearScreen);
  
    setAuthor("Michael Simpson");
  setOriginalArtist("John Maeda");
  //- Time Paint - 1990");
  loadCode("scenes/mgsMaedaTimePainter/exampleCode.cpp");
    
  painters.clear();
  for (int i = 0; i < numberOfPainters; i++) {
    painters.push_back(TimePainter(paintSpeed, baseLongevity, ellipseSize, lineWeight));
  }
  bNeedsRedraw = false;
  bNeedClearScreen = false;
  ofSetCircleResolution(100);
  frame.allocate(dimensions.width, dimensions.height, GL_RGBA32F_ARB);
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
//  //<<<<<<< HEAD
//}
//
//void mgsMaedaTimePainter::update(){
//=======

}

void mgsMaedaTimePainter::clearScreen(bool& i){
  //bNeedClearScreen = true;
  //  frame.begin();
  //  ofClear(0,10);
  //  frame.end();
  //  clearScreenP.set("Clear Screen", false);
}

void mgsMaedaTimePainter::pause(bool& i){
  paused = !paused;
}

void mgsMaedaTimePainter::update(){
  //if (bNeedsRedraw) {
//    frame.begin();
//    ofClear(0);
//    frame.end();
//    painters.clear();
    for (int i = 0; i < numberOfPainters; i++) {
      painters.push_back(TimePainter(paintSpeed, baseLongevity, ellipseSize, lineWeight));
    }
  //    drawScene();
  //  bNeedsRedraw = false;
  //}
//  if (bNeedClearScreen) {
//    frame.begin();
//    ofClear(0,10);
//    frame.end();
//    clearScreenP.set("Clear Screen", false);
//    bNeedClearScreen = false;
//  }
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  drawScene();
}

void mgsMaedaTimePainter::draw(){
//<<<<<<< HEAD
//=======
  if(fadeWhenDead){
    frame.begin();
    if(fadeCounter < 100){
      ofSetColor(0,1);
      ofDrawRectangle(0,0,dimensions.width,dimensions.height);
    } else {
      ofSetColor(0,2);
      ofDrawRectangle(0,0,dimensions.width,dimensions.height);
    }
    frame.end();
  }
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.draw(0,0);
}

void mgsMaedaTimePainter::redraw(int& i){
//<<<<<<< HEAD
//  drawScene();
//}
//
//void mgsMaedaTimePainter::redrawInt(int& i){
//  ofClear(0);
//  painters.clear();
//  for (int i = 0; i < numberOfPainters; i++) {
//    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
//    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
//  }
//  drawScene();
//}
//
//void mgsMaedaTimePainter::redrawFloat(float& i){
//  ofClear(0);
//  painters.clear();
//  for (int i = 0; i < numberOfPainters; i++) {
//    painters.push_back(TimePainter(paintSpeed, baseLongevity, size, lineWeight));     
//    //painter[i+2] = new myTimePainter(0.0, 0.0, 120.0, 0.80, 500, color(random(255),random(255),random(255)), 4);
//  }
//  drawScene();
//}
//
//void mgsMaedaTimePainter::drawScene(){
//  frame.begin();
//  //for (int i = 0; i < numberOfPainters; i++) {
//  if (currentPainter < numberOfPainters-1) {  
//    if(painters[currentPainter].longevity > 0){
//      painters[currentPainter].update(currentPainter);
//    } else {
//      painters[currentPainter].reset();
//      currentPainter++;
//    }
//  } else {
//    painters[currentPainter].reset();
//    currentPainter = 0;
//  }
//    // } else {
//    //   painters[currentPainter].reset();
//    //   currentPainter = 0;
//      //ofBackground(0);
//      //}
////}  
//  frame.end();
//}
//
//=======
  //drawScene();
}

void mgsMaedaTimePainter::redrawBool(bool& i){
  
}

void mgsMaedaTimePainter::redrawInt(int& i){
  bNeedsRedraw = true;
  //  painters.clear();
  //  for (int i = 0; i < numberOfPainters; i++) {
  //    painters.push_back(TimePainter(paintSpeed, baseLongevity, ellipseSize, lineWeight));
  //  }
  //  drawScene();
}

void mgsMaedaTimePainter::redrawFloat(float& i){
  bNeedsRedraw = true;
  //    frame.begin();
  //  ofClear(0);
  //  frame.end();
  ellipseSize = lineWeight*12;
  //  painters.clear();
  //  for (int i = 0; i < numberOfPainters; i++) {
  //    painters.push_back(TimePainter(paintSpeed, baseLongevity, ellipseSize, lineWeight));
  //  }
  //  drawScene();
}

void mgsMaedaTimePainter::drawScene(){
  if(!paused){
    frame.begin();
    //for (int i = 0; i < numberOfPainters; i++) {
    if (currentPainter < numberOfPainters-1) {
      if(painters[currentPainter].longevity > 0){
        painters[currentPainter].update(currentPainter,angleVariance);
      } else {
        painters[currentPainter].reset();
        currentPainter++;
      }
    } else {
      painters[currentPainter].reset();
      currentPainter = 0;
    }
    //}
    frame.end();
    fadeCounter++;
    if(fadeCounter>102){
      fadeCounter = 0;
    }
  }
}
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
