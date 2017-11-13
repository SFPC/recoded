#ifndef _PENNER_CIRC
#define _PENNER_CIRC

#include <math.h>
#include "ofxEasing.h"
class ofxEasingCirc: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
