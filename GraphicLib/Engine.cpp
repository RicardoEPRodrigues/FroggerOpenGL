/*
 * Engine.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: ricardo
 */

#include "Engine.h"

#include "stdio.h"

Engine::Engine() {
	this->matrixModule = new AVTMatrixModule();
	pvm_uniformId = 0;
	vm_uniformId = 0;
	normal_uniformId = 0;
	for(int i = 0; i<10 ; i++)
		lPos_uniformId[i] = 0;
	sDir_uniformId = 0;
	texMode_uniformId = 0;
	tex_loc1 = 0;
	tex_loc2 = 0;
	camera = TOPORTHO;
}

void Engine::recomputeMatrices() {
	// send matrices to OGL
	this->matrixModule->computeDerivedMatrix(PROJ_VIEW_MODEL);
	glUniformMatrix4fv(vm_uniformId, 1, GL_FALSE,
			this->matrixModule->mCompMatrix[VIEW_MODEL]);
	glUniformMatrix4fv(pvm_uniformId, 1, GL_FALSE,
			this->matrixModule->mCompMatrix[PROJ_VIEW_MODEL]);
	this->matrixModule->computeNormalMatrix3x3();
	glUniformMatrix3fv(normal_uniformId, 1, GL_FALSE,
			this->matrixModule->mNormal3x3);
}

// --------------------------------------------------------
//
// Shader Stuff
//

GLuint Engine::setupShaders() {

	// Shader for models
	shader.init();
	shader.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/pointlight.vert");
	shader.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/pointlight.frag");

	// set semantics for the shader variables
	glBindFragDataLocation(shader.getProgramIndex(), 0, "colorOut");
	glBindAttribLocation(shader.getProgramIndex(), VERTEX_COORD_ATTRIB,
			"position");
	glBindAttribLocation(shader.getProgramIndex(), NORMAL_ATTRIB, "normal");
	glBindAttribLocation(shader.getProgramIndex(), TEXTURE_COORD_ATTRIB,
			"texCoord");

	glLinkProgram(shader.getProgramIndex());

	texMode_uniformId = glGetUniformLocation(shader.getProgramIndex(), "texMode");
	pvm_uniformId = glGetUniformLocation(shader.getProgramIndex(), "m_pvm");
	vm_uniformId = glGetUniformLocation(shader.getProgramIndex(),
			"m_viewModel");
	normal_uniformId = glGetUniformLocation(shader.getProgramIndex(),
			"m_normal");
	lPos_uniformId[0] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[0]");
	lPos_uniformId[1] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[1]");
	lPos_uniformId[2] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[2]");
	lPos_uniformId[3] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[3]");
	lPos_uniformId[4] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[4]");
	lPos_uniformId[5] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[5]");
	lPos_uniformId[6] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[6]");
	lPos_uniformId[7] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[7]");
	lPos_uniformId[8] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[8]");
	lPos_uniformId[9] = glGetUniformLocation(shader.getProgramIndex(), "l_pos[9]");
	sDir_uniformId = glGetUniformLocation(shader.getProgramIndex(), "s_dir");
	tex_loc1 = glGetUniformLocation(shader.getProgramIndex(), "texmap1");
	tex_loc2 = glGetUniformLocation(shader.getProgramIndex(), "texmap2");
	tex_loc3 = glGetUniformLocation(shader.getProgramIndex(), "texmap3");
	tex_loc4 = glGetUniformLocation(shader.getProgramIndex(), "texmap4");
	tex_loc5 = glGetUniformLocation(shader.getProgramIndex(), "texmap5");
	tex_loc6 = glGetUniformLocation(shader.getProgramIndex(), "texmap6");
	tex_loc7 = glGetUniformLocation(shader.getProgramIndex(), "texmap7");
	tex_loc8 = glGetUniformLocation(shader.getProgramIndex(), "texmap8");
	tex_loc9 = glGetUniformLocation(shader.getProgramIndex(), "texmap9");
	tex_loc10 = glGetUniformLocation(shader.getProgramIndex(), "texmap10");
	tex_loc11 = glGetUniformLocation(shader.getProgramIndex(), "texmap11");
	tex_loc12 = glGetUniformLocation(shader.getProgramIndex(), "texmap12");
	tex_loc13 = glGetUniformLocation(shader.getProgramIndex(), "texmap13");
	this->lightsActive = glGetUniformLocation(shader.getProgramIndex(), "lightsActive");
	this->fogActive = glGetUniformLocation(shader.getProgramIndex(), "fogActive");

	printf("InfoLog for Hello World Shader\n%s\n\n",
			shader.getAllInfoLogs().c_str());

	return (shader.isProgramValid());
}

void Engine::lights(bool active) {
	if (active) {
		glUniform1i(this->lightsActive, 1);
	}
	else {
		glUniform1i(this->lightsActive, 0);
	}
}

void Engine::fog(bool active){
	if(active) {
		glUniform1i(this->fogActive, 1);
	}
	else {
		glUniform1i(this->fogActive, 0);
	}
}

