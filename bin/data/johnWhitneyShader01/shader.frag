#version 120

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.1415926535897932384626433832795

#define HORIZ_SCALE    10.0
#define VERT_SCALE     0.15

#define RED_SCALE      1.
#define BLUE_SCALE     3.
#define GREEN_SCALE    9.

#define STEP_MIN       0.003
#define STEP_MAX       0.007

uniform float time;
uniform vec2 resolution;

uniform float redOffset, blueOffset, greenOffset;
uniform float redScale, blueScale, greenScale;

float f(float x, float xOffset, float yScale) {
    return sin(time * (x * HORIZ_SCALE + xOffset)) * yScale;
}

float fprime(float x, float xOffset, float yScale) {
    return -HORIZ_SCALE * time * yScale * cos(time * (xOffset + HORIZ_SCALE * x));
}

// adapted from http://www.iquilezles.org/www/articles/distance/distance.htm

float c(vec2 uv, float xOffset, float yScale) {
    float fp = fprime(uv.x, xOffset, yScale);
    float de = abs(f(uv.x, xOffset, yScale) - uv.y) / sqrt(1 + fp*fp);
    return smoothstep(STEP_MAX, STEP_MIN, de);
}

void main()
{
    vec2 uv = gl_FragCoord.xy / resolution.xy - vec2(0.5, 0.5);
    vec3 color = vec3(0.);
    
    vec3 color1 = vec3(0.792, 0.352, 0.513); // #CA5A83
    vec3 color2 = vec3(1.000, 0.767, 0.388); // #FFC463
    vec3 color3 = vec3(0.779, 0.114, 0.249); // #C71D3F
    
    color += c(uv, redOffset,   redScale)   * color1;
    color += c(uv, blueOffset,  blueScale)  * color2;
    color += c(uv, greenOffset, greenScale) * color3;
    
    gl_FragColor = vec4(color, 1.0);
}
 