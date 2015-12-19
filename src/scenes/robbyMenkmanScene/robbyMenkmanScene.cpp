//
//  triangleScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "robbyMenkmanScene.h"
#include "appConstants.h"

#define RK_MNK_DEL_REFRESH 7000

void robbyMenkmanScene::setup(){
    speedParameter.set("delay", 1000, 100, 10000);
    chunkParameter.set("chunk size", 9000, 1000, 20000);
    parameters.add(speedParameter);
    parameters.add(chunkParameter);

      // MUST BE A JPEG!  no PNG
    // from Rosa Menkman's flickr https://www.flickr.com/photos/r00s/14470920443/
    originalBuffer = ofBufferFromFile("scenes/robbyMenkmanScene/100.jpg");
    nextGlitchMoment = 0;
    loadImageBuffer();

    setAuthor("Robby Kraft");
    setOriginalArtist("Rosa Menkman");
    loadCode("scenes/robbyMenkmanScene/code.txt");
}
void robbyMenkmanScene::loadImageBuffer(){
    buffer = originalBuffer;
    image.load(buffer);
    lastBufferLoad = ofGetElapsedTimeMillis();
}
void robbyMenkmanScene::glitchImage(){
    char *data = buffer.getData();
    int size = buffer.size();
    int chunkSize = ofRandom(10,chunkParameter);
    int index = ofRandom(size - chunkSize);
    for(int i = index; i < size - chunkSize; i++){
        data[i] = data[i+chunkSize];
    }
    buffer = ofBuffer(data, size);// - chunkSize);
    image.load(buffer);
    nextGlitchMoment = ofGetElapsedTimeMillis() + ofRandom(5, speedParameter);
}
void robbyMenkmanScene::update(){
    if(ofGetElapsedTimeMillis() > nextGlitchMoment){
        glitchImage();
    }
    // reload the image from buffer
    // if the image is broken
    // or if the time > 4 seconds
    if(!image.isAllocated() || lastBufferLoad + RK_MNK_DEL_REFRESH < ofGetElapsedTimeMillis()){
        loadImageBuffer();
        glitchImage();
    }
}
void robbyMenkmanScene::draw(){
    ofClear(0, 0, 0);
    if(image.isAllocated())
        image.draw(0, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
}