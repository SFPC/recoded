#pragma once

#include "ofMain.h"
#include "baseScene.h"

class memoAktenScene : public baseScene {
	
	struct Particle : public ofPoint {
		bool overground;
		float circle_max_radius;
		float circle_progress;
		float circle_alpha;
		
		Particle()
		: overground(false)
		{}
		
		void setupCircle() {
			circle_max_radius = 30.;
			circle_progress = 0.;
			circle_alpha = 0.;
		}
		
		void update(float new_x, float new_y, float baseline_y) {
			x = new_x;
			y = new_y;

			if (overground == true && y < baseline_y) {
				overground = false;
				setupCircle();
			}
			else if(overground == false && y > baseline_y) {
				overground = true;
				setupCircle();
			}
			else {
				circle_progress = ofClamp(circle_progress+0.025, 0., 1.);
				circle_alpha = 1. - circle_progress;
			}
		}
		
		float getRadius() const {
			return circle_max_radius * circle_progress;
		}
	};
	
public:
    
	void setup();
	void update();
	void draw();
    void reset();
	
	void refreshParticles();
    
    double progress;
    float lastTime;
	
	std::vector<Particle> particles;
	ofParameter<int> num_points;
	ofParameter<float> speed;
	ofParameter<float> animation_height;
	ofParameter<float> line_max_length;
	ofParameter<float> line_alpha;
};
