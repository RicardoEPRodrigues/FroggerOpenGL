/*
 * MovementEngine.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#include "MovementEngine.h"

MovementEngine::MovementEngine(std::list<ResetableObject *> * resetables,
		float xMin, float xMax, float yMin, float yMax, float zMin,
		float zMax) {
	this->_resetables = resetables;

	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
	this->zMin = zMin;
	this->zMax = zMax;
}

MovementEngine::~MovementEngine() {
	// TODO Auto-generated destructor stub
}

void MovementEngine::update(double delta) {
	std::list<ResetableObject*>::iterator iterator;
	for (iterator = this->_resetables->begin();
			iterator != this->_resetables->end(); iterator++) {
		if ((*iterator)->isAlive()) {
			bool isXValid = (*iterator)->getPosition()->getX() < this->xMax
					&& (*iterator)->getPosition()->getX() > this->xMin;
			bool isYValid = (*iterator)->getPosition()->getY() < this->yMax
					&& (*iterator)->getPosition()->getY() > this->yMin;
			bool isZValid = (*iterator)->getPosition()->getZ() < this->zMax
					&& (*iterator)->getPosition()->getZ() > this->zMin;
			if (!isXValid || !isYValid || !isZValid) {
				(*iterator)->die();
			}
			else {
				(*iterator)->update(delta);
			}
		}
	}
}

void MovementEngine::reset() {
	std::list<ResetableObject*>::iterator iterator;
	for (iterator = this->_resetables->begin();
			iterator != this->_resetables->end(); iterator++) {
		if (!(*iterator)->isAlive()) {
			if ((*iterator)->getResetTime() == 0) {
				(*iterator)->respawn();
			} else {
				(*iterator)->updateResetTime();
			}
		}
	}
}
