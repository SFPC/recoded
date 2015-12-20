#include "mgsRileyEllipsesAndSquares.h"

vector<ofPoint> points;
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
  frame.begin();
  ofClear(0);
  frame.end();
  drawScene();
}

void mgsRileyEllipsesAndSquares::update(){
    //if (bNeedRedraw) {
        drawScene();
//        bNeedRedraw = false;
//    }
}

void mgsRileyEllipsesAndSquares::draw(){
  frame.draw(0,0);
}

void mgsRileyEllipsesAndSquares::redraw(int& i){
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
    }
  }
  frame.end();
}
