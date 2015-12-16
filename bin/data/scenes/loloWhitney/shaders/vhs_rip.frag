#version 120

uniform sampler2DRect tex0; 
uniform float	t_width;
uniform float	t_height;
uniform float t;
uniform float wave_am;
uniform float disor;

float random (vec2 st) { 
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))* 
        43758.5453123);
}

void main()
{
    vec4 cor = gl_TexCoord[0];
    vec2 s_cor = vec2(cor.xy);
  //  vec4 input_texture = texture2DRect(tex0,cor.xy+vec2(sin((t*2.0)+cor.y*100.0)*4.0,0.0));
   
    bool noise_con = false;
	if(cor.y > 0.0){
		noise_con = true;
	}

	float d = distance(s_cor,vec2(s_cor.x,(tan(t*1.0)*t_height)));
	vec4 noise_sample = vec4(0.0);
	bool	bar_con = false;

	bar_con = true;
	if(noise_con && bar_con)
	{
		s_cor.x+=cos(t+s_cor.y/10.0)*wave_am;	
	}

	float l = fract(random(s_cor+vec2(0.0,t/20.0)));

    vec2 distort = vec2((bar_con ? cos(t*.1+s_cor.y*2.0)*disor : 0.0),0.0);
 	vec4 xxx = texture2DRect(tex0, gl_TexCoord[0].xy+distort*disor);

 	vec4 input_texture = texture2DRect(tex0,s_cor);

 	//input_texture+=xxx;


    gl_FragColor = noise_sample+input_texture+xxx;
}