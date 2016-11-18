/*
 * DynamicObject.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#include "DynamicObject.h"

DynamicObject::DynamicObject() :
        GameObject(), _speed() {

}

DynamicObject::~DynamicObject() {

}

void DynamicObject::update(double delta_t) {
    int x = this->_speed.getX();
    int y = this->_speed.getY();
    int z = this->_speed.getZ();

    if (x > 0) {
        x += delta_t;
    } else {
        if (x < 0) {
            x -= delta_t;
        }
    }

    if (y > 0) {
        y += delta_t;
    } else {
        if (y < 0) {
            y -= delta_t;
        }
    }

    if (z > 0) {
        z += delta_t;
    } else {
        if (z < 0) {
            z -= delta_t;
        }
    }

    this->addPos(x, y, z);
}

void DynamicObject::setSpeed(const Vector3& speed) {
    this->_speed = speed;
}

void DynamicObject::setSpeed(double x, double y, double z) {
    this->_speed.set(x, y, z);
}

Vector3 DynamicObject::getSpeed() {
    return this->_speed;
}
