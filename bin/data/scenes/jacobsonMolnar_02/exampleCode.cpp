for (int i = 0; i < grid.getOutline().size(); i++) {
    float theta = rand(360) + pow(-1, ofRandom(1)) * [[rotationSpeed]] * time);
    polyline box = grid.getOutline()[i];
    path lineFill = getLineFill(box, [[stepSize]], theta);
    for (int j = 0; j < lineFill.getOutline().size(); j++) {
        polyline line = lineFill.getOutline()[j];
        line.draw();
    }
}
