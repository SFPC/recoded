void draw() {

	string text = "MIT MEDIA LAB";
    
    drawText(text);

	for(int x = 0; x < screenWidth; x++) {
		for(int y = 0; y < screenHeight; y++) {

			Vector2 distortion = new Vector2(0, 0);

			distortion += noise2D(frequency);
			distortion.y += 0.0;

			drawPixel(x, y, distortion);

		}
	}
	
}
