void drawPixel(int x, int y) {
    float centerDistance = distanceFromCenter(x, y);
    
    float color1 = cos((centerDistance - 0.3) * [[time]]);
    float color2 = cos((centerDistance - 0.4) * [[time]]);
    float color3 = cos((centerDistance - 0.5) * [[time]]);
    
    setThickness([[thickness]]);
    drawPixelColor(r, g, b);
}
