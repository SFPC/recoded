#pragma once

#include "ofMain.h"
#include "baseScene.h"

//<<<<<<< HEAD
//class Line {
//  vector<float> x, y;// this way you declare more than one object of the same kind.
//  float alpha, delta, period, phase, radius;
//
// public:
//  Line(int i, int columnCount, int rowCount, int a, int p, int r, float d, int ph) {
//    alpha = a;
//    period = p;
//    radius = r;
//    delta = d;
//    phase = ph;
//=======
class RileyLine {
  vector<float> x, y;

 public:
  float accel, speed, wavePeriod, wavePhase, distance;

  RileyLine(int columnCount, int rowCount, float s, int a, int wp, int d, int wph) {
    speed = s;
    accel = a;
    wavePeriod = wp;
    distance = d;
    wavePhase = wph;
    //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
    x.resize(rowCount);
    y.resize(rowCount);
  }

//<<<<<<< HEAD
//  void update(float lineSpacing, float lineHeight, int rowCount) {
//    alpha += delta;
//    for (int i = 0; i < rowCount; i++) {
//      float angle = ofDegToRad(phase + alpha + (period * i));
//      x[i] = radius * sin(angle);
//      y[i] = lineSpacing + i * lineHeight;
//      //y[i] += lineHeight * 2.0 * cos(angle);
//    }
//  }
//
//  float getX(int i) {
//    return x[i];
//  }
//
//  float getY(int i) {
//=======
  void update(float lineSpacing, float lineHeight, int rowCount, float dist) {
    distance = dist;
    accel += speed;
    for (int i = 0; i < rowCount; i++) {
      x[i] = distance * sin(ofDegToRad(wavePhase + accel + (wavePeriod * i)));
      y[i] = lineSpacing + i * lineHeight;
    }
  }

  float X(int i) {
    return x[i];
  }

  float Y(int i) {
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
    return y[i];
  }
};

class mgsRileyDescending : public baseScene {   
 public:
  void setup();
  void update();
  void draw();
  void setupLines(int& l);
  void setupLinesF(float& l);
//<<<<<<< HEAD
//
//  ofMesh quad1;
//  ofMesh quad2;
//  vector<Line> lines;
//
//  ofParameter<float> lineWidth, lineHeight, lineSpacing, minDelta, maxDelta;
//  ofParameter<int> rows, columns, fillColor, bgColor, minPeriod, maxPeriod, minAlpha, maxAlpha, minPhase, maxPhase;
//=======
  void setupNewLines();
  void setupLinesB(bool& l);
  void drawGrid(int& l);
  void loadLine(float x, float y, float accel, float speed, float wavePeriod, float wavePhase, float distance);
  
  ofMesh quad1;
  ofMesh quad2;
  ofMesh quad3;
  ofMesh quad4;
  vector<RileyLine> lines;
  int oldRows, oldColumns;
  
  ofParameter<float>  minSpeed, maxSpeed, speedParam, wavePhaseParam, accelParam, wavePeriodParam, distanceParam, yOffset, xOffset, lineWidth, lineHeight, lineSpacing, minWavePeriod, maxWavePeriod, minAccel, maxAccel, minWavePhase, maxWavePhase, rows, columns;
  ofParameter<int>  fillColor, bgColor;
  ofParameter<bool> animated;
  //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
};
