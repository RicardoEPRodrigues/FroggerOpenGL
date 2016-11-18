/*
 * TopOrthoCamera.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: ricardo
 */

#include "TopOrthoCamera.h"

TopOrthoCamera::TopOrthoCamera() :
        OrthogonalCamera(-40, 40, -35, 35, 5, 50) {
    this->_position.set(0, 0, 40);
    this->_at.set(0, 0, 0);
    this->_up.set(0, 1, 0);
}

TopOrthoCamera::~TopOrthoCamera() {
}

