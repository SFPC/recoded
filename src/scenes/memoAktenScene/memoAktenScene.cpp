
#include "memoAktenScene.h"


void memoAktenScene::refreshParticles() {
	particles.clear();
	for (int i=0; i<num_points; i++) {
		Particle p;
		particles.push_back(p);
	}
}

void memoAktenScene::setup(){
  
	// setup pramaters
	num_points.set("num_points", 35, 5, 50);
	//parameters.add(num_points);
	
	speed.set("speed", 4.5, 0.1, 10.0);
	parameters.add(speed);
	
	animation_height.set("animation_height", 80, 50, dimensions.height * 0.5);
	parameters.add(animation_height);
	
	line_max_length.set("line_max_length", 50., 0., 200.);
	parameters.add(line_max_length);
	
	line_alpha.set("line_alpha", 0.1, 0., .75);
	parameters.add(line_alpha);
	
	refreshParticles();
    progress = 0;
    lastTime = 0;

    setAuthor("Motoi Shimizu");
    setOriginalArtist("Memo Akten");
	loadCode("scenes/memoAktenScene/exampleCode.cpp");
}

void memoAktenScene::reset() {
    lastTime = 0;
    progress = 0;
}

void memoAktenScene::update(){
	
	if (particles.size() != num_points) {
		refreshParticles();
	}

    if (lastTime == 0) {
        lastTime = getElapsedTimef();
    }
    float now = getElapsedTimef();
    float dt = now - lastTime;
    lastTime = now;
    
    progress += dt * speed;
	const float baseline_y = dimensions.height * 0.5;

	for (int i=0; i<particles.size(); i++) {
		const float x = dimensions.width / particles.size() * i + 10;
		const float y = baseline_y + animation_height * sin(progress/particles.size()*(i+1));
		Particle & p = particles.at(i);
		p.update(x, y, baseline_y);
	}
}

void memoAktenScene::draw(){
	
	// -- center line
	ofSetColor(255 * 0.5);
	ofSetLineWidth(1);
	ofDrawLine(0,
			   dimensions.height * 0.5,
			   dimensions.width,
			   dimensions.height * 0.5);
	
	
	// -- lines between circles
	for (int myself=0; myself<particles.size(); myself++) {
		
		Particle & from = particles.at(myself);
		
		if (myself < particles.size()-1) {
			Particle & to = particles.at(myself+1);
			ofSetColor(255, 255*line_alpha);
			ofSetLineWidth(1);
			ofDrawLine(from, to);
			ofDrawLine(from.x, from.y, from.x, dimensions.height * 0.5);
		}
		
		for (int dest=0; dest<particles.size(); dest++) {
			Particle & to = particles.at(dest);
			const float distance = from.distance(to);
			if (distance < line_max_length) {
				float a = 1.0 - ofMap(distance, 0., line_max_length, 0., 1.);
				ofSetColor(255, 255*a);
				ofSetLineWidth(1);
				ofDrawLine(from, to);
			}
		}
	}
	
	// -- circles
	for (const auto &p: particles) {
		// moving circle
		ofSetColor(255);
		ofFill();
		ofDrawCircle(p, 3);
			
		// a dot on baseline
		ofSetColor(255 * 0.5);
		ofFill();
		ofDrawCircle(p.x, dimensions.height * 0.5, 2);
		
		// bang!
		ofSetColor(255, 255*p.circle_alpha);
		ofNoFill();
		ofDrawCircle(p.x, dimensions.height * 0.5, p.getRadius());
	}
}
