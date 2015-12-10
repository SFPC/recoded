// In many works of James and John Whitney trigonomic equations are used to generate animation
// This sketch shows a simple Lissajous curve animation to explain the principle


// Moving the eyes on the curve is done by animating the phase of the trigonomic functions
// Depending on the animation speed parameter the phase value is incremented with each new frame
animSpeed[1] = 60 * pAnimSpeed;
pPhase.set(( ofGetFrameNum() % animSpeed[1] ) * TWO_PI / animSpeed[1]);


// The shape of a Lissajous curve is highly sensitive to
// the relation of the frequencies used in the equations for X and Y
// The values that define this relation are randomly chosen every 3 seconds here

if( ( ofGetElapsedTimeMillis() - timerLastTime ) > 3000 ){
    plissajouRatioX.set(ofRandom(1,plissajouRatioX.getMax()));
    plissajouRatioY.set(ofRandom(1,plissajouRatioY.getMax()));
    timerLastTime = ofGetElapsedTimeMillis();
}


// Calculate the spacing of each element on the curve
spacingOnCurve = TWO_PI / [[Density]]

// Calculate the position and draw each element
for (int i = 0; i < [[Density]] ; i++) {
    
    // amplitude * sin ( angle + phase )
    x = [[Amplitude]] * cos( [[Lissajous Ratio X]] * spacingOnCurve * i + [[Phase]]);
    y = [[Amplitude]] * sin( [[Lissajous Ratio Y]] * spacingOnCurve * i + [[Phase]]);
    
    // calculate the size of each element
    iconWidth = eyesImg.getWidth() * Image Scale;
    iconHeight = eyesImg.getHeight() * Image Scale;
    
    // draw the element
    eyesImg.draw(x-iconWidth/2, y-iconHeight/2, iconWidth, iconHeight);
    
}