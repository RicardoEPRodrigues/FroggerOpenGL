/*
 * Nightlight.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#include "Nightlight.h"

Nightlight::Nightlight(float x, float y) {
    Vector4 position(x, y, 3.0f, 1.0f);
    Vector3 direction(0.0f, 0.0f, -1.0f);
    Vector4 ambient(0.1f, 0.1f, 0.1f, 1.0f);
    Vector4 diffuse(0.8f, 0.8f, 0.8f, 1.0f);
    Vector4 specular(0.7f, 0.7f, 0.7f, 1.0f);
    this->setPosition(position);
    this->setDirection(direction);
    this->setAmbient(ambient);
    this->setDiffuse(diffuse);
    this->setSpecular(specular);
    this->setCutOff(0.3f);
    this->setIsSpot(false);
    this->setAtt(1.0f, 1.0f, 1.0f);
    this->setExponent(1.0f);
    this->setState(true);
}

Nightlight::~Nightlight() {
    // TODO Auto-generated destructor stub
}

void Nightlight::update() {

}
