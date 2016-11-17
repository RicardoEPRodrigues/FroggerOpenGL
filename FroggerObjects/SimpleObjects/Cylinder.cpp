/*
 * Sphere.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Cylinder.h"

Cylinder::Cylinder(MyMesh* mesh) :
		SimpleObject(mesh) {
}

Cylinder::~Cylinder() {
	free(this->mesh);
}

void Cylinder::init() {
	createCylinder(1.0f, 0.5f, 20, this->mesh);
}
