#include "interactionManager.h"
#include "ofApp.h"

void interactionManager::setup()
{
    lastInteractionTime = 0;
    interactionTimeout = 10;
    bInteracting = false;
#ifdef USE_SERIAL
    serial.listDevices();
    serial.setup(0, 57600);
#endif
}

void interactionManager::update()
{
    float timeNow = ofGetElapsedTimef() - lastInteractionTime;
    if (timeNow > interactionTimeout){
        bInteracting = false;
    }
    
    if (bInteracting == true){
		for (int i = 0; i < ((ofApp*)ofGetAppPtr())->SM.scenes.size(); i++) {
            ((ofApp*)ofGetAppPtr())->SM.scenes[i]->bUpdateParamFromRecording = false;
		}
    } else {
        for (int i = 0; i < ((ofApp*)ofGetAppPtr())->SM.scenes.size(); i++) {
            ((ofApp*)ofGetAppPtr())->SM.scenes[i]->bUpdateParamFromRecording = true;
        }
    }
    

    //------------------------------------------------ parse incoming packet
    arduinoPacket currPacket;

    bool bGotPacket = false;
#ifdef USE_SERIAL
    while (serial.available())
    {
        char byte = serial.readByte();
        s += byte;

        if (byte == 'z')
        {
            bool bFoundA = false;
            int position = 0;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == 'a')
                {
                    bFoundA = true;
                    position = i;
                }
            }
            string subString = s.substr(position);
            //cout << subString << endl;
            s = "";
            vector<string> strings = ofSplitString(subString, " ");
            if (strings.size() == 6)
            {
                if (strings[0] == "a" && strings[5] == "z")
                {
                    bGotPacket = true;
                    for (int i = 0; i < 4; i++)
                    {
                        currPacket.knobValues[i] = ofToFloat(strings[i + 1])/4096.0;
                        ///cout << "i " << i << " " << currPacket.knobValues[i]  << endl;
                    }
                }
            }
        }
    }
#endif
    //cout << byte;

    bool bChange = false;
    
    if (bGotPacket == true){
    float valueChangeThreshold = 0.01; // some higher threshold since eletrical values might shift...
    
    
    
    for (int i = 0; i < 4; i++)
    {
        vector < int > knobMappings = ((ofApp*)ofGetAppPtr())->SM.scenes[ ((ofApp*)ofGetAppPtr())->SM.currentScene ]->midiKnobs;
        
        if (i < knobMappings.size()){
            
            cout << "size " << knobMappings.size() << endl;
            cout << i << " " << fabs(currPacket.knobValues[i] - prevPacket.knobValues[i]) << endl;
            
            if (fabs(currPacket.knobValues[i] - prevPacket.knobValues[i]) > valueChangeThreshold)
            {
                
                float change = (currPacket.knobValues[i] - prevPacket.knobValues[i]);
                if (change < -.5) change += 1;
                if (change > .5) change -=1;
//                cout << currPacket.knobValues[i] << endl;
//                cout << prevPacket.knobValues[i] << endl;
//                
                
                int which = knobMappings[i];
                float pctDiff = currPacket.knobValues[i]-prevPacket.knobValues[i];
                
                ((ofApp*)ofGetAppPtr())->SM.scenes[ ((ofApp*)ofGetAppPtr())->SM.currentScene ]->updateInteractiveParams(change, which, currPacket.knobValues[i]);
                // todo :
    //            if (IM.bInteracting) {
    //                int numParams = MIN(SM.scenes[SM.currentScene]->midiKnobs.size(),4);
    //                
    //                for (int i=0; i<numParams; i++) {
    //                    float val = IM.prevPacket.knobValues[i];
    //                    cout << "setting param " << i << " to " << val << endl;
    //                    SM.scenes[SM.currentScene]->updateInteractiveParams(val, i);
    //                }
    //            }
                
                //cout << "knob" << i << " " << currPacket.knobValues[i] << " | ";
                bChange = true;
            }
        }
    }
    //cout << endl;
    }

    if (bChange == true)
    {
        bInteracting = true;
        lastInteractionTime = ofGetElapsedTimef();
        
    }

    if (bGotPacket){
        for (int i = 0; i < 4; i++){
            prevPacket.knobValues[i] = currPacket.knobValues[i];
        }
    }
    //--------------------------------------------- send outgoing packet
}
    
void interactionManager::turnOffLEDs() {
    this->setLEDs(0,0,0,0);
}

void interactionManager::setLEDs(int led1, int led2, int led3, int led4) {
#ifdef USE_SERIAL
    int ledValuesByte = (led1 & 0x1) + ((led2 & 0x1) << 1) + ((led3 & 0x1) << 2) + ((led4 & 0x1) << 3); 
    serial.writeByte(ledValuesByte);
#endif
}

void interactionManager::setCurrentSceneParameterCount(int numParams) {
#ifdef USE_SERIAL
    int ledValuesByte = 0x0;
    for (int i=0; i<numParams; i++) {
        ledValuesByte += (0x1 << i);
    }
    serial.writeByte(ledValuesByte);
#endif
}

