#pragma once

#include "ofMain.h"

class ofxDataBender {
    
public:
    
    void setup(string imagesPath, string ext);
    void update(int startLine, int numberOfLines, bool sips=false);
    void draw(int x, int y, int w, int h);
    
    int getLineCount(string path);
    void sipsConvert();
    void glitchImage(int start, int max);

    int lineCount;

    std::string fileExt;
    std::string srcPath;
    std::string dstPath;
    
    ofImage src;
    ofImage dst;

    ofParameter<int> numberOfLines;
    ofParameter<int> startLine;
};
