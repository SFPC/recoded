
#pragma once

#include "ofMain.h"
#include "baseScene.h"

#define CHARACTER_CODE      -1
#define CHARACTER_PARAM     0
#define CHARACTER_COMMENT   1

//----------------------------------------
// typography things:
vector < int > positionsOfSubstring(string str, string sub);
typedef struct {
    int paramID;
    string paramName;
    int position;
    int length;
} templatePos;

typedef struct {
    char    character;
    int     idOfChar;       // -1 = regular code, 0 = param 0, etc....
    int     type;
} codeLetter;

class typographyManager {
    
    
public: 
    
    void setup ( baseScene * scene, float animateTime );
    void update( baseScene * scene );
    void draw();

    //----------------------------------------
    // sound
    
    ofSoundPlayer keystroke1Sound;
    ofSoundPlayer keystroke2Sound;
    
    void loadSounds();
    
    //----------------------------------------
    // timing
    
    float setupTime;
    float animTime;
    
    

    //----------------------------------------
    // typography
    
    vector < codeLetter > getCodeWithParamsReplaced( baseScene * bs);          // more info for coloring
    
    int nParams;
    vector < vector < int > > paramPositions;
    vector < int > paramLengths;
    vector < templatePos > paramsInOrder;
    void calcPositionsOfParams();
    vector < string > paramsToReplace;
    
    // For MIDI
    vector < float > paramChangedEnergy;
    
    // For animation
    vector < float > paramEnergyTarget;
    vector < float > paramEnergy;
    
    float energyDecayRate, energyChangePerFrame;
    
    
};
