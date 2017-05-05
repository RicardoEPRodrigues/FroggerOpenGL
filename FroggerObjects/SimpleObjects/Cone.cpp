/*
 * Cone.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Cone.h"

Cone::Cone(MyMesh* mesh) :
        SimpleObject(mesh) {
}

Cone::~Cone() {
    free(this->mesh);
}

void Cone::init() {
    createCone(1.0f, 1.0f, 20, this->mesh);
}
