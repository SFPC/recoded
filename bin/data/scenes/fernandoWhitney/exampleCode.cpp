void draw() {

	int circles = 30;

	for(int i = 0; i < circles; i++) {
		
		float wobble = sin(frequency + time) * amplitude;

		Vector2 position = new Vector2(
			sin(2PI) * outerRadius * wobble,
			cos(2PI) * outerRadius * wobble
		);

		drawCircle(innerRadius, position);
	}
	
}