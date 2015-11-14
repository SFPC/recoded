
#pragma once



#include "ofMain.h"



class baseScene {
    
public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    baseScene(){};
    ~baseScene(){}
    
    void loadCode( string fileName );
    string getCodeWithParamsReplaced();
    
    ofParameterGroup parameters;
    string code;
    
    
};