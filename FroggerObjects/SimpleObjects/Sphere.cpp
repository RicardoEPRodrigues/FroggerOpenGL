/*
 * Sphere.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#include "Sphere.h"

Sphere::Sphere(MyMesh* mesh) :
        SimpleObject(mesh) {
}

Sphere::~Sphere() {
    free(this->mesh);
}

void Sphere::init() {
    createSphere(0.5f, 20, this->mesh);
}
