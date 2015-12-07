ofBackground(251, 241, 229);

ofColor cyan(167, 200, 250);
ofColor magenta(235, 173, 137);
ofColor yellow(249, 235, 106);

ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
ofSetColor(cyan);
font.drawString(text, 100, 100 + [[currentDisplacement0]]);
font.drawString(text, 100, 100 + [[currentDisplacement1]]);

ofSetColor(magenta);
font.drawString(text, 100, 100 + [[currentDisplacement2]]);
font.drawString(text, 100, 100 + [[currentDisplacement3]]);

ofSetColor(yellow);
font.drawString(text, 100, 100 + [[currentDisplacement4]]);
font.drawString(text, 100, 100 + [[currentDisplacement5]]);

ofDisableBlendMode();