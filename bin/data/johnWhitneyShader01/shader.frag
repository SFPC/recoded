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

#define STEP_MIN       0.021
#define STEP_MAX       0.03

uniform float time;
uniform vec2 resolution;

float drawLine(vec2 uv, float y) {
    float dist = abs(uv.y - y);
    return smoothstep(STEP_MAX, STEP_MIN, dist);
}

void main()
{
    vec2 uv = gl_FragCoord.xy / resolution.xy - vec2(0.5, 0.5);
    vec3 color = vec3(0.);
    
    float redVal   = time * (uv.x * HORIZ_SCALE + RED_SCALE);
    float redY     = sin(redVal) * VERT_SCALE;
    color.r        = drawLine(uv, redY);
    
    float greenVal = time * (uv.x * HORIZ_SCALE + GREEN_SCALE);
    float greenY   = sin(greenVal) * VERT_SCALE;
    color.g        = drawLine(uv, greenY);
    
    float blueVal  = time * (uv.x * HORIZ_SCALE + BLUE_SCALE);
    float blueY    = sin(blueVal) * VERT_SCALE;
    color.b        = drawLine(uv, blueY);
    
    gl_FragColor = vec4(color, 1.0);
}
 