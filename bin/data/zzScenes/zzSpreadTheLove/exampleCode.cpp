// spread the love

for (int i = 0; i < paths.size(); i++){
    pushMatrix();
    rotateY([[spreadRotation]] * (i*0.1 + 1));
    paths[i].draw();
    
    vector < polyline > lines = paths[i].getOutline();
    
    for (int j = 0; j < lines.size(); j++){
        polyline line = lines[j].getResampledBySpacing(2);
        for (int k = 0; k < 400; k++){
            float pct = fmod(getElapsedTimef()*0.02  + map(k,0, 400, 0, 1), 1);
            point pt = line.getPointAtPercent(pct);
            circle(pt, 2);
        }
    }
    
    popMatrix();

}
