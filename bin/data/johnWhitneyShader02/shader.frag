#version 120

#ifdef GL_ES
precision mediump float;
#endif

#define STEP_MIN        0.021
#define STEP_MAX        0.03

#define DISTANCE_SCALE  500.0
#define TIME_SCALE      130.0

uniform float time;
uniform vec2 resolution;

float nearZero(float val) {
    return smoothstep(STEP_MAX, STEP_MIN, abs(val));
}

void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec2 center = resolution * 0.5;

    float centerDistance = length(pos - center);
    
    float r = cos((centerDistance / DISTANCE_SCALE - 0.3) * time * TIME_SCALE);
    float g = cos((centerDistance / DISTANCE_SCALE - 0.4) * time * TIME_SCALE);
    float b = cos((centerDistance / DISTANCE_SCALE - 0.5) * time * TIME_SCALE);
    
    vec3 color = vec3(0.);
    color.r = nearZero(r);
    color.g = nearZero(g);
    color.b = nearZero(b);
    
    gl_FragColor = vec4(color, 1.0);
}
