/*
 * ResetableObject.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: ricardo
 */

#include "ResetableObject.h"

ResetableObject::ResetableObject() :
		DynamicObject() {
	this->setAlive(false);
	this->_resetTime = rand() % 10;
}

ResetableObject::~ResetableObject() {
}

void ResetableObject::resetPosition() {
	this->setPosition(this->_resetPosition);
}

void ResetableObject::die() {
	this->resetPosition();
	this->setAlive(false);
	this->_resetTime = rand() % 10;
}

void ResetableObject::respawn() {
	this->resetPosition();
	this->setAlive(true);
}

void ResetableObject::updateResetTime() {
	this->_resetTime--;
}
