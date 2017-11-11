void setup(){
	img = loadImage("blurred_spot.png");
}
void draw(){
   background(black);
    Point center = dimensions.getCenter();
    translate(center);
    for (int  i = 0; i < [[Num lines]]; i++) {
		
        x = ofMap(sin(getElapsedSeconds()),-1,1,[[Inner Radius]], 
        	 [[Mid Radius]])*cos(i * phiLines);
        y = ofMap(sin(getElapsedSeconds()),-1,1,[[Inner Radius]],
        	[[Mid Radius]])*sin(i * phiLines);
        
        saveTransformation();
        translate(x,y);
        
        rotate(360 * getElapsedSeconds() * [[Speed]]
         + ofMap(i*phiLines,0,2*PI,0,360));
        //For loop for define and draw dots
        for (int j = -7; j < 7; j++) {
            Point a (2 * midRad / 14 * j, 0);
            setColor(255,100,100,255);
            img.draw(a, 100, 100);
        }
        restoreTransformation();
    }
}