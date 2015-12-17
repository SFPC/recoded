
#include "mwalczykVeraSquares.h"

void mwalczykVeraSquares::setup(){
  
    // We draw everything into an FBO that is twice the size of the current window
    int border = 80;
    int size = dimensions.width * 2 - border;
    int sizeStep = size / NUM_SQUARES;
    ofPoint windowCenter(dimensions.width, dimensions.height);
    
    for (int i = 0; i < NUM_SQUARES; ++i)
    {
        ofPolyline line;
        ofPoint upperLeft(windowCenter.x - size/2, windowCenter.y - size/2);
        ofPoint upperRight(windowCenter.x + size/2, windowCenter.y - size/2);
        ofPoint lowerRight(windowCenter.x + size/2, windowCenter.y + size/2);
        ofPoint lowerLeft(windowCenter.x - size/2, windowCenter.y + size/2);
        
        // This seqeunce of operations essentially builds a sub-divided square (polyline)
        line.addVertex(upperLeft);                                          // first, add the upper left point
        addPointBetween(upperLeft, upperRight, MAX_SUBDIVISIONS, line);
        line.addVertex(upperRight);                                         // then, add the upper right
        addPointBetween(upperRight, lowerRight, MAX_SUBDIVISIONS, line);
        line.addVertex(lowerRight);                                         // then, add the lower right
        addPointBetween(lowerRight, lowerLeft, MAX_SUBDIVISIONS, line);
        line.addVertex(lowerLeft);                                          // finally, add the lower left
        addPointBetween(lowerLeft, upperLeft, MAX_SUBDIVISIONS, line);
        line.close();
        
        mSquares.push_back(line);
        size -= sizeStep;
    }
    
    mSquareColor.set(65);
    ofSetLineWidth(3);
    
    // Allocate and clear our FBO
    mSquareFbo.allocate(dimensions.width * 2, dimensions.height * 2, GL_RGB, 8);
    mSquareFbo.begin();
    ofClear(ofColor::white);
    mSquareFbo.end();
    
    MAX_OFFSET.set("maxOffset", 0, 0, 10);
    MAX_TRANSLATION.set("maxTranslation", 0, 0, 15);
    PCT_JITTER.set("pctJitter", 0, 0, 1);
    parameters.add(MAX_OFFSET);
    parameters.add(MAX_TRANSLATION);
    parameters.add(PCT_JITTER);
    
    //parameters.add(translationNoiseZ.set("translationNoiseZ", 0, 0, 3));
    //parameters.add(jitterNoiseZ.set("jitterNoiseZ", 0, 0, 3));
    
    //mPaperTexture.load("paper.jpg");

    setAuthor("Michael Walczyk");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/mwalczykVeraSquares/exampleCode.cpp");
}

void mwalczykVeraSquares::addPointBetween(ofPoint &a, ofPoint &b, int numToAdd, ofPolyline &polyLine)
{
    // This function generates vertices between two points and adds them to the polyline
    float step = 1.0f / numToAdd;
    float pct = step;
    for (int i = 0; i < numToAdd; ++i)
    {
        polyLine.addVertex(a.getInterpolated(b, pct));
        pct += step;
    }
}

void mwalczykVeraSquares::update(){
    jitterNoiseZ.set(getElapsedTimef()/2.0);
    translationNoiseZ.set(getElapsedTimef()/2.0);
}

void mwalczykVeraSquares::draw(){
    
    //-------------------------------------------------------------- FBO begins
    mSquareFbo.begin();
    ofClear(ofColor::white);
    
    // Draw the background texture, if it's available
//    if (mPaperTexture.isAllocated())
//    {
//        ofSetColor(ofColor::white);
//        mPaperTexture.draw(0, 0, ofGetWidth() * 2, ofGetHeight() * 2);
//    }
    ofSetColor(mSquareColor);
    int i = 0;
    for (const auto &square: mSquares)
    {
        ofPolyline shiftedLine;
        for (auto &point: square.getVertices())
        {
            // Leave some of the points in their original positions
            if (ofNoise(point.x, point.y, jitterNoiseZ) > PCT_JITTER)
            {
                shiftedLine.addVertex(point);
            }
            else {
                shiftedLine.addVertex(point.x + ofMap(ofNoise(i * 17, jitterNoiseZ + 17), 0, 1, -MAX_OFFSET, MAX_OFFSET),
                                      point.y + ofMap(ofNoise(i * 17, jitterNoiseZ + 53), 0, 1, -MAX_OFFSET, MAX_OFFSET));
            }
        }
        shiftedLine.close();
        
        ofPushMatrix();
        ofTranslate(ofMap(ofNoise(i * 17, translationNoiseZ + 37), 0, 1, -MAX_TRANSLATION, MAX_TRANSLATION),
                    ofMap(ofNoise(i * 17, translationNoiseZ + 89), 0, 1, -MAX_TRANSLATION, MAX_TRANSLATION));
        shiftedLine.draw();
        ofPopMatrix();
        i++;
    }
    
    mSquareFbo.end();
    //-------------------------------------------------------------- FBO ends
    
    // Draw the FBO at 1/2 res, which equates to 504x504
    mSquareFbo.draw(0, 0, dimensions.width, dimensions.height);
}