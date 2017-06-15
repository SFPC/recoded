
#include "mgsRileyDescending.h"
#include "appConstants.h"
int lineColor = 0;
int strokeColor = 0;
int fillColor = 0;

//<<<<<<< HEAD
//=======
int rows=107;
int columns=10;
int numOfWaves=5;

// vector<vector<float>> myLines;

// myLines = { x, y, columns, rows, speed, accel, wavePeriod, wavePhase, distance };
// void loadLine(x,y,cols,rows,speed,accel,wavePeriod,wavePhase,distance){
//   myLines.push_back(x,y,cols,rows,speed,accel,wavePeriod,wavePhase,distance);     
// }

// void getLineX(int lineNumber){

// }

//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
// addQuadToMesh:
// Vertices should go in the following order
// p0---------p1
// |           |
// |           |
// p2---------p3
void addQuadToMesh(ofMesh& m, const ofVec3f& p0, const ofVec3f& p1, const ofVec3f& p2, const ofVec3f& p3){
  int i = m.getNumVertices();
  m.addVertex(p0);
  m.addVertex(p1);
  m.addVertex(p2);
  m.addVertex(p3);
  m.addIndex(i);
  m.addIndex(i+1);
  m.addIndex(i+2);
  m.addIndex(i);
  m.addIndex(i+2);
  m.addIndex(i+3);    
}

void mgsRileyDescending::setup(){
//<<<<<<< HEAD
//  loadCode("mgsScene/exampleCode.cpp");  
//  parameters.add(rows.set("Rows", 120, 1, 200));
//  rows.addListener(this, &mgsRileyDescending::setupLines);
//  
//  parameters.add(columns.set("Columns", 9, 1, 100));
//  columns.addListener(this, &mgsRileyDescending::setupLines);
//
//  parameters.add(lineSpacing.set("Interval Height", 10.0, 1, 100));
//  parameters.add(lineWidth.set("Line Width", 55.0, 1, 300));
//  parameters.add(lineHeight.set("Line Height", 5.0, 1, 100));
//
//  parameters.add(minPeriod.set("Min Period", -10, -100, 0));
//  minPeriod.addListener(this, &mgsRileyDescending::setupLines);
//  parameters.add(maxPeriod.set("Max Period", 10, 0, 100));
//  maxPeriod.addListener(this, &mgsRileyDescending::setupLines);
//  parameters.add(minDelta.set("Min Delta", 0.5, 0.0, 4.0));
//  minDelta.addListener(this, &mgsRileyDescending::setupLinesF);
//  parameters.add(maxDelta.set("Max Delta", 4.0, 0.0, 10.0));
//  maxDelta.addListener(this, &mgsRileyDescending::setupLinesF);
//  parameters.add(minAlpha.set("Minimum Alpha", 0, 0, 360));
//  minAlpha.addListener(this, &mgsRileyDescending::setupLines);
//  parameters.add(maxAlpha.set("Maximum Alpha", 360, 0, 360));
//  maxAlpha.addListener(this, &mgsRileyDescending::setupLines);
//  parameters.add(minPhase.set("Minimum Phase", 0, 0, 360));
//  minPhase.addListener(this, &mgsRileyDescending::setupLines);
//  parameters.add(maxPhase.set("Maximum Phase", 360, 0, 360));
//
//
//  
//  quad1.setMode(OF_PRIMITIVE_TRIANGLES);
//  quad2.setMode(OF_PRIMITIVE_TRIANGLES);
//  quad1.disableColors();
//  quad1.disableColors();
//  
//  lines.clear();
//  for (int i = 0; i < columns; i++) {
//    lines.push_back(Line(i, columns, rows,ofRandom(minAlpha,maxAlpha),
//                         ofRandom(minPeriod,maxPeriod),
//                         ((504.0 / columns) / 3.0),
//                         ofRandom(minDelta,maxDelta),
//                         ofRandom(minPhase,maxPhase)));
//=======
  setAuthor("Michael Simpson");
  setOriginalArtist("Bridget Riley");
  //- Study for Shuttle - 1964");
  loadCode("scenes/mgsRileyDescending/exampleCode.cpp");
  

  rows.set("Rows", 109, 1, 200);
  //rows.addListener(this, &mgsRileyDescending::setupLinesF);
  
  parameters.add(lineHeight.set("Row Height", 5.67717, 1, 100));
  //lineHeight.addListener(this, &mgsRileyDescending::setupLinesF);

  columns.set("Columns", 19, 1, 200);
  //columns.addListener(this, &mgsRileyDescending::setupLinesF);
  
  parameters.add(lineWidth.set("Column Width", 60.0, 1, 300));
  //lineWidth.addListener(this, &mgsRileyDescending::setupLinesF);
  
  parameters.add(lineSpacing.set("Depth Amount", 14.8061, 1, 100));
  //lineSpacing.addListener(this, &mgsRileyDescending::setupLinesF);
  
    wavePeriodParam.set("Number of Waves", 2, 0, 60);
  //wavePeriodParam.addListener(this, &mgsRileyDescending::setupLinesF);
  
    wavePhaseParam.set("Wave Phase", 180.0, 0, 360);
  //wavePhaseParam.addListener(this, &mgsRileyDescending::setupLinesF);
  
    distanceParam.set("Distance Between", 15.8163, 1, 100);
  //distanceParam.addListener(this, &mgsRileyDescending::setupLinesF);

  parameters.add(speedParam.set("Speed", 4.0, 0.0, 5.0));
  //speedParam.addListener(this, &mgsRileyDescending::setupLinesF);

    accelParam.set("Acceleration", 360.0, 1, 360);
  //accelParam.addListener(this, &mgsRileyDescending::setupLinesF);
  
  animated.set("Animated", true);
  //  animated.addListener(this, &mgsRileyDescending::setupLinesB);
  
//  parameters.add(yOffset.set("Y-Offset", ));
//  
//  xOffset, lineWidth, lineHeight, lineSpacing, minWavePeriod, maxWavePeriod, minAccel, maxAccel, minWavePhase, maxWavePhase, <#Args &parameters...#>)
  quad1.setMode(OF_PRIMITIVE_TRIANGLES);
  quad2.setMode(OF_PRIMITIVE_TRIANGLES);
  quad3.setMode(OF_PRIMITIVE_TRIANGLES);
  quad4.setMode(OF_PRIMITIVE_TRIANGLES);
  quad1.disableColors();
  quad2.disableColors();
  quad3.disableColors();
  quad4.disableColors();
  
  xOffset = -300;
  yOffset = -100;

  lines.clear(); 

  for (int i = 0; i < columns; i++) {
    lines.push_back(RileyLine(columns, rows, speedParam, accelParam, wavePeriodParam, distanceParam, wavePhaseParam));
    //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
  }
}

