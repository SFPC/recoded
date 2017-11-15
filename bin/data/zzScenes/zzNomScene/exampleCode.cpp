for (int h = 0; h < 7; h++) {
    pushMatrix();
    translate(0, 20*h - 3.5*20-20);
    
    for (int i = 0; i < paths.size(); i++) {
        vector < polyline > lines = paths[i].getOutline();
        for (int j = 0; j < lines.size(); j++) {
            lines[j] = lines[j].getResampledBySpacing(3);
        }
        
        
        for (int j = 0; j < lines.size(); j++) {
            for (int k = 0; k < lines[j].size(); k++) {
                float y = lines[j][k].x + lines[j][k].y * 0.1;
                lines[j][k].y +=
                    signedNoise(y*(0.001) + getElapsedTimef(), h*0.2) * [[wavyAmt]];
            }
        }
        
        beginShape();
        for (int j = 0; j < lines.size(); j++) {
            if (j != 0) nextContour();
                for (int k = 0; k < lines[j].size(); k++) {
                    setColor(255, 255, 0, map(h, 0, 6, 20, 80));
                    vertex(lines[j][k]);
                }
        }
        endShape();
    }
    popMatrix();
    
}
