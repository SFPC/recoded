#include "annMolnarRectangles.h"

//--------------------------------------------------------------
void annMolnarRectangles::setup(){
    
    ofBackground(226,223,232);
    addRepeat.set("Repeats", 0.,0.,20.);
    xPos.set("Horizontal stretch",10.,10.,50.);
    yPos.set("Vertical stretch",10.,10.,50.);
    
    parameters.add(addRepeat);
    parameters.add(xPos);
    parameters.add(yPos);
    
    setAuthor("ann tbd");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/annMolnarRectangles/exampleCode.cpp");
}
void annMolnarRectangles::update(){}
//--------------------------------------------------------------
void annMolnarRectangles::draw(){
    /*
     Recreation of Vera Molnar piece:
     https://image.invaluable.com/housePhotos/artcurial/23/301023/H1118-L22105038.jpg
     */
    
    ofSeedRandom(0);
    
    // draw background
    ofSetColor(226,223,232);
    ofFill();
    ofDrawRectangle(dimensions);
    
    ofSetLineWidth(1);
    
    
    ofSetColor(0);
    ofNoFill();
    
    ofColor myColors[6];
    
    //red
    myColors[0] = ofColor(88,0,0, 150);
    myColors[1] = ofColor(88,0,0, 150);
    
    //blue
    myColors[2] = ofColor(0,0,58,150);
    myColors[3] = ofColor(0,0,58,150);
    myColors[4] = ofColor(0,0,58,150);
    
    //orange
    myColors[5] = ofColor(179,74,36,150);
    
    for (int i=0; i<col;i++){
        for (int j=0;j<row;j++){
            // calculate number of rectangles to draw in each column
            int repeat;

            if (i<3){
                repeat = 1+i*i;
            } else if (i == 3) {
                repeat = 40;
            } else {
                int val = col-i;
                float f = val*val;
                repeat = static_cast<int>(f);
            }
            // draw rectangles
            int random_color;
            if (i == row) {
                random_color = ofRandom(1,row);
            } else {
                random_color = ofRandom(0,row);
            }
            repeat += addRepeat;
            
            ofSetColor( myColors[ (int) ofRandom(0,row)]);
            for (int k=0;k<repeat;k++){
                square(i,j);
            }
        }
    }
}

void annMolnarRectangles::square(int a, int b) {
    int padding_w = dimensions.width *.1;
    int inner_width = dimensions.width - padding_w * 2;
    
    int padding_h = dimensions.height *.2;
    int inner_height = dimensions.height - padding_h * 2;
    
    int square_w = inner_width / col * 0.6;
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    
        int start_x = padding_w+a*inner_width/col+ofRandom(-xPos,xPos);
        int start_y = padding_h+b*inner_height/row+ofRandom(-yPos,yPos);
        ofVertex(start_x, start_y);
        ofVertex(start_x+ofRandom(-xPos,xPos), start_y+square_w+ofRandom(-yPos,yPos));
        ofVertex(start_x+square_w+ofRandom(-xPos,xPos), start_y+square_w);
        ofVertex(start_x+square_w, start_y+ofRandom(-yPos,yPos));
    ofEndShape(true);
}
