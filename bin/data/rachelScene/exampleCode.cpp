void main(void) {
    float x = gl_FragCoord.x;
    float y = gl_FragCoord.y;
    
    float mx = [[posX]] / x;
    float my = [[posY]] / y;
    
    // Make it weird
    float factor_one = [[time]] * y * sin(y * 0.01) * my;
    float factor_two = mx + my;
    float weirdness = tan(factor_one / factor_two);
    
    // Output color
    gl_FragColor = vec4(weirdness, weirdness, weirdness, 1.0);
}