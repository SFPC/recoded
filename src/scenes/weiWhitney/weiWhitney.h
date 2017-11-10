#pragma once

#include "ofMain.h"
#include "baseScene.h"

class weiWhitney : public baseScene{

	public:
		void setup();
		void update();
		void draw();

		ofParameter<float> speed, scale, radiusAdder ;
		ofParameter<int> nTips;
};
