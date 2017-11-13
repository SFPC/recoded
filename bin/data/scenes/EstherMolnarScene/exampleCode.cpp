void draw(){
	background(black);
	setRectMode(OF_RECTMODE_CENTER);
	enableBlendMode(BLENDMODE_ADD);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			setColor(255,[[color]]*i/2,[[color]]*j/2);
			drawRectangle(
				50 + i * 140 + ofRandom(-[[move]], [[move]]) / 30, 
				50 + j * 140 + ofRandom(-[[move]], [[move]]) / 30,
				[[size]],
				[[size]]);
		}
	}
	disableBlendMode();
}
