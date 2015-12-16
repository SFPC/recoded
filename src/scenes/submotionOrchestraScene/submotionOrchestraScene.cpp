#include "submotionOrchestraScene.h"

void submotionOrchestraScene::setup(){

	speed.set("speed", 2.1, 0.1, 3.);
	parameters.add(speed);

	size.set("size", 1.2, 0.1, 3.);
	parameters.add(size);
	
	sphere.setResolution(6);
	sphere.setRadius(350);
	for (auto &v: sphere.getMesh().getVertices()) {
		if (abs(v.x) > 3) {
			v += ofRandom(-5, 5);
			points_src.emplace_back(v);
		}
	}
	std::random_shuffle(begin(points_src), end(points_src));
	points_dest.clear();
	
    setAuthor("Motoi Shimizu");
    setOriginalArtist("Submotion Orchestra");
    loadCode("scenes/submotionOrchestraScene/exampleCode.cpp");
}

void submotionOrchestraScene::update(){
	
	k = getElapsedTimef() * speed;
	
	points_dest.clear();
	
	for (int i=0; i<points_src.size(); i++) {
		const float radian = ofDegToRad(360. / points_src.size() * i);
		const float scale = ofMap(sin(radian * k), -1., 1., size, 1.);
		const ofPoint & src = points_src.at(i);
		ofPoint p = src * scale;
		points_dest.emplace_back(p);
	}
	
	assert(points_src.size() == points_dest.size());
}

void submotionOrchestraScene::draw(){
	cam.begin();
	
	ofRotate(10. * k, 1., 1., 1.);
	
	glEnable(GL_DEPTH_TEST);
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor4d(1.0, 1.0, 1.0, 1.0);
	for (int i=0; i<points_src.size(); i++) {
		const ofPoint & src = points_src.at(i);
		const ofPoint & dest = points_dest.at(i);
		glVertex3d(src.x*0.3, src.y*0.3, src.z*0.3);
		glVertex3d(dest.x, dest.y, dest.z);
	}
	glEnd();
	
	static GLfloat distance[] = { 0.0, 0.0, 1.0 };
	glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
	glPointSize(40000);
	glColor4d(1.0, 1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (const auto & dest: points_dest) {
		glVertex3d(dest.x, dest.y, dest.z);
	}
	glEnd();
	glDisable(GL_DEPTH_TEST);

	cam.end();
}
