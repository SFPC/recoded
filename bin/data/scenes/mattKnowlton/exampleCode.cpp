void draw(){
    
    int tileCount = 40;
    int gridSize = width/tileCount;
    int numberOfParticles = tileCount * tileCount;
    
    loadImages();
    createParticles(numberOfParticles);
    
    for(int i=0; i<width; i+=gridSize){
        for(int i=0; i<height; i+=gridSize){
            color co = getParticleColorFromImage(x, y);
            setParticleColor(co);
            createParticleAt(x, y);
        }
    }
    
    drawParticles();
}
