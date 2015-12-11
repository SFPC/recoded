#pragma once

#include "ofMain.h"
#include "baseScene.h"

class menkmanTIFF1 : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    int getLineCount(string path);
    void glitchImage(int start, int max);

    int lineCount;

    std::string srcPath;
    std::string dstPath;
    
    ofImage src;
    ofImage dst;

    ofParameter<int> numberOfLines;
    ofParameter<int> startLine;
};
