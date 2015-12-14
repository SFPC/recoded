
#pragma once

#include "ofMain.h"
#include "baseScene.h"

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
} codeLetter;



class typographyManager {
    
    
public: 
    
    void setup ( baseScene * scene, float animateTime );
    void update( baseScene * scene );
    void draw();
    
    
    
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
    vector < float > paramChangedEnergy;
    
    
};