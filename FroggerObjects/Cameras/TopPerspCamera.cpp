/*
 * TopPerspCamera.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: ricardo
 */

#include "TopPerspCamera.h"

TopPerspCamera::TopPerspCamera() :
		PerspectiveCamera(60.0f, 0.1f, 100.0f) {
	this->_position.set(0, 0, 70);
	this->_at.set(0, 0, 0);
	this->_up.set(0, 1, 0);
}

TopPerspCamera::~TopPerspCamera() {
}

