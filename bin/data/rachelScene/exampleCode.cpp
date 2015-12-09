void main(void) {
    
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    
    float mx = posx / gl_FragCoord.x;
    float my = posy / gl_FragCoord.y;

    float factor_one, factor_two, weirdness;
    
    factor_one = time / 50 * gl_FragCoord.y * sin(gl_FragCoord.y * 0.01) * my;
    factor_two = mx + my;
    weirdness = tan(factor_one/factor_two);
    
    // black and white
    gl_FragColor = vec4(weirdness, weirdness, weirdness, 1.0);
    
    // blue and pink
    // gl_FragColor = vec4(weirdness, 0.5, 1.0, 1.0);
    
    // pink and yellow
    // gl_FragColor = vec4(1.0, weirdness, 0.5, 1.0);
}