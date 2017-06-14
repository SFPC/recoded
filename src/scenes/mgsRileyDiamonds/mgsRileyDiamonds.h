#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mgsRileyDiamonds : public baseScene {
//<<<<<<< HEAD
//    
//public:
//    
//    void setup();
//    void update();
//    void draw();
//    void redraw(int& i);
//    void redrawBool(bool& i);
//    void drawRiley();
//    
//    //    ofParameter<float> param;
//    ofParameter<int> height, width, red, green, blue, alpha;
//    ofParameter<bool> grayscale;
//    ofFbo frame;
//=======

public:
    
    
  void setup();
  void update();
  void draw();
  void redraw(float& i);
  void redrawFloat(float& i);
  void redrawBool(bool& i);
  void drawRiley();
  void drawFullRiley();
  
  ofParameter<float> height, width,red, green, blue, alpha;
  ofParameter<bool> grayscale, animated, discoMode;
  
  ofFbo frame;
  float gh, gw;
  int counter = 0;
  vector<float> colorArray;
  float shiftCounter = 0;
  float rowCounter = 0;
  float diamondCounter = 0;
  
  bool bNeedRedraw, bNeedsFullRedraw, bNeedRedrawFloat;
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
};
