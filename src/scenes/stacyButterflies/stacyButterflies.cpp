
#include "stacyButterflies.h"
void Butterfly::setup(float width, float height){
    
    loc = ofPoint(ofRandom(-width/2, width/2),
                  ofRandom(-height/2, height/2)
                  );
    color.setHsb(ofMap(loc.x, -width/2, width/2, 5, 35),
                 100,
                 230);
    speed = ofRandom(.8, 1.2);
//    color = ofColor(127 + 127 * sin(loc.x * .010),
//                    127 + 127 * sin(loc.y * .011),
//                    127 + 127 * sin( * .012));
    angle = ofRandom(-50,50);
    font.load("fonts/avenir.otf", 30);
}

void Butterfly::draw(){
    ofPushMatrix();
    ofTranslate(loc);
    ofRotateZ(angle);
    for (int i = 0; i < 2; i++){
        int dir = i*2-1;
        ofPushMatrix();
        ofRotateY(ofMap(dir*sin(speed*ofGetElapsedTimef()), -1, 1, -40, 40) + i*100);
        //            //6
        //            //156
        //            //901
        ofSetColor(color);
        font.drawString("butter\nfly", 0, 0);
        ofPopMatrix();
    }
    ofPopMatrix();
}

void stacyButterflies::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in stacyButterflies.h
    //parameters.add(param.set("param", 5, 0, 100));

	
    for (int i = 0; i < 3; i++) {
        Butterfly b;
        b.setup(dimensions.width, dimensions.height);
        //        b.color = ofColor( 127 + 127 * sin(i*35 * .010),
        //                           127 + 127 * sin(i*35 * .011),
        //                           127 + 127 * sin(i*35 * .012));
        butterflies.push_back(b);
    }
    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");
    
    loadCode("scenes/stacyButterflies/exampleCode.cpp");
}

void stacyButterflies::update(){
    
}

void stacyButterflies::draw(){
    ofBackground(0);
    easycam.enableOrtho();
    easycam.begin();
    ofRotateX(143);
    ofRotateZ(183);
    for (int j = 0; j<butterflies.size(); j++) {
        butterflies[j].draw();
    }
     easycam.end();

    

//// - butterfly on crack -
//    easycam.begin();
//    for (int i = 0; i < 2; i++){
//        for (int j = 0; j < 50; j++){
//            ofRotateY(ofMap(ofGetElapsedTimef(), -1, 1, -20, 20) + i*100);
//            ofRotateX(901);
//            //6
//            //156
//            //901
//            ofSetColor( 127 + 127 * sin(j*35 * 0.01),
//                       127 + 127 * sin(j*35 * 0.011),
//                       127 + 127 * sin(j*35 * 0.012));
//
//        font.drawString(myString, 0, 0);
//
//        }
//    }
//    easycam.end();
    
    
    
    
    
//    for (int i = 1; i<10; i++){
//    ofPushMatrix();
//    ofTranslate(0, stringHeight(....)*i);
//    ofScale(1, .9*i);
//    font.drawString(myString, 0, 0);
//    ofPopMatrix();
//    }


}
