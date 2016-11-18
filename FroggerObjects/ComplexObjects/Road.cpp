/*
 * Road.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Road.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cube.h"

#include <cstring>

Road::Road() : StaticObject() {
    MyMesh* mesh = new MyMesh();

    float bg_scale = 5.0f;
    float bg_wide = 95.0f;

    float amb2[] = {0.1f, 0.1f, 0.1f, 1.0f};
    float diff2[] = {0.3f, 0.3f, 0.3f, 1.0f};
    float spec2[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float emissive2[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess2 = 100.0f;
    int texcount2 = 3;
    //int texcount2 = 0;

    memcpy((*mesh).mat.ambient, amb2, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff2, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec2, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive2, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess2;
    (*mesh).mat.texCount = texcount2;

    Cube* c = new Cube(mesh);
    c->setScale(bg_wide * 1.0f, bg_scale * 5.0f, 1.0f);
    c->setPosition(0.0f, bg_scale * -3.0f, -2.0f);

    this->addElement(c);

}

Road::~Road() {

}


