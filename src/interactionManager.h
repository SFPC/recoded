


#pragma once

#include "ofMain.h"


// we want to send this to the arduino
//---------------------------------------------------------------------
enum status {
    TYPING,
    SCENE_ANIMATING,
    SCENE_INTERACTING
};

typedef struct {
    status currentStatus;
    int numParamsForThisScene;
} statusPacket;
//---------------------------------------------------------------------


//---------------------------------------------------------------------
typedef struct {
    float knobValues[4];
} arduinoPacket;


class interactionManager {
    
    
    public:
    
    
        void setup();
    
        void update();
    
        float lastInteractionTime;
        float interactionTimeout;
    
        bool bInteracting;
    
    
        arduinoPacket prevPacket;
};