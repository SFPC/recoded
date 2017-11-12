void setup(){
	img.loadImage("N00004808.jpg");
	img.setImageType(OF_IMAGE_GRAYSCALE);
}

void draw(){
	setRectMode(OF_RECTMODE_CENTER);	
	for (int i = 0; i < img.getWidth(); i=i+20) {
		for (int j = 0; j < img.getHeight(); j=j+20) {
			color c = img.getColor(i, j); 
			float bright = c.getBrightness(); 

			pushMatrix();

			translate(i, j);
			rotateZ(ofMap(bright, 0, 255, 0, [[rotation]]));
			setColor(255, [[alpha]]);
			drawLine([[posX1]], 0, 5, 0);
			popMatrix();
		}
	}
}
