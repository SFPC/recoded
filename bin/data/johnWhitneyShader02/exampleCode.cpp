void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec2 center = resolution * 0.5;
    
    float centerDistance = length(pos - center);
    
    float r = cos((centerDistance / DISTANCE_SCALE - 0.3) * [[time]] * TIME_SCALE);
    float g = cos((centerDistance / DISTANCE_SCALE - 0.4) * [[time]] * TIME_SCALE);
    float b = cos((centerDistance / DISTANCE_SCALE - 0.5) * [[time]] * TIME_SCALE);
    
    vec3 color = vec3(0.);
    color.r = nearZero(r);
    color.g = nearZero(g);
    color.b = nearZero(b);
    
    gl_FragColor = vec4(color, 1.0);
}
