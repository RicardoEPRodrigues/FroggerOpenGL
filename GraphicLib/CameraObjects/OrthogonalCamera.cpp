/*
 * OrthogonalCamera.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom,
                                   double top, double znear, double zfar) : Camera(znear, zfar) {
    this->_left = left;
    this->_right = right;
    this->_bottom = bottom;
    this->_top = top;
}

OrthogonalCamera::~OrthogonalCamera() {
}

void OrthogonalCamera::update(float camX, float camY, float camZ) {
}

void OrthogonalCamera::computeProjectionMatrix(Engine* engine, float ratio) {
    engine->matrixModule->loadIdentity(PROJECTION);
    engine->matrixModule->ortho(_left, _right, _bottom, _top, _near, _far);
}
