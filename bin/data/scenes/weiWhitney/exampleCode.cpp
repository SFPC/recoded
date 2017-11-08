
for (int i = 0; i < nStarPts; i++){
    float x = origx + outerRadius * cos(angle);
    float y = origy + outerRadius * sin(angle);
    ofVertex(origx + outerRadius * cos(angle),origy + outerRadius * sin(angle));
    angle = angle + angleChangePerPt;
}