void mgsRileyDescending::update() {
    
}

void mgsRileyDescending::draw() {
  ofBackground(0);
  ofSetColor(fillColor);
  ofFill();
  for (int x = 0; x < columns; x++) {
//<<<<<<< HEAD
//    lines[x].update(lineSpacing, lineHeight, rows);
//    quad1.clear();
//    quad2.clear();
//    for (int y = 0; y < rows - 1; y++) {
//      float x0 = (x + .5) * lineWidth + lines[x].getX(y);
//      float y0 = lines[x].getY(y);
//      float x1 = (x + .5) * lineWidth + lines[x].getX(y + 1);
//      float y1 = lines[x].getY(y + 1);
//      if ((y & 1) == 0) {
//        if ((x != 0 && y != 3)) {
//          ofSetColor(210,210,200);
//          ofFill();
//          addQuadToMesh(quad1,
//                        ofVec3f(x * lineWidth, y * lineHeight, 0),
//                        ofVec3f(x0, y0, 0),
//                        ofVec3f(x1, y1, 0),
//                        ofVec3f(x * lineWidth, (y + 1) * lineHeight, 0));
//          quad1.draw();
//        }
//        if ((x != columns-1 && y != rows-1)) {
//          ofSetColor(210,210,200);
//          ofFill();
//          addQuadToMesh(quad2,
//                        ofVec3f(x0, y0, 0),
//                        ofVec3f((x + 1) * lineWidth, y * lineHeight, 0),
//                        ofVec3f((x + 1) * lineWidth, (y + 1) * lineHeight, 0),
//                        ofVec3f(x1, y1, 0));
//          quad2.draw();
//=======
//    if(animated){
      lines[x].speed = speedParam;
//    } else {
//      lines[x].speed = 0;
//    }
    if (oldColumns == floor(columns) && oldRows == floor(rows)){
      
    } else {
      
    oldColumns = floor(columns);
    oldRows = floor(rows);
    lines.clear();
    for (int i = 0; i < columns; i++) {
      lines.push_back(RileyLine(columns, rows, speedParam, accelParam, wavePeriodParam, distanceParam, wavePhaseParam));
    }
    }

    lines[x].update(lineSpacing, lineHeight, rows, distanceParam);

    quad1.clear();
    quad2.clear();
    quad3.clear();
    quad4.clear();

    for(int y = 0; y < rows - 1; y++) {
      float x0 = (x + .5) * lineWidth + lines[x].X(y);
      float y0 = lines[x].Y(y);
      float x1 = (x + .5) * lineWidth + lines[x].X(y + 1);
      float y1 = lines[x].Y(y + 1);
      if ((y & 1) == 0) {
        if ((x != 0 && y != 3)) {
          ofSetColor(255);
          ofFill();
          addQuadToMesh(quad1,
                        ofVec3f((x * lineWidth)+xOffset, (y * lineHeight)+yOffset, 0),
                        ofVec3f(x0+xOffset, y0+yOffset, 0),
                        ofVec3f(x1+xOffset, y1+yOffset, 0),
                        ofVec3f((x * lineWidth)+xOffset, ((y + 1) * lineHeight)+yOffset, 0));
          quad1.draw();
          ofSetColor(0);
          ofFill();
          addQuadToMesh(quad3,
                        ofVec3f((x * lineWidth)+xOffset, ((y * lineHeight)-lineHeight)+yOffset, 0),
                        ofVec3f(x0+xOffset, (y0-lineHeight)+yOffset, 0),
                        ofVec3f(x1+xOffset, (y1-lineHeight)+yOffset, 0),
                        ofVec3f((x * lineWidth)+xOffset, (((y + 1) * lineHeight)-lineHeight)+yOffset, 0));
          quad3.draw();
        }
        if(x != columns-1 && y != rows-1) {
          ofSetColor(255);
          ofFill();
          addQuadToMesh(quad2,
                        ofVec3f(x0+xOffset, y0+yOffset, 0),
                        ofVec3f(((x + 1) * lineWidth)+xOffset, (y * lineHeight)+yOffset, 0),
                        ofVec3f(((x + 1) * lineWidth)+xOffset, ((y + 1) * lineHeight)+yOffset, 0),
                        ofVec3f(x1+xOffset, y1+yOffset, 0));
          quad2.draw();
          ofSetColor(0);
          ofFill();
          addQuadToMesh(quad4,
                        ofVec3f(x0+xOffset, y0-lineHeight+yOffset, 0),
                        ofVec3f(((x + 1) * lineWidth)+xOffset, ((y * lineHeight)-lineHeight)+yOffset, 0),
                        ofVec3f(((x + 1) * lineWidth)+xOffset, (((y + 1) * lineHeight)-lineHeight)+yOffset, 0),
                        ofVec3f(x1+xOffset, (y1-lineHeight)+yOffset, 0));
          quad4.draw();
          //>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
        }
      }
    }
  }
}

