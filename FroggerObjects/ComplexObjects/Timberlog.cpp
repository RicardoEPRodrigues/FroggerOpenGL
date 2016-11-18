/*
 * Timberlog.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Timberlog.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cylinder.h"

#include <cstring>

Timberlog::Timberlog() :
        HitableObject(Vector3(-2, -1, -1), Vector3(2, 1, 1)) {
    MyMesh* mesh = new MyMesh();

    float amb[] = {0.2f, 0.1f, 0.1f, 1.0f};
    float diff[] = {0.5f, 0.2f, 0.2f, 1.0f};
    float spec[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess = 100.0f;
    int texcount = 1;

    memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess;
    (*mesh).mat.texCount = texcount;

    Cylinder* c = new Cylinder(mesh);
    c->setScale(5.0f, 6.0f, 3.0f);
    c->setRotation(0.0f, 0.0f, 90.0f);

    this->addElement(c);

}

Timberlog::~Timberlog() {

}

