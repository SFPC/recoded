#ofxParameterMidiSync

This is an addon for openFrameworks.
It allows to easily sync ofParameters (the ones used with OF's default GUI) with MIDI messages, like the ones coming from a MIDI controller.

##Implementation
In your ofApp.h file include the addon.

After the following line:

`#include "ofMain.h"`

Add these lines:
`#include "ofxGui.h"`
`#include "ofxParameterMidiSync.h"`

Create an instance inside your ofApp class

`ofxParameterMidiSync sync;`


Now in your ofApp.cpp file put the following inside the `setup()` method:
 
`sync.setup(0, gui.getParameter());`

Here, the first argument is the midi device number. you can find out the number of your device by calling `ofxMidiIn::listPorts();` which will print to the console the available midi ports.

The second argument is the ofParameterGroup that you want to sync to.
Here we consider the gui object to be an instance of ofxPanel (the default gui for OF).

You can also sync individual ofParameters without syncing a whole group using:
`linkMidiToOfParameter(int controlNum, ofAbstractParameter& param);`
`linkMidiToOfParameter(ofxMidiMessage& msg, ofAbstractParameter& param);`

The `ofAbstractParameter` is the base class for all ofParameters, so it doesn't matter wich kind of parameter is, the addon will figure it out.

Then just call any of the following when needed.

`learn()`

`unlearn()`

`load(string path)`

`save(string path)`

##Usage

Follow the example to see how to implement. Once implemented syncing parameters is really easy, you just call the `learn()` method and move a parameter in the gui and a slider or knob in your controller and syncing is ready. This settings can be saved and loaded.
If you want to change a ofParameter/MIDIMessage pair just call the `unlearn()` method and move either the MIDI controller or the gui param and this will get unsynced.

When syncing with ofVec2f, ofVec3f, ofVec4f or any ofColor you just need to sync the first parameters of it, the following ones will be automatically assigned to the following MIDI ContinousControl numbers.

##Requirements
[ofxMidi](https://github.com/danomatika/ofxMidi)
ofxGui (included in OF)

##Compatibility
Made to work with OF 0.9
