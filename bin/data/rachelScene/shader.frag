#version 120

uniform float posx;
uniform float posy;
uniform float time;
// uniform float scale;
uniform vec2 resolution;

void main(void) {
    
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    
    float mx = posx / gl_FragCoord.x;
    float my = posy / gl_FragCoord.y;
    
// 1 ----------------------
    
    float factor_one, factor_two, weirdness;
    
    factor_one = time / 50 * gl_FragCoord.y * sin(gl_FragCoord.y * 0.01) * my;
    factor_two = mx + my;
    weirdness = tan(factor_one/factor_two);
    
//    black and white
    gl_FragColor = vec4(weirdness, weirdness, weirdness, 1.0);
    
    // blue and pink
//    gl_FragColor = vec4(weirdness, 0.5, 1.0, 1.0);
    
    // pink and yellow
//    gl_FragColor = vec4(1.0, weirdness, 0.5, 1.0);
    
// 2 ----------------------
    
//    float red, green, blue;
//    
//    red = my * gl_FragCoord.y;
//    blue = gl_FragCoord.x / time/250 * tan(gl_FragCoord.y);
//    green = tan(blue+red);
//    
//    gl_FragColor = vec4(red, green, blue, 1.0);

// 3 ----------------------
     // a fairly plain one
    
//    float red, green, blue;
//    
//    red = time / 0.01;
//    blue = gl_FragCoord.y;
//    green = cos(gl_FragCoord.x / red);
//    
//    gl_FragColor = vec4(red, green, blue, 1.0);

// 4 ----------------------
    
//    float red, green, blue;
//    
//    red = tan(time * 0.0001) * gl_FragCoord.y * my;
//    blue = sin(time/mx)/10 * my;
//    green = tan(blue/red) * my * 40;
//    
//    gl_FragColor = vec4(red, green, blue, 1.0);
    
}