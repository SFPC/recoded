
// draw triangles column
float drawTrianglesYAxis(float xPos, float yPos){
    for (int i =0; i < [[yElements]]; i++) {
        
        triangleWidth = screenHeight / yElements;
        triangleHeight = triangleWidth;
        sineWaveOffset = sin((ofGetElapsedTimef() + i * 1.9) * 3.1);

        drawTriangle(xPos,
                     yPos + sineWaveOffset + i * triangleHeight,
                     triangleWidth,
                     triangleHeight);
      }
    retrun xPos;
    retrun triangleWidth;
}
// duplicate triangles column on the x axis
void draw(){
    for (int i = 0; i < [[xElements]]; i++) {
        
        x[i] = (xPos[i-1] + (triangleWidth[i-1] * 0.5) + (triangleWidth[i] * 0.5));

        drawTrianglesYAxis(x, 0)
    }
}

