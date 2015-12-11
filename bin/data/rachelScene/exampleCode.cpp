void drawPixel(int x, int y) {
    // Make it weird
    float factor_one = [[time]] * y * sin(y) * [[posY]] / y;
    float factor_two = [[posX]] / x + [[posY]] / y;
    float weirdness = tan(factor_one / factor_two);
    
    // Output color
    setPixelBrightness(weirdness);
}