#include "interactionManager.h"



void interactionManager::setup(){

    lastInteractionTime = 0;
    interactionTimeout = 10;
    bInteracting = false;
    

    
}

void interactionManager::update(){
    
    float timeNow = ofGetElapsedTimef() - lastInteractionTime;
    if (timeNow > interactionTimeout){
        bInteracting = false;
    }
    
    
    
    //------------------------------------------------ parse incoming packet
    arduinoPacket currPacket;
    
    // do some magic to get a packet in
    
    float valueChangeThreshold = 3; // some higher treshold since eletrical values might shift...
    
    bool bChange = false;
    for (int i = 0; i < 4; i++){
        if (fabs(currPacket.knobValues[i] - prevPacket.knobValues[i]) > valueChangeThreshold){
            bChange = true;
        }
    }
    
    
    if (bChange == true){
        bInteracting = true;
        lastInteractionTime = ofGetElapsedTimef();
    }
    
     prevPacket = currPacket;
    
    //--------------------------------------------- send outgoing packet
    
    
   
    
}
