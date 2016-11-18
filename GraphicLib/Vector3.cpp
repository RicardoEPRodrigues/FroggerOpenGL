/*
 * Vector3.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#include "Vector3.h"

Vector3::Vector3() {
    this->_x = 0.0;
    this->_y = 0.0;
    this->_z = 0.0;
}

Vector3::Vector3(double x, double y, double z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Vector3::~Vector3() {

}

double Vector3::getX() {
    return this->_x;
}

double Vector3::getY() {
    return this->_y;
}

double Vector3::getZ() {
    return this->_z;
}

void Vector3::set(double x, double y, double z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Vector3 Vector3::operator=(const Vector3& vec) {
    if (this != &vec) {
        (*this)._x = vec._x;
        (*this)._y = vec._y;
        (*this)._z = vec._z;
    }
    return *this;
}

Vector3 Vector3::operator*(double num) {
    Vector3 res;

    res._x = this->_x * num;
    res._y = this->_y * num;
    res._z = this->_z * num;

    return res;
}

Vector3 Vector3::operator+(const Vector3& vec) {
    Vector3 res;

    res._x = this->_x + vec._x;
    res._y = this->_y + vec._y;
    res._z = this->_z + vec._z;

    return res;
}

Vector3 Vector3::operator-(const Vector3& vec) {
    Vector3 res;

    res._x = this->_x - vec._x;
    res._y = this->_y - vec._y;
    res._z = this->_z - vec._z;

    return res;
}
