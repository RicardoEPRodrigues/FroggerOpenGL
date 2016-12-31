/*
 * Vector4.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "Vector4.h"

Vector4::Vector4() {
    this->_w = 0.0;
}

Vector4::Vector4(double x, double y, double z, double w)
        : Vector3(x, y, z) {
    this->_w = w;
}

Vector4::~Vector4() {
}

double Vector4::getW() {
    return this->_w;
}

void Vector4::set(double x, double y, double z, double w) {
    Vector3::set(x, y, z);
    this->_w = w;
}

Vector4 Vector4::operator=(const Vector4& vec) {
    if (this != &vec) {
        this->_x = vec._x;
        this->_y = vec._y;
        this->_z = vec._z;
        this->_w = vec._w;
    }
    return *this;
}

Vector4 Vector4::operator*(double num) {
    Vector4 res;

    res._x = this->_x * num;
    res._y = this->_y * num;
    res._z = this->_z * num;
    res._w = this->_w * num;

    return res;
}

Vector4 Vector4::operator+(const Vector4& vec) {
    Vector4 res;

    res._x = this->_x + vec._x;
    res._y = this->_y + vec._y;
    res._z = this->_z + vec._z;
    res._w = this->_w + vec._w;

    return res;
}

Vector4 Vector4::operator-(const Vector4& vec) {
    Vector4 res;

    res._x = this->_x - vec._x;
    res._y = this->_y - vec._y;
    res._z = this->_z - vec._z;
    res._w = this->_w - vec._w;

    return res;
}
