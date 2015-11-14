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

    
void sceneManager::setup(){
    
    
    scenes.push_back(new veraAnimatedScene() );
    scenes.push_back(new exampleScene() );
    scenes.push_back(new triangleScene() );
    
    // disney
    for (auto scene : scenes){
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
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
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