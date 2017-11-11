
#include "jacobsonMolnar_02.h"

void jacobsonMolnar_02::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);

    
    framePad = 0.95;
    countBoxes = 10;
    
    stepSize.set("stepSize", 7, 3, 20);
    parameters.add(stepSize);
    rotationSpeed.set("rotationSpeed", 5, 3, 50);
    parameters.add(rotationSpeed);
    setAuthor("Matt Jacobson");
    setOriginalArtist("Vera Molnar");
    
    loadCode("scenes/jacobsonMolnar_02/exampleCode.cpp");
}

void jacobsonMolnar_02::update(){
    
}

void jacobsonMolnar_02::draw(){
    
    ofBackground(0);
    ofSetColor(255);
    
    ofTranslate(dimensions.width / 2, dimensions.height / 2);
    
    ofNoFill();
    
    ofSeedRandom(0);
    
    float screenSideLength = MIN(dimensions.width, dimensions.height);
    float sideLength = framePad * screenSideLength / countBoxes;
    
    ofPath grid;
    
    for (int i = 0; i < countBoxes; i++) {
        for (int j = 0; j < countBoxes; j++) {
            float cx = ofMap(i, 0, countBoxes, -framePad * screenSideLength / 2, framePad * screenSideLength / 2) + sideLength / 2;
            float cy = ofMap(j, 0, countBoxes, -framePad * screenSideLength / 2, framePad * screenSideLength / 2) + sideLength / 2;
            for (int n = 0; n < 4; n++) {
                float t = ofMap(n, 0, 4, 0, 2 * PI) + PI / 4;
                float r = sqrt(2 * pow(sideLength / 2, 2));
                float x = cx + r * cos(t);
                float y = cy + r * sin(t);
                if (n == 0) grid.moveTo(x, y);
                else grid.lineTo(x, y);
            }
            grid.close();
        }
    }
    
    for (int i = 0; i < grid.getOutline().size(); i++) {
        ofPolyline box = grid.getOutline()[i];
        ofPath lineFill = getLineFill(box, stepSize, ofRandom(0, 360) + pow(-1, int(round(ofRandom(1)))) * rotationSpeed * ofGetElapsedTimef());
        for (int j = 0; j < lineFill.getOutline().size(); j++) {
            ofPolyline line = lineFill.getOutline()[j];
            ofSetLineWidth(1);
            line.draw();
        }
    }
    
}

ofPath jacobsonMolnar_02::getLineFill(ofPolyline _p, float _s, float _t) {
    ofPath result;
    
    vector<ofPoint> v = _p.getVertices();
    ofPoint c = _p.getCentroid2D();
    
    float xMin = 100000;
    float xMax = -100000;
    float yMin = 100000;
    float yMax = -100000;
    for (int i = 0; i < v.size(); i++) {
        v[i] -= c;
        v[i].rotate(_t, ofVec3f(0, 0, 1));
        xMin = MIN(xMin, v[i].x);
        xMax = MAX(xMax, v[i].x);
        yMin = MIN(yMin, v[i].y);
        yMax = MAX(yMax, v[i].y);
    }
    
    for (float y = yMin + _s; y < yMax; y += _s) {
        float xIntersectStart = xMax;
        float xIntersectEnd = xMin;
        for (int i = 0; i < v.size(); i++) {
            ofPoint s = v[i];
            ofPoint e = v[(i + 1) % v.size()];
            float xIntersect = (y - s.y) * (e.x - s.x) / (e.y - s.y) + s.x;
            if (MIN(s.x, e.x) < xIntersect && MAX(s.x, e.x) > xIntersect) {
                xIntersectStart = MIN(xIntersectStart, xIntersect);
                xIntersectEnd = MAX(xIntersectEnd, xIntersect);
            }
        }
        result.moveTo(xIntersectStart, y);
        result.lineTo(xIntersectEnd, y);
        result.close();
    }
    
    result.rotate(-_t, ofVec3f(0, 0, 1));
    result.translate(c);
    
    return result;
}
