/*
 * PerspectiveCamera.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(double fovy, double zNear,
		double zFar) : Camera(zNear, zFar) {
	this->_fovy = fovy;
}

PerspectiveCamera::~PerspectiveCamera() {
}

void PerspectiveCamera::update(float camX, float camY, float camZ) {
}

void PerspectiveCamera::computeProjectionMatrix(Engine * engine, float ratio) {
	engine->matrixModule->loadIdentity(PROJECTION);
	engine->matrixModule->perspective(this->_fovy, ratio, this->_near, this->_far);
}
