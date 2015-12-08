#include "menkmanPNG1.h"

void menkmanPNG1::setup(){
  
//    ofSetLogLevel(OF_LOG_VERBOSE);

    srcPath = "menkmanPNG1/images/menkman.png";
    dstPath = "menkmanPNG1/images/menkmanGlitch.png";
    
    lineCount = getLineCount(srcPath);
    
    src.load(srcPath);
    dst.load(dstPath);
    
    // setup pramaters
    numberOfLines.set("numberOfLines", 1, 0, 50);
    startLine.set("startLine", lineCount-50, 0, lineCount);
    parameters.add(numberOfLines);
    parameters.add(startLine);
    
    loadCode("menkmanJPG1/exampleCode.cpp");
}

void menkmanPNG1::update(){
    glitchImage(startLine, numberOfLines);    
}

void menkmanPNG1::draw(){
    ofBackground(0);
    ofSetColor(255);
    dst.draw(0,0,dimensions.getWidth(),dimensions.getHeight());
}


int menkmanPNG1::getLineCount(string path) {
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


void menkmanPNG1::glitchImage(int start, int max) {
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
    
    std::string cmd = "sips -s format png "+ofToDataPath(dstPath)+" --out "+ofToDataPath(dstPath);
    system(cmd.c_str());
    
//    ofLogVerbose("open in glitch");
    dst.load(dstPath);
    
}

