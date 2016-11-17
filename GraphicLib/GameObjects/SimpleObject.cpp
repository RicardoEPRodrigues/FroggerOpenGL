/*
 * SimpleElement.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "SimpleObject.h"

#include <cstring>

SimpleObject::SimpleObject() {
	this->mesh = new MyMesh();
	float amb2[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	float diff2[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec2[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	float emissive2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess2 = 100.0f;
	int texcount2 = 0;

	memcpy((*mesh).mat.ambient, amb2, 4 * sizeof(float));
	memcpy((*mesh).mat.diffuse, diff2, 4 * sizeof(float));
	memcpy((*mesh).mat.specular, spec2, 4 * sizeof(float));
	memcpy((*mesh).mat.emissive, emissive2, 4 * sizeof(float));
	(*mesh).mat.shininess = shininess2;
	(*mesh).mat.texCount = texcount2;

}

SimpleObject::SimpleObject(MyMesh * mesh) {
	this->mesh = mesh;
}

SimpleObject::~SimpleObject() {
	free(this->mesh);
}

void SimpleObject::drawInside(Engine engine) {
	AVTMatrixModule *module = engine.matrixModule;
	GLint loc;
	module->pushMatrix(MODEL);

	// send the material
	loc = glGetUniformLocation(engine.shader.getProgramIndex(), "mat.ambient");
	glUniform4fv(loc, 1, this->mesh->mat.ambient);
	loc = glGetUniformLocation(engine.shader.getProgramIndex(), "mat.diffuse");
	glUniform4fv(loc, 1, this->mesh->mat.diffuse);
	loc = glGetUniformLocation(engine.shader.getProgramIndex(), "mat.specular");
	glUniform4fv(loc, 1, this->mesh->mat.specular);
	loc = glGetUniformLocation(engine.shader.getProgramIndex(),
			"mat.shininess");
	glUniform1f(loc, this->mesh->mat.shininess);
	loc = glGetUniformLocation(engine.shader.getProgramIndex(), "mat.emissive");
	glUniform4fv(loc, 1, this->mesh->mat.emissive);
	loc = glGetUniformLocation(engine.shader.getProgramIndex(), "mat.texCount");
	glUniform1f(loc, this->mesh->mat.texCount);

	// send matrices to OGL
	engine.recomputeMatrices();
	glUniform1i(engine.texMode_uniformId, this->mesh->mat.texCount);
	glBindVertexArray(this->mesh->vao);
	glDrawElements(this->mesh->type, this->mesh->numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	module->popMatrix(MODEL);
}
