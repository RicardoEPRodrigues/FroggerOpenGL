/*
 * Entity.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#include "Entity.h"

#include <cstring>
#include <stdlib.h>

Entity::Entity() :
        _position() {

}

Entity::~Entity() {

}

Vector3* Entity::setPosition(double x, double y, double z) {
    Vector3* r = (Vector3*) malloc(sizeof(Vector3));
    this->_position.set(x, y, z);
    memcpy(r, &this->_position, sizeof(Vector3));
    return r;
}

Vector3* Entity::setPosition(const Vector3& p) {
    Vector3* r = (Vector3*) malloc(sizeof(Vector3));
    this->_position = p;
    memcpy(r, &this->_position, sizeof(Vector3));
    return r;
}

Vector3* Entity::getPosition() {
    Vector3* r = (Vector3*) malloc(sizeof(Vector3));
    memcpy(r, &this->_position, sizeof(Vector3));
    return r;
}
