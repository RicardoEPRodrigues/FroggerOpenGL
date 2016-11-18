/*
 * River.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "River.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cube.h"

#include <cstring>

River::River() :
        HitableObject(Vector3(-45, -10, -2), Vector3(45, 10, 1)) {
    MyMesh* mesh = new MyMesh();

    float bg_scale = 4.0f;
    float bg_wide = 95.0f;

    float amb3[] = {0.0f, 0.0f, 0.2f, 1.0f};
    float diff3[] = {0.0f, 0.0f, 0.5f, 0.5f};
    float spec3[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float emissive3[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess3 = 100.0f;
    int texcount3 = 2;

    memcpy((*mesh).mat.ambient, amb3, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff3, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec3, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive3, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess3;
    (*mesh).mat.texCount = texcount3;

    Cube* c = new Cube(mesh);
    c->setScale(bg_wide * 1.0f, bg_scale * 5.0f, 1.0f);
    c->setPosition(0.0f, 0.0f, -2.0f);

    this->addElement(c);
}

River::~River() {

}

