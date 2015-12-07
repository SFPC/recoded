//
// Recode:
// Cover art of "Finest Hour" by Submotion Orchestra
// https://soundcloud.com/submotion-orchestra/always-synkro-remix-bip
//
// Motoi Shimizu(@motoishmz, http://backspace.tokyo/en) from SFPC First Class
//

ofSpherePrimitive sphere;
sphere.setResolution(6);
std::vector<ofPoint> points_src = sphere.getMesh().getVertices();
std::vector<ofPoint> points_dest;
float k = ofGetElapsedTimef() * speed;

for (int i=0; i<points_src.size(); i++) {
	const float radian = ofDegToRad(360. / points_src.size() * i);
	const float scale = ofMap(sin(radian * k), -1., 1., size, 1.);
	const ofPoint & src = points_src.at(i);
	ofPoint p = src * scale;
	points_dest.emplace_back(p);
}