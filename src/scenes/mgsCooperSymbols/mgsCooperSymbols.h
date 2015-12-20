#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mgsCooperSymbols : public baseScene {
  
public:
  int lineCounter=0;
  float rowCounter=0;
  float shiftCounter=0;
  
  void setup();
  void update();
  void draw();
  void reset();
  void drawGrid(float x, float y);
  void drawFullGrid(float x, float y);
  void drawShape(int mode);
  bool randomBool();
  void randomStroke();
  void randomFill();
  void drawSquare(float x, float y, float s);
  void drawTri(float x, float y, float s);
  void drawCircle(float x, float y, float s);
  void setupParameters();
  void clearScreen(int r, int g, int b, int a);
  void clearCell(float x, float y, float w, float h);
  void debugGrid();
  
  void drawScene();
  void drawFullScene();
  void drawCursor();
  void incrementCursor();
  void redraw(int& i);
  void redrawFloat(float& i);
  void redrawBool(bool& i);

  void redrawGrid(int& i);
  
  ofParameter<int> gridSize,fadeLength, numberOfShapes, red, green, blue;
  ofParameter<float> thickness, spacer, mod;
  ofParameter<bool> animated, randomStrokeP, singleShapesP, secondGridP, arcInsteadOfCircleP, debug;
  
  ofPath path;
  ofPolyline curve;
  ofFbo frame;
  ofColor clearColor, symbolColor, cursorColor;
  float gh,gw,lineWidth;
  int alpha;
  bool bNeedsRedraw, bNeedRedrawFullScene;
};