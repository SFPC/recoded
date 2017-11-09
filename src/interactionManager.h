#pragma once
#include "ofMain.h"
#include "appConstants.h"
// we want to send this to the arduino
//---------------------------------------------------------------------
enum status
{
    TYPING,
    SCENE_ANIMATING,
    SCENE_INTERACTING
};

typedef struct
{
    status currentStatus;
    int numParamsForThisScene;
} statusPacket;
//---------------------------------------------------------------------

//---------------------------------------------------------------------
typedef struct
{
    float knobValues[4];
} arduinoPacket;

class interactionManager
{

  public:
    void setup();

    void update();
    void gotMessage(ofMessage msg);
    void keyPressed(int key);
    void turnOffLEDs();
    void setLEDs(int led1, int led2, int led3, int led4);
    void setCurrentSceneParameterCount(int numParams);

    float lastInteractionTime;
    float interactionTimeout;

    bool bInteracting;

    arduinoPacket prevPacket;
#ifdef USE_SERIAL
    ofSerial serial;
#endif
    string s;
};
