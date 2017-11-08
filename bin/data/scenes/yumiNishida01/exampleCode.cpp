
void reset(){
    lines.clear();
    x = 0;
    line_number = 0;
}

void draw(){
    setHue([[color]]);
    int y = VISUALS_HEIGHT*0.01 + VISUALS_HEIGHT*0.12*line_number;
    lines[line_number].addVertex(x+Random([[x_]], 20),
                                 y+Random(20, [[y_]]));

    x+=10;
    if(x > VISUALS_WIDTH){
        x = 0;
        line_number++;
        addLine();
    }
    if(y > VISUALS_HEIGHT*0.9){
        reset();
    }
    for (int i = 0; i < lines.size(); i++) {
        lines[i].draw();
    }
}
