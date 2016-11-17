/*
 * ComposedElement.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "ComposedObject.h"

void ComposedObject::localInit() {
	elems = new std::list<GameObject*>();
}

ComposedObject::ComposedObject() {
	localInit();
}

ComposedObject::~ComposedObject() {
	std::list<GameObject *>::iterator it;
	for (it = this->elems->begin(); it != this->elems->end(); it++) {
		free((*it));
	}
	free(this->elems);
}

void ComposedObject::addElement(GameObject *element) {
	this->elems->push_back(element);
}

void ComposedObject::init() {
	std::list<GameObject *>::iterator it;
	for (it = this->elems->begin(); it != this->elems->end(); it++) {
		(*it)->init();
	}
}

void ComposedObject::drawInside(Engine engine) {
	std::list<GameObject *>::iterator it;
	for (it = this->elems->begin(); it != this->elems->end(); it++) {
		(*it)->draw(engine);
	}
}
