void main()
{
	vec4	the_vertex = gl_Vertex;
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * the_vertex;
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
}