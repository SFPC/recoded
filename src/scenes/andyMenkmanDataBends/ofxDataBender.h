#pragma once

#include "ofMain.h"

class ofxDataBender {
    
public:
    
    void setup(string imagesPath, string ext, int debounce=0);
    void update(int startLine, int numberOfLines, bool sips=false);
    void draw(int x, int y, int w, int h);
    
    void setDebounce(int debounce);
    int getLineCount(string path);
    void sipsConvert();
    void glitchImage(int start, int max);

    int lineCount;

    std::string fileExt;
    std::string srcPath;
    std::string dstPath;

    ofParameter<int> numberOfLines;
    ofParameter<int> startLine;
    
private:

    ofImage src;
    ofImage dst;
    int debounceTime;
    int debounceValue;

};
