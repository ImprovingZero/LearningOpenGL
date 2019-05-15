#version 440

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	sampler2D specularTex;
};

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;

uniform Material material;

uniform vec3 LightPos0;
uniform vec3 cameraPos;

void main()
{
	//Ambient Light
	vec3 ambientLight = material.ambient;

	//Difuss Light
	vec3 PosToLightDirVec = normalize(vs_position - LightPos0);
	float diffuse = clamp(dot(PosToLightDirVec, vs_normal), 0, 1);
	vec3 Diffusefinal = material.diffuse * diffuse;

	//Specular light
	vec3 lightToPosDirVec =  normalize(vs_position - LightPos0);
	vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, normalize(vs_normal)));
	vec3 posToViewDirVec = normalize(cameraPos - vs_position);
	float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 30);
	vec3 specularFinal = material.specular * specularConstant;

	//Attenuation light

	//Final light

	
	fs_color = texture(material.diffuseTex, vs_texcoord)*
		(vec4(ambientLight,1.f) + vec4(Diffusefinal,1.f) + vec4(specularFinal, 1.f));

}