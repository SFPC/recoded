
#include "mgsRileyDiamonds.h"
#include "appConstants.h"

//<<<<<<< HEAD
//float gh, gw;
//int counter = 0;
//vector<float> colorArray;
//
//void mgsRileyDiamonds::setup(){
//  parameters.add(grayscale.set("Grayscale", false));
//  parameters.add(height.set("Diamond Height", 25, 1, 500));
//  parameters.add(width.set("Diamond Width", 25, 1, 500));
//=======



void mgsRileyDiamonds::setup(){
  setAuthor("Michael Simpson");
  setOriginalArtist("Bridget Riley");
  //- November - 1990");
  parameters.add(grayscale.set("Grayscale", false));
  //parameters.add(sequentialShading.set("Sequential Shading", false));
  parameters.add(height.set("Diamond Height", 25.0, 1, 50));
  parameters.add(width.set("Diamond Width", 25.0, 1, 50));
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  parameters.add(red.set("Red Amount", 255, 0, 255));
  parameters.add(green.set("Green Amount", 255, 0, 255));
  parameters.add(blue.set("Blue Amount", 255, 0, 255));
  parameters.add(alpha.set("Alpha Amount", 255, 1, 255));
//<<<<<<< HEAD
//  width.addListener(this, &mgsRileyDiamonds::redraw);
//  height.addListener(this, &mgsRileyDiamonds::redraw);
//=======
  parameters.add(animated.set("Animated", true));
  parameters.add(discoMode.set("Disco Mode", false));
  width.addListener(this, &mgsRileyDiamonds::redrawFloat);
  height.addListener(this, &mgsRileyDiamonds::redrawFloat);
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  alpha.addListener(this, &mgsRileyDiamonds::redraw);
  red.addListener(this, &mgsRileyDiamonds::redraw);
  green.addListener(this, &mgsRileyDiamonds::redraw);
  blue.addListener(this, &mgsRileyDiamonds::redraw);
  grayscale.addListener(this, &mgsRileyDiamonds::redrawBool);
//<<<<<<< HEAD
//  
//  loadCode("mgsRileyDiamonds/exampleCode.cpp");
//  gh = dimensions.height/height;
//  gw = dimensions.width/width;
//  frame.allocate(dimensions.width, dimensions.height);
//  //  ofEnableSmoothing();
//  frame.begin();
//  ofClear(0);
//  frame.end();
//=======
  animated.addListener(this, &mgsRileyDiamonds::redrawBool);
  discoMode.addListener(this, &mgsRileyDiamonds::redrawBool);
  //sequentialShading.addListener(this, &mgsRileyDiamonds::redrawBool);
  
  loadCode("scenes/mgsRileyDiamonds/exampleCode.cpp");

  gh = dimensions.height/height;
  gw = dimensions.width/width;
    
//    bNeedRedraw = bNeedsFullRedraw = bNeedRedrawFloat = false;
//  
  frame.allocate(dimensions.width, dimensions.height);
  frame.begin();
  ofClear(0);
  frame.end();
  drawFullRiley();
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  drawRiley();
}

void mgsRileyDiamonds::update(){
//<<<<<<< HEAD
//  
//}
//
//void mgsRileyDiamonds::draw(){
//  frame.draw(0,0);
//}
//
//void mgsRileyDiamonds::redraw(int& i){
//  drawRiley();
//}
//
//void mgsRileyDiamonds::redrawBool(bool& i){
//  drawRiley();
//=======
//    if (bNeedRedraw) {
//        drawRiley();
//        bNeedRedraw = false;
//    }
//    if (bNeedsFullRedraw) {
//      drawFullRiley();
//        bNeedsFullRedraw = false;
//    }
//    if (bNeedRedrawFloat) {
           gh = dimensions.height/height;
           gw = dimensions.width/width;
//        bNeedRedrawFloat = false;
//    }
}

void mgsRileyDiamonds::draw(){
//  if(discoMode){
//    drawFullRiley();
//  } else if (animated) {

    drawRiley();
  //  }
  frame.draw(0,0);
}

