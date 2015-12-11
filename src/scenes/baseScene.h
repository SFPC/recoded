
#pragma once

#include "ofMain.h"


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


class baseScene {
    
public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual void reset(){}          // this is for scenes that change over time....
    
    baseScene(){};
    ~baseScene(){}
    
    void loadCode( string fileName );
    string getCodeWithParamsReplaced();
    vector < codeLetter > getCodeWithParamsReplaced2();          // more info for coloring
    
    
    ofParameterGroup parameters;    // this is the parameters of your sketch...

    string code;                // this is the code we show
    
    ofRectangle dimensions;     // this is the dimensions of
                                // the surface you are drawing into.
    
    
    //----------------------------------------
    // typography
    int nParams;
    vector < vector < int > > paramPositions;
    vector < int > paramLengths;
    vector < templatePos > paramsInOrder;
    void calcPositionsOfParams();
    vector < string > paramsToReplace;
    vector < float > paramChangedEnergy;
    
};