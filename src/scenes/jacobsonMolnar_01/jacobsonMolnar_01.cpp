
#include "jacobsonMolnar_01.h"

void jacobsonMolnar_01::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
    
    
    
    
    
    stepSizeMin.set("stepSizeMin", 2, 2, 10);
    stepSizeMax.set("stepSizeMax", 10, 10, 25);
    noiseResolution.set("noiseResolution", 0.001, 0.001, 0.01);
    timeScale.set("timeScale", 0.1, 0.1, 2);
    
    parameters.add(stepSizeMin);
    parameters.add(stepSizeMax);
    parameters.add(noiseResolution);
    parameters.add(timeScale);
    
    
    
    
    
    
    framePad = 0.99;
    density = 0.1;
    
    float m_density = min<float>(dimensions.width,dimensions.height) * density;
    vector<ofVec2f> m_samples = ofxPoissonDiskSampling::sample2D(framePad * dimensions.width, framePad * dimensions.height, m_density, false);
    
    origin = ofPoint(dimensions.width / 2, dimensions.height / 2);
    center = ofPoint((1 - framePad) * dimensions.width / 2, (1 - framePad) * dimensions.height / 2);
    
    for (ofVec2f p : m_samples) triangulation.addPoint(ofPoint(p.x, p.y) - origin + center);
    
    triangulation.triangulate();
    
    setAuthor("Matt Jacobson");
    setOriginalArtist("Vera Molnar");
    
    loadCode("scenes/jacobsonMolnar_01/exampleCode.cpp");
    
}

void jacobsonMolnar_01::update(){
    
}

void jacobsonMolnar_01::draw(){
    
    ofBackground(0);
    
    ofNoFill();
    ofSetColor(255);
    
    ofTranslate(dimensions.width / 2, dimensions.height / 2);
    
    vector<ofMeshFace> triangles = triangulation.triangleMesh.getUniqueFaces();
    
    for (int i = 0; i < triangles.size(); i++) {
        
        ofMeshFace triangle = triangles[i];
        
        ofPoint A = triangle.getVertex(0);
        ofPoint B = triangle.getVertex(1);
        ofPoint C = triangle.getVertex(2);
        
        float a = ofDist(B.x, B.y, C.x, C.y);
        float b = ofDist(A.x, A.y, C.x, C.y);
        float c = ofDist(A.x, A.y, B.x, B.y);
        float perimeter = a + b + c;
//        float area = 0.5 * ((A.x - C.x) * (B.y - A.y) - (A.x - B.x) * (C.y - A.y));
        
        
        float semiperimeter = perimeter / 2;
        float area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
        
        
        float inscribedRadius = 2 * abs(area) / perimeter;
        
        ofPoint incenter = ofPoint((a * A.x + b * B.x + c * C.x) / perimeter, (a * A.y + b * B.y + c * C.y) / perimeter);
        
        float stepSize = ofMap(ofNoise((noiseResolution * incenter).x, (noiseResolution * incenter).y, timeScale * ofGetElapsedTimef()), 0, 1, stepSizeMin, stepSizeMax);
        
        for (float n = stepSize; n < inscribedRadius; n += stepSize) {
            
            float scale = inscribedRadius / (inscribedRadius - n);
            
            ofPoint v0 = (A - incenter).scale((A - incenter).length() * (1 / scale)) + incenter;
            ofPoint v1 = (B - incenter).scale((B - incenter).length() * (1 / scale)) + incenter;
            ofPoint v2 = (C - incenter).scale((C - incenter).length() * (1 / scale)) + incenter;
            
            ofSetLineWidth(1);
            ofBeginShape();
            ofVertex(v0);
            ofVertex(v1);
            ofVertex(v2);
            ofEndShape(OF_CLOSE);
        }
    }
    
}