//<<<<<<< HEAD
//void mgsRileyDescending::setupLinesF(float& l){
//  lines.clear();
//  for (int i = 0; i < columns; i++) {
//    lines.push_back(Line(i, columns, rows,
//                         ofRandom(minAlpha,maxAlpha),
//                         ofRandom(minPeriod,maxPeriod),
//                         ((504.0 / columns) / 3.0),
//                         ofRandom(minDelta,maxDelta),
//                         ofRandom(minPhase,maxPhase)));
//  }
//}
//
//void mgsRileyDescending::setupLines(int& l){
//  lines.clear();
//  for (int i = 0; i < columns; i++) {
//    lines.push_back(Line(i, columns, rows,
//                         ofRandom(minAlpha,maxAlpha),
//                         ofRandom(minPeriod,maxPeriod),
//                         ((504.0 / columns) / 3.0),
//                         ofRandom(minDelta,maxDelta),
//                         ofRandom(minPhase,maxPhase)));
//  }
//}
//=======
void mgsRileyDescending::setupLinesB(bool& l) {
  // lines.clear();
  // for (int i = 0; i < columns; i++) {
  //   lines.push_back(RileyLine(i, columns, rows, speedParam, accelParam, wavePeriodParam, distanceParam, wavePhaseParam));
  // }
}

void mgsRileyDescending::setupLinesF(float& l) {
//  lines.clear();
//  for (int i = 0; i < columns; i++) {
//    lines.push_back(RileyLine(columns, rows, speedParam, accelParam, wavePeriodParam, distanceParam, wavePhaseParam));
//  }
  setupNewLines();
}

void mgsRileyDescending::setupNewLines() {
  if (oldColumns == floor(columns) && oldRows == floor(rows)) return;
  oldColumns = floor(columns);
  oldRows = floor(rows);
  lines.clear();
  for (int i = 0; i < columns; i++) {
    lines.push_back(RileyLine(columns, rows, speedParam, accelParam, wavePeriodParam, distanceParam, wavePhaseParam));
  }
}
//>>>>>>> 708c864d367c75773ca8168ac961c5e7f26d86d5
