#pragma once

#include "ofMain.h"
#include "baseScene.h"

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
    x.resize(rowCount);
    y.resize(rowCount);
  }

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
};
