/*
 * Car.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Car.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Torus.h"

Car::Car() :
        HitableObject(Vector3(-4, -1.5, -0.5), Vector3(3.0, 1.5, 0.8)) {

    MyMesh* mesh = new MyMesh();
    MyMesh* mesh2 = new MyMesh();

    float amb[] = {0.0f, 0.0f, 0.1f, 1.0f};
    float diff[] = {0.0f, 0.0f, 0.8f, 1.0f};
    float spec[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess = 100.0f;
    int texcount = 0;

    memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess;
    (*mesh).mat.texCount = texcount;

    Sphere* s1 = new Sphere(mesh);
    s1->setScale(4.0f, 4.0f, 2.0f);
    s1->setPosition(1.5f, 0.0f, 0.8f);

    this->addElement(s1);

    Sphere* s2 = new Sphere(mesh);
    s2->setScale(4.0f, 4.0f, 2.0f);
    s2->setPosition(-1.5f, 0.0f, 0.8f);

    this->addElement(s2);

    float amb2[] = {0.1f, 0.0f, 0.0f, 1.0f};
    float diff2[] = {0.5f, 0.0f, 0.0f, 1.0f};
    float spec2[] = {0.7f, 0.7f, 0.7f, 1.0f};
    float emissive2[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess2 = 100.0f;
    float texcount2 = 0;

    memcpy((*mesh2).mat.ambient, amb2, 4 * sizeof(float));
    memcpy((*mesh2).mat.diffuse, diff2, 4 * sizeof(float));
    memcpy((*mesh2).mat.specular, spec2, 4 * sizeof(float));
    memcpy((*mesh2).mat.emissive, emissive2, 4 * sizeof(float));
    (*mesh2).mat.shininess = shininess2;
    (*mesh2).mat.texCount = texcount2;

    Torus* t = new Torus(mesh2);
    t->setPosition(-2.0f, -1.5f, -0.5f);

    this->addElement(t);

    Torus* t1 = new Torus(mesh2);
    t1->setPosition(2.0f, -1.5f, -0.5f);

    this->addElement(t1);

    Torus* t2 = new Torus(mesh2);
    t2->setPosition(-2.0f, 1.5f, -0.5f);

    this->addElement(t2);

    Torus* t3 = new Torus(mesh2);
    t3->setPosition(2.0f, 1.5f, -0.5f);

    this->addElement(t3);
}

Car::~Car() {

}
