
#include "menkmanJPG1.h"

void menkmanJPG1::setup(){

//    ofSetLogLevel(OF_LOG_VERBOSE);

    srcPath = "menkmanJPG1/images/menkman.jpg";
    dstPath = "menkmanJPG1/images/menkmanGlitch.jpg";
    
    lineCount = getLineCount(srcPath);
    
    src.load(srcPath);
    dst.load(dstPath);
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, lineCount);
    startLine.set("startLine", 50, 0, lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
    
    loadCode("menkmanJPG1/exampleCode.cpp");
    
}

void menkmanJPG1::update(){
    glitchImage(startLine, numberOfLines);
}

void menkmanJPG1::draw(){
    ofBackground(0);
    ofSetColor(255);
    dst.draw(0,0,dimensions.getWidth(),dimensions.getHeight());
}

int menkmanJPG1::getLineCount(string path) {
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


void menkmanJPG1::glitchImage(int start, int max) {
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
    
//    ofLogVerbose("open in glitch");
    dst.load(dstPath);
}

