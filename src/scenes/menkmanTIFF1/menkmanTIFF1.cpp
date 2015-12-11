
#include "menkmanTIFF1.h"

void menkmanTIFF1::setup(){

    srcPath = "menkmanTIFF1/images/menkman.tif";
    dstPath = "menkmanTIFF1/images/menkmanGlitch.tif";
    
    lineCount = getLineCount(srcPath);
    
    src.load(srcPath);
    dst.load(dstPath);
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, lineCount);
    startLine.set("startLine", 50, 0, lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
    
    loadCode("menkmanTIFF1/exampleCode.cpp");
}

void menkmanTIFF1::update(){
    glitchImage(startLine, numberOfLines);    
}

void menkmanTIFF1::draw(){
    ofBackground(0);
    ofSetColor(255);
    dst.draw(0,0,dimensions.getWidth(),dimensions.getHeight());
}


int menkmanTIFF1::getLineCount(string path) {
    int count = 0;
    string line;
    std::ifstream file;
    
    // open file
    file.open(ofToDataPath(path).c_str());
    
    // count lines one by one
    while(std::getline(file, line)) {
        ++count;
    }
    
    file.close();
    
    return count;
};


void menkmanTIFF1::glitchImage(int start, int max) {
//    ofLogVerbose("glitch image: "+ofToString(start)+", "+ofToString(max));
    
    ifstream fin;
    fin.open(ofToDataPath(srcPath).c_str());
    
    ofstream fout;
    fout.open(ofToDataPath(dstPath).c_str() );
    
    int i = 0;
    
    while(fin) {
        string str;
        std::getline(fin, str);
        
        if(i >= start && i < start + max) {
            // leave this line out
//            ofLogVerbose("leave out line "+ofToString(i));
        } else {
            fout << str << "\n";
        }
        
        i++;
    }
    
    fout.close();
    fin.close();
    
    dst.load(dstPath);
}