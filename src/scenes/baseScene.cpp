//
//  baseScene.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "baseScene.h"


void baseScene::loadCode( string fileName ){
    
    ofBuffer buffer = ofBufferFromFile(fileName);
    code = "";
    
    for (auto line : buffer.getLines()){
        code += line;
        code += "\n";
    }

}


