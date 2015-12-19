
#include "veraAnimatedScene.h"


void veraAnimatedScene::setup(){
    
    size.set("size", 0.5, 0, 1);
    smoothing.set("smoothing", 0.8, 0, 1);
    opacity.set("opacity", 200, 0, 255);
    parameters.add(size);
    parameters.add(smoothing);
    parameters.add(opacity);
    
    for (int i = 0; i < 6; i++) {
        vector<vector<ShapePosition>> row;
        
        for (int j = 0; j < 6; j++) {
            
            vector<ShapePosition> col;
            
            int numShapes = 0;
            switch(j) {
                case 0:
                    numShapes = 5;
                    break;
                case 1:
                    numShapes = 25;
                    break;
                case 2:
                    numShapes = 10;
                    break;
                case 3:
                    numShapes = 6;
                    break;
                case 4:
                    numShapes = 3;
                    break;
                case 5:
                    numShapes = 2;
                    break;
            }
                
            for(int l = 0; l < numShapes; l++) {
                ShapePosition sp;
                
                sp.topLeft.set(dimensions.width/8 + i*dimensions.width/8 - ofRandom(100,0),
                               dimensions.height/8 + j*dimensions.height/8 - ofRandom(100,0));
                sp.topRight.set(dimensions.width/8 + i*dimensions.width/8 + ofRandom(100,0),
                                dimensions.height/8 + j*dimensions.height/8 - ofRandom(100,0));
                sp.bottomRight.set(dimensions.width/8 + i*dimensions.width/8 + ofRandom(100,0),
                                   dimensions.height/8 + j*dimensions.height/8 + ofRandom(100,0));
                sp.bottomLeft.set(dimensions.width/8 + i*dimensions.width/8 - ofRandom(100,0),
                                  dimensions.height/8 + j*dimensions.height/8 + ofRandom(100,0));
                col.push_back(sp);
            }
            row.push_back(col);
        }
        
        pos.push_back(row); // Add the row to the main vector

    }
    
    vols = {0.5,0.6,0.7,0.8,0.9};

    setAuthor("Sara Howorka");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/veraAnimatedScene/exampleCode.cpp");
}

void veraAnimatedScene::update(){
    if(ofGetElapsedTimeMillis() % 2 == 0) {
        vols.push_back(size);
        vols.erase(vols.begin());
    }
}

void veraAnimatedScene::draw(){
    ofNoFill();
    
    ofSetColor(255,255,255, opacity);
    ofSetLineWidth(1);
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int numShapes = 0;
            switch(j) {
                case 0:
                    numShapes = 5;
                    break;
                case 1:
                    numShapes = 25;
                    break;
                case 2:
                    numShapes = 10;
                    break;
                case 3:
                    numShapes = 6;
                    break;
                case 4:
                    numShapes = 3;
                    break;
                case 5:
                    numShapes = 2;
                    break;
            }
            
            for(int k = 0; k < numShapes; k++) {
                ofBeginShape();
                
                int centerX = (i+1.5)*dimensions.width/8;
                int centerY = (j+1.5)*dimensions.height/8;
                
                pos[i][j][k].topLeft.x = (pos[i][j][k].topLeft.x + ofRandom(-5,5));
                pos[i][j][k].topLeft.y = (pos[i][j][k].topLeft.y + ofRandom(-5,5));
                pos[i][j][k].topRight.x = (pos[i][j][k].topRight.x + ofRandom(-5,5));
                pos[i][j][k].topRight.y = (pos[i][j][k].topRight.y + ofRandom(-5,5));
                pos[i][j][k].bottomRight.x = (pos[i][j][k].bottomRight.x + ofRandom(-5,5));
                pos[i][j][k].bottomRight.y = (pos[i][j][k].bottomRight.y + ofRandom(-5,5));
                pos[i][j][k].bottomLeft.x = (pos[i][j][k].bottomLeft.x + ofRandom(-5,5));
                pos[i][j][k].bottomLeft.y = (pos[i][j][k].bottomLeft.y + ofRandom(-5,5));
                
                ofVertex( (centerX - 100 * vols[i] ) * smoothing +
                         (1-smoothing) * pos[i][j][k].topLeft.x,
                         (centerY - 100 * vols[i] ) * smoothing +
                         (1-smoothing) * pos[i][j][k].topLeft.y);
                ofVertex( (centerX + 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].topRight.x,
                       (centerY - 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].topRight.y);
                ofVertex( (centerX + 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].bottomRight.x,
                       (centerY + 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].bottomRight.y);
                ofVertex( (centerX - 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].bottomLeft.x,
                       (centerY + 100 * vols[i] ) * smoothing +
                       (1-smoothing) * pos[i][j][k].bottomLeft.y);
                
                
                ofEndShape(true);
            }
        }
    }
}