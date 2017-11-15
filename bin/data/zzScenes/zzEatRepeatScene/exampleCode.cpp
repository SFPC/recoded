translate(midPt);
for (int i = 0; i < groups.size(); i++){
    
    vector < svgPath > paths = groups[i]->getElementsForType<svgPath>();
    
    pushMatrix();
    
    rotateX(getElapsedTimef() * (1 + i*0.2) *[[amtRotateX]] * 30 );
    rotateY(getElapsedTimef() * (1 + i*0.2) *[[amtRotateY]] * 30 );
    rotateZ( (timeAdder * [[amtRotateZ]] * 200 *( i % 2 == 0 ? -1 : 1)));
    for (int j = 0; j < paths.size(); j++){
        paths[j]->path.draw();
    }
    popMatrix();
}
