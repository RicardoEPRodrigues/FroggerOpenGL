/*
 * Turtle.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Turtle.h"

#include "../SimpleObjects/Sphere.h"

Turtle::Turtle() :
        HitableObject(Vector3(-2, -1, -1), Vector3(2, 1, 1)) {
    MyMesh* mesh = new MyMesh();
    MyMesh* mesh1 = new MyMesh();

    float amb[] = {0.0f, 0.1f, 0.1f, 1.0f};
    float diff[] = {0.0f, 0.8f, 0.0f, 1.0f};
    float spec[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess = 100.0f;
    int texcount = 7;

    memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess;
    (*mesh).mat.texCount = texcount;

    Sphere* s = new Sphere(mesh);
    s->setScale(6.0f, 5.0f, 3.0f);

    this->addElement(s);

    float amb1[] = {0.0f, 0.1f, 0.1f, 1.0f};
    float diff1[] = {0.0f, 0.8f, 0.0f, 1.0f};
    float spec1[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float emissive1[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess1 = 100.0f;
    int texcount1 = 13;

    memcpy((*mesh1).mat.ambient, amb1, 4 * sizeof(float));
    memcpy((*mesh1).mat.diffuse, diff1, 4 * sizeof(float));
    memcpy((*mesh1).mat.specular, spec1, 4 * sizeof(float));
    memcpy((*mesh1).mat.emissive, emissive1, 4 * sizeof(float));
    (*mesh1).mat.shininess = shininess1;
    (*mesh1).mat.texCount = texcount1;

    Sphere* s1 = new Sphere(mesh1);
    s1->setPosition(-3.0f, 0.0f, 0.0f);
    s1->setScale(3.0f, 2.5f, 1.5f);

    this->addElement(s1);

}

Turtle::~Turtle() {

}

