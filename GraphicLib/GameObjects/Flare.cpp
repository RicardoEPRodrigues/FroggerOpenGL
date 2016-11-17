/*
 * Flare.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: ricardo
 */

#include "Flare.h"

#include <cstring>

Flare::Flare() {
	this->fDistance = 0;
	this->fSize = 0;
}

Flare::~Flare() {
	// TODO Auto-generated destructor stub
}

void Flare::init() {
	createRectangleXY(this->mesh);
}

void Flare::update(double delta_t) {
}

void Flare::setRGBA(float r, float g, float b, float a) {
	float diff[] = { r, g, b, a };
	memcpy(mesh->mat.diffuse, diff, 4 * sizeof(float));
}

void Flare::setTexture(int textureId) {
	this->mesh->mat.texCount = textureId;
}
