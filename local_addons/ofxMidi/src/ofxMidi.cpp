/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#include "ofxMidi.h"

// choose the midi backend
#ifdef TARGET_OF_IPHONE
	#include "ios/ofxPGMidiIn.h"
#endif

// -----------------------------------------------------------------------------
void ofxMidiConnectionListener::midiInputAdded(string name, bool isNetwork) {
	ofLogNotice("ofxMidi") << "input added: " << name << " network: " << isNetwork;
}

void ofxMidiConnectionListener::midiInputRemoved(string name, bool isNetwork) {
	ofLogNotice("ofxMidi") << "input removed: " << name << " network: " << isNetwork;
}

void ofxMidiConnectionListener::midiOutputAdded(string name, bool isNetwork) {
	ofLogNotice("ofxMidi") << "output added: " << name << " network: " << isNetwork;
}

void ofxMidiConnectionListener::midiOutputRemoved(string name, bool isNetwork) {
	ofLogNotice("ofxMidi") << "output removed: " << name << " network: " << isNetwork;
}

// -----------------------------------------------------------------------------
void ofxMidi::setConnectionListener(ofxMidiConnectionListener * listener) {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::setConnectionListener(listener);
	#endif
}

// -----------------------------------------------------------------------------
void ofxMidi::clearConnectionListener() {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::clearConnectionListener();
	#endif
}

// -----------------------------------------------------------------------------
void ofxMidi::enableNetworking() {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::enableNetworking();
	#endif
}
