// code goes here!

//if you want to show a parameter's value, which highlights when it changes you need to enclose it's name in double square brackets.
// for a parameter named myParam you shoudl put [[myParam]] in the pseudo code below.


void draw() {
    textWidth = getTextBoundingBox().width;
    zoom = screenWidth * [[widthScale]] / textWidth;
    setBackgroundColor(ColorFromHSV(mod(getElapsedTime(), 255), 200, 255));
    points = getTextPointsWithSpacing([[drawEvery]]);

    pushMatrix();
    scaleScreen(zoom);

    for (point in points) {
        drawImage([[imageScale]]);
    }

    popMatrix();
}
