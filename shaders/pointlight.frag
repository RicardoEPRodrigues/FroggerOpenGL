#version 330

uniform sampler2D texmap1;
uniform sampler2D texmap2;
uniform sampler2D texmap3;
uniform sampler2D texmap4;
uniform sampler2D texmap5;
uniform sampler2D texmap6;
uniform sampler2D texmap7;
uniform sampler2D texmap8;
uniform sampler2D texmap9;
uniform sampler2D texmap10;
uniform sampler2D texmap11;
uniform sampler2D texmap12;
uniform sampler2D texmap13;

uniform int lightsActive;
uniform int fogActive;

uniform int texMode;
out vec4 colorOut;

struct Materials {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	int texCount;
};

uniform Materials mat;

struct Lights {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;

	float isEnabled;
	float isLocal;
	float isSpot;
	
	vec4 position;
	vec3 lightDirection; // camera space
	vec3 spotDirection;
	
	float spotCosCutoff;
};

const int MaxLights = 10;
uniform Lights lit[MaxLights];
//uniform Lights lit;

in Data {
	vec3 normal;
	vec3 eye;
	vec3 lightDir[MaxLights];
	//vec3 lightDir;
	//vec3 sl_dir;
	float distance;
	vec2 tex_coord;
} DataIn;

uniform vec4 s_dir[MaxLights];
// uniform vec4 s_dir;

vec4 texel;

vec3 applyFog( in vec3 rgb, // original color of the pixel
				in float distance ) // camera to point distance
{
	float b = 0.01;
	float fogAmount = exp( -distance*b );
	vec3 fogColor = vec3(0.5,0.6,0.7);
	return mix( fogColor, rgb, fogAmount );
}

