#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "gif_lib.h"

// Hacked gif interleave decoding function based off gif_libs DGifSlurp
int DGifGlitchSlurp(GifFileType * GifFile, bool pInterleave, int InterlacedOffsets[], int InterlacedJumps[]);

class alexGifPaletteDitherMenkman : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofPoint center;
    
    ofDirectory dir;
    
    GifFileType gif;
    string gifSlurpStatus;
    int gifOpenError;
    ColorMapObject colorMap;
    
    ofParameterGroup paramsGroup;
    ofParameter<int> pPaletteShift;
    
    ofParameter<int> pImageIndex;
    int ImageIndexLast;
    void GGReloadImage();

    
    ofParameter<bool> pInterleave;
    // eventlistener  not working, using flag as workround
    void pInterleaveChanged(int &pInterleave);
    bool pInterleaveLast;
    
    ofParameter<int> pInterlacedOffset[4];
    ofParameter<int> pInterlacedJumps[4];
    
    ofPixels framePixels;
    ofImage frame;
    int frameIndex;
    
    unsigned long int lastTime;
    bool ImageReload;

};
