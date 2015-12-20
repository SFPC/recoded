#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2DRect texture0;
uniform float dimAmt;

void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec3 src = texture2DRect(texture0, pos).rgb;
    
    src *= dimAmt;

    gl_FragColor = vec4(src, 1.0);
}
