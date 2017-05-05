/*
 * Daylight.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#include "Daylight.h"

Daylight::Daylight() {
//	Vector4 position(4.0f, 6.0f, 2.0f, 1.0f);
    Vector4 position(0.0f, 0.0f, 10.0f, 0.0f);
    Vector3 direction(0.0f, 0.0f, -1.0f);
    Vector4 ambient(0.3f, 0.3f, 0.3f, 1.0f);
    Vector4 diffuse(0.7f, 0.7f, 0.7f, 1.0f);
    Vector4 specular(1.0f, 1.0f, 1.0f, 1.0f);
    this->setPosition(position);
    this->setDirection(direction);
    this->setAmbient(ambient);
    this->setDiffuse(diffuse);
    this->setSpecular(specular);
    this->setCutOff(0.9);
    this->setIsSpot(false);
    this->setAtt(0.2f, 0.2f, 0.2f);
    this->setExponent(1.0f);
    //this->setState(true);

}

Daylight::~Daylight() {
}

void Daylight::update() {

}
