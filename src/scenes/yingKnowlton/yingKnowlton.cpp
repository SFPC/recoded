
#include "yingKnowlton.h"

void yingKnowlton::setup(){

    originalImage.load("scenes/yingKnowlton/sfpc-final_640.png");
    originalImage.setImageType(OF_IMAGE_COLOR);
    sourceImage.load("scenes/yingKnowlton/sfpc-final_640.png");
    sourceImage.setImageType(OF_IMAGE_COLOR);
    targetScores = NULL;

    ofBackground(0);

    res = 4;

    // note: pulled from @sfpc_nyc instagram feed
    directory = ofDirectory("scenes/yingKnowlton/videos/");
    directory.listDir();

    playVideo(0);
    center.set(dimensions.width/2, dimensions.height/2);
    screenScale = dimensions.width/vidPlayer.getWidth();
    screenScale *= 1.01; // MULTIPLY HERE TO MAKE EDGES BLEED PAST THE SCREEN

    parameters.add(videoNum.set("videoNum", 0, 0, directory.size()));
    parameters.add(iterations.set("iterations", 5000, 10, 10000));
    parameters.add(mixRatio.set("mixRatio", 1, 0, 1));

    setAuthor("Ying Quan Tan");
    setOriginalArtist("Ken Knowlton");
    loadCode("scenes/yingKnowlton/exampleCode.cpp");
}

void yingKnowlton::update(){
    vidPlayer.update();
    if (vidPlayer.isPlaying() && vidPlayer.getTotalNumFrames() - vidPlayer.getCurrentFrame() < 30) {
        videoNum = ++videoNum % directory.size();
        playVideo(videoNum);
    }
    if (current != videoNum) {
        current = videoNum;
        playVideo(videoNum);
    }
}

void yingKnowlton::draw(){
    ofPushMatrix();

    int vidWidth = vidPlayer.getWidth() * screenScale;
    int vidHeight = vidPlayer.getHeight() * screenScale;
    // center the video
    ofTranslate(center - ofPoint(vidWidth, vidHeight)/2);

    // make sure video scales to screen.
    ofScale(screenScale, screenScale);


    if ((vidPlayer.isPlaying() && sourceImage.isAllocated())) {
        unsigned char * vidPixels = vidPlayer.getPixels().getData();
        unsigned char * originalPixels = originalImage.getPixels().getData();

        ofImage &image = sourceImage;
        int cols = image.getWidth() / res;
        int rows = image.getHeight() / res;
        int positions = cols * rows;
        int bytesPerPixel = 3;

        for (int it = 0; it < iterations; it++) {
            unsigned char * targetPointer;
            if (ofRandom(1.0) < mixRatio) {
                targetPointer = vidPixels;
            } else {
                targetPointer = originalPixels;
            }

            int i = floor(ofRandom(cols)) * res;
            int j = floor(ofRandom(rows)) * res;
            float previousTargetScore = targetScore;
            int index = (j * image.getWidth() + i) * bytesPerPixel;
            int x = i / res;
            int y = j / res;

            int randX = floor(ofRandom(cols)) * res;
            int randY = floor(ofRandom(rows)) * res;
            int randIndex = (randY * image.getWidth() + randX) * bytesPerPixel;

            unsigned char * from = getSubImage(image, i, j, res);
            unsigned char * to = getSubImage(image, randX, randY, res);

            // calculate costs
            float fromScore = distance(from, targetPointer + index);
            float toScore = distance(to, targetPointer + randIndex);

            float afterSwapFromScore = distance(to, targetPointer + index);
            float afterSwapToScore = distance(from, targetPointer + randIndex);

            if (afterSwapFromScore + afterSwapToScore < fromScore + toScore) {
                // perform swap
                setSubImage(image, i, j, res, to);
                setSubImage(image, randX, randY, res, from);
            }
            delete[] from;
            delete[] to;
        }

        image.update();
        image.draw(0, 0);
    }
    ofPopMatrix();
}

void yingKnowlton::playVideo(int index) {
    vidPlayer.load(directory.getPath(index));
    int cols = vidPlayer.getWidth() / res;
    int rows = vidPlayer.getHeight() / res;
    if (targetScores == NULL) {
        targetScores = new unsigned char[cols * rows];
    }
    memset(targetScores,0,cols * rows);

    vidPlayer.setVolume(0);
    vidPlayer.play();

}

unsigned char * yingKnowlton::getSubImage(ofImage &image,
                                   int _x,
                                   int _y,
                                   int maskSize) {
    int bytesPerPixel = 3;
    unsigned char * subImage = new unsigned char[maskSize * maskSize * bytesPerPixel];
    unsigned char * data = image.getPixels().getData();

    int c = 0;
    for (int y = _y; y < _y + maskSize; y++) {
        for (int x = _x; x < _x + maskSize; x++) {
            int idx = y * image.getWidth()*bytesPerPixel + x*bytesPerPixel;
            for (int i = 0; i < bytesPerPixel; i++) {
                subImage[c + i] = data[idx + i];
            }
            c += bytesPerPixel;
        }
    }
    return subImage;
}


void yingKnowlton::setSubImage(ofImage &image,
                        int _x,
                        int _y,
                        int maskSize,
                        unsigned char * subImage) {
    int bytesPerPixel = 3;
    unsigned char * data = image.getPixels().getData();
    int c = 0;
    for (int y = _y; y < _y + maskSize; y++) {
        for (int x = _x; x < _x + maskSize; x++) {
            int idx = (y * image.getWidth() + x) * bytesPerPixel;
            for (int i = 0; i < bytesPerPixel; i++) {
                data[idx + i] = subImage[c + i];
            }
            c += bytesPerPixel;
        }
    }
}

float yingKnowlton::distance(unsigned char * pixel1,
                      unsigned char * pixel2) {

    float r1 = pixel1[0];
    float g1 = pixel1[1];
    float b1 = pixel1[2];

    float r2 = pixel2[0];
    float g2 = pixel2[1];
    float b2 = pixel2[2];

    float dist = abs(r1 - r2) + abs(g1 - g2) + abs(b1 - b2);
    dist /= (255*3);
    return dist;
}

float yingKnowlton::getTargetScore() {

    float total = 0;
    int cols = sourceImage.getWidth() / res;
    int rows = sourceImage.getHeight() / res;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            int score = targetScores[j * cols + i];
            total += score;
        }
    }
    return total;
}
