#version 120

#ifdef GL_ES
precision mediump float;
#endif

#define STEP_MIN        0.021
#define STEP_MAX        0.03
#define STEP_FADE       1.3

#define TIME_SADDLE     0.1
#define MAX_TIME        0.55

#define DISTANCE_SCALE  500.0
#define TIME_SCALE      130.0

uniform float time;
uniform vec2 resolution;

uniform float rOffset, gOffset, bOffset;
uniform float thickness;

float nearZero(float val) {
    float timeScale = (time - TIME_SADDLE) / MAX_TIME;
    return smoothstep(thickness * (STEP_FADE + timeScale), thickness, abs(val));
}

void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec2 center = resolution * 0.5;

    float centerDistance = length(pos - center);
    
    vec3 color1 = vec3(0.692, 0.995, 0.997); // #B0FEFE
    vec3 color2 = vec3(1.000, 0.909, 0.345); // #FFE858
    vec3 color3 = vec3(1.000, 0.435, 0.380); // #FF6F61
    
    float r = cos((centerDistance / DISTANCE_SCALE - 0.3) * time * TIME_SCALE);
    float g = cos((centerDistance / DISTANCE_SCALE - 0.4) * time * TIME_SCALE);
    float b = cos((centerDistance / DISTANCE_SCALE - 0.5) * time * TIME_SCALE);
    
    vec3 color = vec3(0.);
    color += nearZero(r) * color1;
    color += nearZero(g) * color2;
    color += nearZero(b) * color3;
    
    gl_FragColor = vec4(color, 1.0);
}
