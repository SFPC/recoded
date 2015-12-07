//
// Recode:
// Simple Harmonic Motion #5 (2011) by Memo Akten
// http://www.memo.tv/simple-harmonic-motion-5/
//
// Motoi Shimizu(@motoishmz, http://backspace.tokyo/en) from SFPC First Class
//

const float progress = ofGetElapsedTimef() * speed;
const float baseline_y = dimensions.height * 0.5;

for (int i=0; i<particles.size(); i++) {
	const float x = dimensions.width / particles.size() * i + 30;
	const float y = baseline_y + animation_height * sin(progress/particles.size()*(i+1));
	particles.at(i).update(x, y);
}