void mgsRileyDiamonds::drawFullRiley(){
  frame.begin();
  ofClear(0);
  for(float x = 0; x < dimensions.width+gw; x += gw){
    for(float y = 0; y < dimensions.width+gh; y += gh){
      ofColor c = ofColor(ofRandom(0,red),ofRandom(0, green), ofRandom(0,blue),255);
      ofColor g = ofColor(ofRandom(0,255),255);

      if(grayscale){
        ofSetColor(g);
        ofFill();
      } else {
        ofSetColor(c);
        ofFill();
      }

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
     //       bNeedsFullRedraw = true;
//     frame.begin();
//     ofClear(0);
//     drawFullRiley();
//     frame.end();
   } else {
     gh = dimensions.height/height;
     gw = dimensions.width/width;
     //       bNeedRedraw = true;
       //drawRiley();
   }
 }

 void mgsRileyDiamonds::redrawFloat(float& i){
   //     bNeedRedrawFloat = true;
     //   gh = dimensions.height/height;
//   gw = dimensions.width/width;
//   frame.begin();
//   ofClear(0);
//   for(float x = 0; x < dimensions.width+gw; x += gw){
//     for(float y = 0; y < dimensions.width+gh; y += gh){
//       ofColor c = ofColor(ofRandom(0,red),ofRandom(0, green), ofRandom(0,blue),255);
//       ofColor g = ofColor(ofRandom(0,255),255);
//
//       if(grayscale){
//         ofSetColor(g);
//         ofFill();
//       } else {
//         ofSetColor(c);
//         ofFill();
//       }
//
//       ofBeginShape();
//       ofVertex(x-gw, y+gh);
//       ofVertex(x, y+gh);
//       ofVertex(x+gw, y);
//       ofVertex(x, y);
//       ofVertex(x-gw, y+gh);  
//       ofEndShape(true);
//     }
//   }
//   frame.end();
//   shiftCounter=0;
//   rowCounter=0;
   //drawRiley();
 }

void mgsRileyDiamonds::redrawBool(bool& i){
  gh = dimensions.height/height;
  gw = dimensions.width/width;
  
  //  if(!animated && grayscale){
  //      bNeedsFullRedraw = true;
//    drawFullRiley();
//  }
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
}

void mgsRileyDiamonds::drawRiley(){
  frame.begin();
//<<<<<<< HEAD
//  for (float i = -width; i <= dimensions.width+width; i+=width) {
//    for (float j = -height; j <= dimensions.height+height; j+=height) {
//      float r = (int)ofRandom(0,red);
//      float g = (int)ofRandom(0, green);
//      float b = (int)ofRandom(0,blue);
//      float gray = (int)ofRandom(0,255);
//
//      if(!grayscale){
//        ofSetColor(r, g, b, alpha);
//      } else {
//        ofSetColor(gray);
//      }
//      ofFill();
//      ofBeginShape();
//      ofVertex(i, j);
//      ofVertex(i, j+2*height);
//      ofVertex(i+width, j);
//      ofVertex(i+width, j-2*height);
//      ofEndShape(true);
//
//      if(!grayscale){
//        ofSetColor(r, g, b, alpha);
//      } else {
//        ofSetColor(gray, 255);
//      }
//      ofNoFill();
//      ofBeginShape();
//      ofVertex(i, j);
//      ofVertex(i, j+2*height);
//      ofVertex(i+width, j);
//      ofVertex(i+width, j-2*height);
//      ofEndShape(true);
//    }    
//=======

    ofSetColor(0, 1);
    ofDrawRectangle(0, 0, dimensions.width, dimensions.height);
  ofColor c = ofColor(ofRandom(0,red),ofRandom(0, green), ofRandom(0,blue),255);
  ofColor g = ofColor(ofRandom(0,255),255);
  if(grayscale){
    ofSetColor(g);
    ofFill();
  } else {
    ofSetColor(c);
    ofFill();
  }
  // Needs work...
  
  // if(sequentialShading){
  //   diamondCounter+=ofRandom(0.25,1);
  //   if(diamondCounter > 255 && diamondCounter < 510){
  //     ofSetColor(diamondCounter-255,0,0);
  //   } else if (diamondCounter > 510 && diamondCounter < 765) {
  //     ofSetColor(diamondCounter-510,diamondCounter-510,0);
  //   } else if (diamondCounter > 765 && diamondCounter < 1020) {
  //     ofSetColor(diamondCounter-765,diamondCounter-765,diamondCounter-765);
  //   } else if (diamondCounter > 1020 && diamondCounter < 1275){
  //     ofSetColor(255,255,255);
  //   } else {
  //     ofSetColor(diamondCounter);
  //   }
  //   ofFill();
  // } else if(grayscale){
  //   ofSetColor(g);
  //   ofFill();
  // } else {
  //   ofSetColor(c);
  //   ofFill();
  // }

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
    //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  }
  frame.end();
}
