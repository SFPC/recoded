
#include "ofxDataBender.h"

void ofxDataBender::setup(string imagesPath, string ext){
    
    fileExt = ext;
    srcPath = imagesPath+fileExt+"/menkman."+fileExt;
    dstPath = imagesPath+"tmp/menkman."+fileExt;
    
    lineCount = getLineCount(srcPath);
    
    src.load(srcPath);
    dst.load(dstPath);
    
}

void ofxDataBender::update(int startLine, int numberOfLines, bool sips){
    glitchImage(startLine, numberOfLines);
    
    // for formats that require a sips conversion
    if (sips) sipsConvert();
    
    dst.load(dstPath);
}

void ofxDataBender::draw(int x, int y,int w, int h){
    dst.draw(x, y, w, h);
}

int ofxDataBender::getLineCount(string path) {
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


void ofxDataBender::sipsConvert() {
    std::string cmd = "sips -s format "+fileExt+" " +ofToDataPath(dstPath)+" --out "+ofToDataPath(dstPath);
    system(cmd.c_str());
}


void ofxDataBender::glitchImage(int start, int max) {

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
        } else {
            fout << str << "\n";
        }
        
        i++;
    }
    
    fout.close();
    fin.close();
}