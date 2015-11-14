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
#include "robbyMolnarScene.h"
#include "robbyRileyScene.h"

    
void sceneManager::setup(){
    
    
    scenes.push_back(new exampleScene() );
    scenes.push_back(new triangleScene() );
    scenes.push_back(new robbyMolnarScene() );
    scenes.push_back(new robbyRileyScene() );
    
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT);
    codeFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT);
    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
    }
    
    
    
//    for (int i = 0; i< scenes.size(); i++){
//        scenes[i]->setup();
//    }
    
    currentScene = 0;
    
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    panel->setPosition(ofGetWidth()-300, 20);

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
    
    ofSetColor(255,255,255);
    sceneFbo.draw(0,0,ofGetHeight(), ofGetHeight());
    
    codeFbo.begin();
    ofClear(50,50,50, 255);
    string codeReplaced = scenes[currentScene]->getCodeWithParamsReplaced();
    ofDrawBitmapString(codeReplaced, 40,40);
    codeFbo.end();
    
    codeFbo.draw(ofGetHeight(), 0,ofGetHeight(), ofGetHeight());
    
    panel->draw();
    
}

void sceneManager::advanceScene(){
    currentScene ++;
    currentScene %= scenes.size();
    
    delete panel;
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    
    panel->setPosition(ofGetWidth()-300, 20);
    
};