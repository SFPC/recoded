//
//  sceneManager.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "sceneManager.h"
#include "exampleScene.h"
#include "triangleScene.h"
#include "veraAnimatedScene.h"
#include "robbyMolnarScene.h"
#include "robbyRileyScene.h"
#include "yeseulScene.h"
#include "johnWhitneyShader01.h"
#include "RoyWhitney1.h"
#include "veraFscene.h"
#include "anastasisRileyScene.h"
#include "menkmanJPG1.h"


void sceneManager::setup(){

    scenes.push_back(new RoyWhitney1());
    scenes.push_back(new veraFscene());
    scenes.push_back(new robbyMolnarScene() );
    scenes.push_back(new veraAnimatedScene() );
    scenes.push_back(new exampleScene() );
    scenes.push_back(new triangleScene() );
    scenes.push_back(new robbyRileyScene() );
    scenes.push_back(new yeseulScene() );
    scenes.push_back(new johnWhitneyShader01());
    scenes.push_back(new anastasisRileyScene());
    scenes.push_back(new menkmanJPG1());
    
    
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);
    codeFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);


    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
    }
    
    
//    for (int i = 0; i< scenes.size(); i++){
//        scenes[i]->setup();
//    }
    
    currentScene = 0;
    scenes[currentScene]->reset();
    
    
    
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    panel->setPosition(ofGetWidth()-300, 20);

    
    mode = DRAW_SIDE_BY_SIDE;
    
}

void sceneManager::update(){
    scenes[currentScene]->update();
}

void sceneManager::draw(){
    
    
    
    sceneFbo.begin();
    ofClear(0,0,0,255);
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
    ofClearAlpha();
    sceneFbo.end();
    
    
    if (mode == DRAW_SIDE_BY_SIDE){
        ofSetColor(255,255,255);
        sceneFbo.draw(0,0,ofGetHeight(), ofGetHeight());
        
        codeFbo.begin();
        ofClear(50,50,50, 255);
        string codeReplaced = scenes[currentScene]->getCodeWithParamsReplaced();
        ofDrawBitmapString(codeReplaced, 40,40);
        codeFbo.end();
        
        codeFbo.draw(ofGetHeight(), 0,ofGetHeight(), ofGetHeight());
    } else if (mode == DRAW_SINGLE){
        sceneFbo.draw(0,0);
    }
    
    panel->draw();
    
}

void sceneManager::advanceScene(){
    currentScene ++;
    currentScene %= scenes.size();
    scenes[currentScene]->reset();
    
    
    
    delete panel;
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    
    panel->setPosition(ofGetWidth()-300, 20);
    
};