void main() {
	vec3 n = normalize(DataIn.normal);
	//vec3 l = normalize(DataIn.lightDir);
	vec3 e = normalize(DataIn.eye);

	float intensity = 0.0;
	float finalIntensity = 0.0;
    vec4 spec = vec4(0.0);
	vec4 finalSpec = vec4(0.0);

	vec4 compAmb = vec4(0.0);
	vec4 compDif = vec4(0.0);
	vec4 compSpc = vec4(0.0);

	if ( lightsActive == 1.0 ) {
		for (int i = 0; i < MaxLights; ++i) {
		//int i = 0;
			if(lit[i].isEnabled == 1.0) {
				vec3 l = normalize(DataIn.lightDir[i]);
				if(lit[i].isLocal == 1.0) {
					if(lit[i].isSpot == 1.0) {
						//vec3 s = normalize(-s_dir[i].xyz);
						vec3 s = normalize(-lit[i].spotDirection.xyz);
						if(dot(s,l) > lit[i].spotCosCutoff) {
							intensity = max(dot(n,l), 0.0);
							finalIntensity = max(finalIntensity, intensity);
							if (intensity > 0.0) {
								vec3 h = normalize(l + e);
								float intSpec = max(dot(h,n), 0.0);
								spec = lit[i].specular * mat.specular * pow(intSpec, mat.shininess);
								//spec = mat.specular * pow(intSpec, mat.shininess);
								finalSpec = max(finalSpec, spec);
								compDif += intensity * lit[i].diffuse;
								compSpc += spec;
							}
						}
					}
	
					else {
						intensity = max(dot(n,l), 0.0);
						finalIntensity = max(finalIntensity, intensity);
						if (intensity > 0.0) {
							vec3 h = normalize(l + e);
							float intSpec = max(dot(h,n), 0.0);
							spec = lit[i].specular * mat.specular * pow(intSpec, mat.shininess);
							//spec = mat.specular * pow(intSpec, mat.shininess);
							finalSpec = max(finalSpec, spec);
							compDif += intensity * lit[i].diffuse;
							compSpc += spec;
						}
					}
				}
	
				else {
					vec3 s = normalize(-lit[i].spotDirection.xyz);
					intensity = max(dot(n,s), 0.0);
					finalIntensity = max(finalIntensity, intensity);
					if (intensity > 0.0) {
						//vec3 s = normalize(-s_dir[i].xyz);
						vec3 h = normalize(s + e);
						float intSpec = max(dot(h,n), 0.0);
						spec = lit[i].specular * mat.specular * pow(intSpec, mat.shininess);
						//spec = mat.specular * pow(intSpec, mat.shininess);
						finalSpec = max(finalSpec, spec);
						compDif += intensity * lit[i].diffuse;
						compSpc += spec;
					}
				}
			}
		}

		vec4 colorToUse = vec4(0);
		vec4 ambientToUse = vec4(0);
		if(texMode == 0){
			colorToUse = mat.diffuse;
			ambientToUse = mat.ambient;
		}
		else {
			ambientToUse =  colorToUse * 0.1;
			if(texMode == 1){
				colorToUse = texture(texmap1, DataIn.tex_coord);  // texel from wood.tga
			}
			else if(texMode == 2){
				colorToUse = texture(texmap2, DataIn.tex_coord);  // texel from water.tga
			}
			else if(texMode == 3){
				colorToUse = texture(texmap3, DataIn.tex_coord);  // texel from asphalt.tga
			}
			else if(texMode == 4){
				colorToUse = mat.ambient*texture(texmap4, DataIn.tex_coord);  // texel from particula.bmp
			}

			else if(texMode == 5){
				colorToUse = texture(texmap5, DataIn.tex_coord);  // texel from tree.tga
			}
		
			else if(texMode == 6){
				colorToUse = texture(texmap6, DataIn.tex_coord);  // texel from grass.tga
			}
			else if(texMode == 7){
				colorToUse = texture(texmap7, DataIn.tex_coord);  // texel from turtle.bmp
			}
			else if(texMode == 8){
				colorToUse = texture(texmap8, DataIn.tex_coord);  // texel from Flare1.bmp
			}
			else if(texMode == 9){
				colorToUse = texture(texmap9, DataIn.tex_coord);  // texel from Flare2.bmp
			}
			else if(texMode == 10){
				colorToUse = texture(texmap10, DataIn.tex_coord);  // texel from Flare3.bmo
			}
			else if(texMode == 11){
				colorToUse = texture(texmap11, DataIn.tex_coord);  // texel from Flare4.bmp
			}
			else if(texMode == 12){
				colorToUse = texture(texmap12, DataIn.tex_coord);  // texel from Sun.bmp
			}
			else{
				colorToUse = texture(texmap13, DataIn.tex_coord);  // texel from head.tga
			}
		}
		
		
		colorOut = max(finalIntensity *  colorToUse + finalSpec , ambientToUse);
		vec3 foggedColor = applyFog( colorOut.xyz, DataIn.distance );
		if ( mat.diffuse[3] == 1.0 )
			colorOut = vec4( foggedColor.xyz, colorToUse[3] );
		else {
			colorOut = vec4( foggedColor.xyz, mat.diffuse[3] );
		}
	} else {
		vec4 colorToUse = vec4(0);
		vec4 ambientToUse = vec4(0);
		if(texMode == 0){
			colorToUse = mat.diffuse;
			ambientToUse = mat.ambient;
		}
		else {
			ambientToUse =  colorToUse * 0.1;
			if(texMode == 1){
				colorToUse = texture(texmap1, DataIn.tex_coord);  // texel from wood.tga
			}
			else if(texMode == 2){
				colorToUse = texture(texmap2, DataIn.tex_coord);  // texel from water.tga
			}
			else if(texMode == 3){
				colorToUse = texture(texmap3, DataIn.tex_coord);  // texel from asphalt.tga
			}
			else if(texMode == 4){
				colorToUse = mat.ambient*texture(texmap4, DataIn.tex_coord);  // texel from particula.bmp
			}

			else if(texMode == 5){
				colorToUse = texture(texmap5, DataIn.tex_coord);  // texel from tree.tga
			}
		
			else if(texMode == 6){
				colorToUse = texture(texmap6, DataIn.tex_coord);  // texel from grass.tga
			}
			else if(texMode == 7){
				colorToUse = texture(texmap7, DataIn.tex_coord);  // texel from turtle.bmp
			}
			else if(texMode == 8){
				colorToUse = texture(texmap8, DataIn.tex_coord);  // texel from Flare1.bmp
			}
			else if(texMode == 9){
				colorToUse = texture(texmap9, DataIn.tex_coord);  // texel from Flare2.bmp
			}
			else if(texMode == 10){
				colorToUse = texture(texmap10, DataIn.tex_coord);  // texel from Flare3.bmo
			}
			else if(texMode == 11){
				colorToUse = texture(texmap11, DataIn.tex_coord);  // texel from Flare4.bmp
			}
			else if(texMode == 12){
				colorToUse = texture(texmap12, DataIn.tex_coord);  // texel from Sun.bmp
			}
			else{
				colorToUse = texture(texmap13, DataIn.tex_coord);  // texel from head.tga
			}
		}
		
		
		colorOut = max(colorToUse , ambientToUse);
		vec3 foggedColor;
		if(fogActive == 1.0)
			foggedColor = applyFog( colorOut.xyz, DataIn.distance );
		else
			foggedColor = colorOut.xyz;
		/*
		if ( mat.diffuse[3] == 1.0 )
			colorOut = vec4( foggedColor.xyz, colorToUse[3] );
		else {
			colorOut = vec4( foggedColor.xyz, mat.diffuse[3] );
		}
		*/
		colorOut = vec4( foggedColor.xyz, colorToUse[3] * mat.diffuse[3] );
	}
}