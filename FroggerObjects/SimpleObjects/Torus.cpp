/*
 * Torus.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Torus.h"

Torus::Torus(MyMesh* mesh) :
        SimpleObject(mesh) {
}

Torus::~Torus() {
    free(this->mesh);
}

void Torus::init() {
    createTorus(0.5f, 1.0f, 10, 20, this->mesh);
}
