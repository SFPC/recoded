for (int i = 0; i < grid.getOutline().size(); i++) {
    theta = rand(360) + pow(-1, random(1)) * [[rotationSpeed]] * time;
    polyline box = grid.getOutline()[i];
    path lineFill = getLineFill(box, [[stepSize]], theta);
    for (int j = 0; j < lineFill.getOutline().size(); j++) {
        polyline line = lineFill.getOutline()[j];
        line.draw();
    }
}