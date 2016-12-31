/*
 * Bus.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Bus.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cube.h"
#include "../SimpleObjects/Cylinder.h"
#include "../SimpleObjects/Torus.h"

Bus::Bus() :
        HitableObject(Vector3(-12.0, -1.5, -0.5), Vector3(2, 1.5, 0.8)) {
    MyMesh* mesh = new MyMesh();
    MyMesh* mesh2 = new MyMesh();
    MyMesh* mesh3 = new MyMesh();

    float amb[] = {0.0f, 0.0f, 0.1f, 1.0f};
    float diff[] = {0.0f, 0.0f, 0.5f, 1.0f};
    float spec[] = {0.3f, 0.3f, 0.3f, 1.0f};
    float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess = 100.0f;
    int texcount = 0;

    memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
    memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
    memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
    memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
    (*mesh).mat.shininess = shininess;
    (*mesh).mat.texCount = texcount;

    Cube* c1 = new Cube(mesh);
    c1->setScale(4.0f, 8.0f, 2.0f);
    c1->setRotation(0.0f, 0.0f, 90.0f);
    c1->setPosition(1.5f, 0.0f, 0.8f);

    this->addElement(c1);

    Cube* c2 = new Cube(mesh);
    c2->setScale(4.0f, 4.0f, 2.0f);
    c2->setPosition(9.0f, 0.0f, 0.8f);

    this->addElement(c2);

    float amb3[] = {0.1f, 0.1f, 0.1f, 1.0f};
    float diff3[] = {0.5f, 0.5f, 0.5f, 1.0f};
    float spec3[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float emissive3[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float shininess3 = 100.0f;
    int texcount3 = 0;

    memcpy((*mesh3).mat.ambient, amb3, 4 * sizeof(float));
    memcpy((*mesh3).mat.diffuse, diff3, 4 * sizeof(float));
    memcpy((*mesh3).mat.specular, spec3, 4 * sizeof(float));
    memcpy((*mesh3).mat.emissive, emissive3, 4 * sizeof(float));
    (*mesh3).mat.shininess = shininess3;
    (*mesh3).mat.texCount = texcount3;

    Cylinder* cl1 = new Cylinder(mesh3);
    cl1->setScale(1.0f, 2.0f, 2.0f);
    cl1->setRotation(0.0f, 0.0f, 90.0f);
    cl1->setPosition(6.0f, 0.5f, 0.8f);

    this->addElement(cl1);

    Cylinder* cl2 = new Cylinder(mesh3);
    cl2->setScale(1.0f, 2.0f, 2.0f);
    cl2->setRotation(0.0f, 0.0f, 90.0f);
    cl2->setPosition(6.0f, -1.0f, 0.8f);

    this->addElement(cl2);

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
    t1->setPosition(11.0f, -1.5f, -0.5f);

    this->addElement(t1);

    Torus* t2 = new Torus(mesh2);
    t2->setPosition(-2.0f, 1.5f, -0.5f);

    this->addElement(t2);

    Torus* t3 = new Torus(mesh2);
    t3->setPosition(11.0f, 1.5f, -0.5f);

    this->addElement(t3);
}

Bus::~Bus() {

}

