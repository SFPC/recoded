
#include "zachTest.h"

void zachTest::setup(){
  
// setup pramaters
	heightScale.set("heightScale", 1, 0, 1);
    movementScale.set("movementScale", 1, 0, 10);
    
	parameters.add(heightScale);
    parameters.add(movementScale);

    setAuthor("Zach Lieberman");
    setOriginalArtist("John Whitney");
    
    loadCode("scenes/zachTest/exampleCode.cpp");
    
    for (int i =0; i < 8; i++){
        adders[i] = 0;
    }
    
    
    dir.listDir("scenes/zachTest/Donuts");
    for (int i = 0; i < dir.size(); i++){
        cout << dir.getPath(i) << endl;
        ofImage blah;
        images.push_back(blah);
        images.back().load(dir.getPath(i));
    }
    //std::exit(0);
}

void zachTest::update(){
    
}

void zachTest::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);

    //ofEnableDepthTest();
    cam.enableOrtho();
    cam.begin(dimensions);

    ofEnableAlphaBlending();
    ofPushMatrix();

   // ofRotateY(ofGetElapsedTimef()*100);

  //  ofTranslate(dimensions.width*0.5, dimensions.height*0.5);
  //  ofScale(0.2, 0.2);
    for (int i = 0; i < 100; i+=1){
        ofPushMatrix();
        ofTranslate(sin(i*0.1+ ofGetElapsedTimef())*300.0, sin(i*0.13+ ofGetElapsedTimef()*0.9)*300.0,sin(i*0.19 + ofGetElapsedTimef()*0.7)*300.0);

        //ofRotateX(ofGetMouseX());
        ofRotateZ(i*0.1 + ofGetElapsedTimef()*100);

        images[(int)(ofGetFrameNum()*0.1 + i * 0.1)%images.size()].draw(0,0, 300,300);
        ofPopMatrix();
    }

    ofPopMatrix();

    cam.end();
   ofSetRectMode(OF_RECTMODE_CORNER);
//
//    ofDisableDepthTest();
//    int grid = ofGetMouseX();
//    ofSetCircleResolution(100);
//
//    float ff = ofGetElapsedTimef();
//    for (int i = 0; i < dimensions.width/grid; i++){
//        for (int j = 0; j < dimensions.width/grid; j++){
//
//            ofPoint pt (i*grid,j*grid);
//            pt += ofPoint(grid, grid)*0.5;
//            ofPushMatrix();
//            ofTranslate(pt.x, pt.y);
//            if ((i+j) % 2 == 0) ofScale(sin(i*0.6+j*0.4+ff*3.0)*0.3 + 1.3, 1.0 );
//            else ofScale(1.0,sin(i*0.6+j*0.4+ff*3.0)*0.3 + 1.3 );
//            ofCircle(0,0,grid*0.2);
//            ofPopMatrix();
//
//        }
//    }
    
//    int colors[] = {0xffceff, 0xffffb8, 0x88b8ff,0xceff9f,0xcea0fe,0x55e5e5,0xffe5a0,0x6fff70,0xffa0ce,0xa0ffe4};
//
//    ofSetHexColor(0xffceff);
//    ofFill();
//    ofDrawRectangle(dimensions);
//
//    for (int i =0; i < 8; i++){
//        adders[i] += ofGetLastFrameTime() * movementScale * (i % 2 == 0 ? -1 : 1);
//    }
////
//    float h = dimensions.height / 8.0;
//
//    for (int i = 7; i >= 0; i--){
//
//        ofSetHexColor(colors[i+1]);
//
//        float amt = sin(i) * 10 + 20;
//
//        float amt2 = sin(i*0.4 + ofGetElapsedTimef()) * 0.2 + 0.8;
//        ofMesh m;
//     m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//        for (int j = 0; j < 100; j++){
//            float pct = ofMap(j, 0, 99, 0, 1);
//
//
//            m.addVertex( ofPoint(pct*dimensions.width, dimensions.height));
//            m.addVertex( ofPoint(pct*dimensions.width, (dimensions.height - h*i*heightScale) + sin(pct*amt +  adders[i]) * (h/2.0)*powf(heightScale, 0.3)*amt2));
//
//        }
//        m.draw();
//    }
    
    
}
