/*
 * Cube.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Cube.h"

Cube::Cube(MyMesh* mesh) :
		SimpleObject(mesh) {
}

Cube::~Cube() {
	free(this->mesh);
}

void Cube::init() {
	createCube(1.0f, this->mesh);
}
