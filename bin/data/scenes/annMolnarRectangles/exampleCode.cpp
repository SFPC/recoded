void draw() {
    int col = 9;
    int row = 6;
    Colors myColors = [red, blue, orange];
    for (int i=0; i<col;i++){
        for (int j=0;j<row;j++){
            // define number of repeated squares
            int repeat;
            if (i<3){
                repeat = 1+i*i;
            } else if (i == 3) {
                repeat = 40;
            } else {
                int f = (col-i)*(col-i);
            }

            // select color
            setColor( myColors[ random(0,3)]);
            for (int k=0;k<repeat;k++) {
                drawSquare(i,j);
            }
        }
    }
}

void drawSquare(int a, int b) {
    beginShape();
    int start_x = random(-xPos, xPos);
    int start_y = random(-yPos, yPos);
    startSquare(start_x, start_y);
    addCorner(start_x + random(), start_y + random());
    endShape(true);
}
