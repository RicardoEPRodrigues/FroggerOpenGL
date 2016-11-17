#version 330

uniform mat4 m_pvm;
uniform mat4 m_viewModel;
uniform mat3 m_normal;

const int MaxLights = 10;

uniform vec4 l_pos[MaxLights];
//uniform vec4 l_pos;
//uniform vec4 s_dir;

in vec4 position;
in vec4 normal;    //por causa do gerador de geometria
in vec4 texCoord;

out Data {
	vec3 normal;
	vec3 eye;
	vec3 lightDir[MaxLights];
	//vec3 lightDir;
	float distance;
	vec2 tex_coord;
} DataOut;

void main () {

	vec4 pos = m_viewModel * position;
	DataOut.distance = length(pos);

	DataOut.normal = normalize(m_normal * normal.xyz);
	
	for(int i = 0; i < MaxLights; ++i)
		DataOut.lightDir[i] = vec3(l_pos[i] - pos);
	//DataOut.lightDir = vec3(l_pos - pos);
	
	DataOut.eye = vec3(-pos);
	
	DataOut.tex_coord = texCoord.st;

	gl_Position = m_pvm * position;	
}