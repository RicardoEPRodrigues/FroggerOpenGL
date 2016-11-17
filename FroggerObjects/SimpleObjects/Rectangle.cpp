/*
 * Cube.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Rectangle.h"

Rectangle::Rectangle(MyMesh* mesh) :
		SimpleObject(mesh) {
	this->size = size;
}

Rectangle::~Rectangle() {
	free(this->mesh);
}

void Rectangle::init() {
	createRectangle(this->mesh);
}
