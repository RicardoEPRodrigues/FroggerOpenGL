/*
 * Camera.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "Camera.h"

Camera::Camera(double znear, double zfar) {
	this->_near = znear;
	this->_far = zfar;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::computeVisualizationMatrix(Engine * engine) {
	engine->matrixModule->loadIdentity(VIEW);
	engine->matrixModule->lookAt(
			this->_position.getX(), this->_position.getY(), this->_position.getZ(),
			this->_at.getX(), this->_at.getY(), this->_at.getZ(),
			this->_up.getX(), this->_up.getY(), this->_up.getZ());
}
