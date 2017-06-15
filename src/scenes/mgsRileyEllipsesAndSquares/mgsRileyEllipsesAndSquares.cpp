#include "mgsRileyEllipsesAndSquares.h"

vector<ofPoint> points;
//<<<<<<< HEAD
//
//void mgsRileyEllipsesAndSquares::setup(){
//  
//// setup pramaters
////    param.set("param", 5, 0, 100);
////    parameters.add(param);
//  parameters.add(shapeMode.set("Shape Mode", 0, 0, 5));
//  shapeMode.addListener(this, &mgsRileyEllipsesAndSquares::redraw);
//  parameters.add(unitSize.set("Unit Size", 6, 1, 50));
//  unitSize.addListener(this, &mgsRileyEllipsesAndSquares::redraw);
//  parameters.add(contrast.set("Unit Size", 6, 1, 50));
//  contrast.addListener(this, &mgsRileyEllipsesAndSquares::redraw);
//  loadCode("mgsRileyEllipsesAndSquares/exampleCode.cpp");
//
//;
//
// ofBackground(255);
//  ofSetCircleResolution(100);
//  frame.allocate(dimensions.width, dimensions.height);
//=======
float px0,py0,px1,py1,px2,py2,px3,py3,px4,py4,px5,py5,px6,py6,px7,py7;

void mgsRileyEllipsesAndSquares::setup(){
  setAuthor("Michael Simpson");
  setOriginalArtist("Bridget Riley");
  //- Hidden Squares - 1990");
  px0 = 66;
  py0 = 97;
  px1 = 260;
  py1 = 310;
  px2 = 320;
  py2 = 100;
  px3 = 440;
  py3 = 270;
  px4 = 69;
  py4 = 349;
  px5 = 320;
  py5 = 430;
  px6 = 330;
  py6 = 320;
  px7 = 434;
  py7 = 429;
  
    bNeedRedraw = false;
    
  parameters.add(unitSize.set("Unit Size", 6, 2, 8));
  unitSize.addListener(this, &mgsRileyEllipsesAndSquares::redraw);
  loadCode("scenes/mgsRileyEllipsesAndSquares/exampleCode.cpp");

  ofBackground(255);
  ofSetCircleResolution(100);
  frame.allocate(dimensions.width, dimensions.height, GL_RGB32F_ARB);
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsRileyEllipsesAndSquares::update(){
  //<<<<<<< HEAD
    
  //=======
    //if (bNeedRedraw) {
        drawScene();
//        bNeedRedraw = false;
//    }
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
}

void mgsRileyEllipsesAndSquares::draw(){
  frame.draw(0,0);
}

void mgsRileyEllipsesAndSquares::redraw(int& i){
//<<<<<<< HEAD
//  drawScene();
//}
//// points.push_back(ofPoint(80,100));
//// points.push_back(ofPoint(260,310));
//
//// points.push_back(ofPoint(320,100));
//// points.push_back(ofPoint(430,270));
//
//// points.push_back(ofPoint(80,360));
//// points.push_back(ofPoint(320,430));
//
//// points.push_back(ofPoint(330,320));
//// points.push_back(ofPoint(430,4300));
//
//// //---
//
//// points.push_back(ofPoint(70,100));
//// points.push_back(ofPoint(260,310));
//
//// points.push_back(ofPoint(310,100));
//// points.push_back(ofPoint(430,270));
//
//// points.push_back(ofPoint(70,360));
//// points.push_back(ofPoint(310,430));
//
//// points.push_back(ofPoint(320,430));
//// points.push_back(ofPoint(320,430));
//
// 
//void mgsRileyEllipsesAndSquares::drawScene(){
//  frame.begin();
//  ofClear(0);
//  for (int i = 0; i < dimensions.width; i+=unitSize) {
//    for (int j = 0; j < dimensions.height; j+=unitSize) {
//      if (i/unitSize % 2 == 0 && j/unitSize % 2 == 0) {
//        if ((i>=80  && i<=260 && j>=100 && j<=310)  ||
//            (i>=320 && i<=440 && j>=100 && j<=270)  ||
//            (i>=80  && i<=320 && j>=360 && j<=440)  ||
//            (i>=330 && i<=440 && j>=320 && j<=440)) {
//          switch(shapeMode){
//          case 0:
//            ofDrawRectangle(i, j, unitSize, unitSize);
//            break;
//          case 1:
//            ofDrawEllipse(i-(1.5*unitSize), j-unitSize/2, unitSize, unitSize);
//            break;  
//          }
//        } else { 
//          switch(shapeMode){
//          case 0:
//            ofDrawEllipse(i+unitSize/2, j+unitSize/2, unitSize, unitSize);
//            break;
//          case 1:
//            ofDrawRectangle(i+unitSize, j+unitSize, unitSize, unitSize);
//            break;  
//          }
//        }
//      } else {
//        if (i/unitSize % 2 == 0 || j/unitSize % 2 == 0) {
//          if ((i >= 70 && i <= 260 && j >= 100 && j <= 310) ||
//              (i >= 310 && i <= 430 && j >= 100 && j <= 270) ||
//              (i >= 70 && i <= 310 && j >= 360 && j <= 430) ||
//              (i >= 320 && i <= 430 && j >= 320 && j <= 430)) {
//            switch(shapeMode){
//            case 0:
//              ofDrawRectangle(i+unitSize, j, unitSize, unitSize);
//              break;
//            case 1:
//              ofDrawEllipse(i+unitSize/2, j+unitSize/2, unitSize, unitSize);
//              break;  
//            } 
//          } else if (j/unitSize % 2 == 0) {        
//            switch(shapeMode){
//            case 0:
//              ofDrawEllipse(i+unitSize/2, j+unitSize*1.5, unitSize, unitSize);
//              break;
//            case 1:
//              ofDrawRectangle(i, j, unitSize, unitSize);
//              break;  
//            } 
//          }
//        }
//      }
//=======
    bNeedRedraw = true;
  //  drawScene();
}

void mgsRileyEllipsesAndSquares::drawScene(){
  frame.begin();
    ofSetColor(0, 20);
    ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
    ofSetColor(255);
  for (float i = 0; i < dimensions.width; i+=unitSize) {
    for (float j = 0; j < dimensions.height; j+=unitSize) {
      if ((int)(i/unitSize) % 2 == 0 && (int)(j/unitSize) % 2 == 0) {
        if ((i > px0 && i < px1 && j > py0 && j < py1)  ||
            (i > px2 && i < px3 && j > py2 && j < py3)  ||
            (i > px4 && i < px5 && j > py4 && j < py5)  ||
            (i > px6 && i < px7 && j > py6 && j < py7)) {
          ofDrawRectangle(i+unitSize, j+unitSize, unitSize, unitSize);
          ofDrawRectangle(i, j, unitSize, unitSize);
        } else { 
          ofDrawEllipse(i+unitSize/2, j+unitSize/2, unitSize, unitSize);
          ofDrawEllipse(i+unitSize/2+unitSize, j+unitSize/2+unitSize, unitSize, unitSize);
        }
      }      
      //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
    }
  }
  frame.end();
}
