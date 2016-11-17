/*
 * Frog.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Frog.h"

#include <cstring>
#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cube.h"

Frog::Frog() :
		HitableObject(Vector3(-2.0, -1.5, -1.0), Vector3(2.0, 1.5, 1.0)) {
	MyMesh * mesh = new MyMesh();
	MyMesh * mesh2 = new MyMesh();
	MyMesh * mesh3 = new MyMesh();
	MyMesh * mesh4 = new MyMesh();

	float amb[] = { 0.0f, 0.1f, 0.0f, 1.0f };
	float diff[] = { 0.0f, 0.5f, 0.0f, 1.0f };
	float spec[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 50.0f;
	int texcount = 0;

	memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
	memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
	memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
	memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
	(*mesh).mat.shininess = shininess;
	(*mesh).mat.texCount = texcount;

	Sphere *s = new Sphere(mesh);
	s->setScale(4.0f, 3.0f, 3.0f);

	this->addElement(s);

	memcpy((*mesh2).mat.ambient, amb, 4 * sizeof(float));
	memcpy((*mesh2).mat.diffuse, diff, 4 * sizeof(float));
	memcpy((*mesh2).mat.specular, spec, 4 * sizeof(float));
	memcpy((*mesh2).mat.emissive, emissive, 4 * sizeof(float));
	(*mesh2).mat.shininess = shininess;
	(*mesh2).mat.texCount = texcount;

	Cube *c = new Cube(mesh2);
	c->setScale(1.0f, 2.0f, 1.0f);
	c->setPosition(-2.0f, -1.5f, 0.0f);

	this->addElement(c);

	Cube *c2 = new Cube(mesh2);
	c2->setScale(1.0f, 2.0f, 1.0f);
	c2->setPosition(2.0f, -1.5f, 0.0f);

	this->addElement(c2);

	Cube *c3 = new Cube(mesh2);
	c3->setScale(1.0f, 2.0f, 1.0f);
	c3->setPosition(-2.0f, 1.5f, 0.0f);

	this->addElement(c3);

	Cube *c4 = new Cube(mesh2);
	c4->setScale(1.0f, 2.0f, 1.0f);
	c4->setPosition(2.0f, 1.5f, 0.0f);

	this->addElement(c4);

	float amb3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float spec3[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float emissive3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess3 = 100.0f;
	int texcount3 = 0;

	memcpy((*mesh3).mat.ambient, amb3, 4 * sizeof(float));
	memcpy((*mesh3).mat.diffuse, diff3, 4 * sizeof(float));
	memcpy((*mesh3).mat.specular, spec3, 4 * sizeof(float));
	memcpy((*mesh3).mat.emissive, emissive3, 4 * sizeof(float));
	(*mesh3).mat.shininess = shininess3;
	(*mesh3).mat.texCount = texcount3;

	Sphere *s2 = new Sphere(mesh3);
	s2->setScale(0.5f, 0.5f, 0.5f);
	s2->setPosition(1.0f, 1.5f, 1.0f);

	this->addElement(s2);

	Sphere *s3 = new Sphere(mesh3);
	s3->setScale(0.5f, 0.5f, 0.5f);
	s3->setPosition(-1.0f, 1.5f, 1.0f);

	this->addElement(s3);

	float amb4[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float diff4[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spec4[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float emissive4[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess4 = 100.0f;
	int texcount4 = 0;

	memcpy((*mesh4).mat.ambient, amb4, 4 * sizeof(float));
	memcpy((*mesh4).mat.diffuse, diff4, 4 * sizeof(float));
	memcpy((*mesh4).mat.specular, spec4, 4 * sizeof(float));
	memcpy((*mesh4).mat.emissive, emissive4, 4 * sizeof(float));
	(*mesh4).mat.shininess = shininess4;
	(*mesh4).mat.texCount = texcount4;

	Sphere *s4 = new Sphere(mesh4);
	s4->setScale(1.0f, 1.0f, 1.0f);
	s4->setPosition(1.0f, 1.0f, 1.0f);

	this->addElement(s4);

	Sphere *s5 = new Sphere(mesh4);
	s5->setScale(1.0f, 1.0f, 1.0f);
	s5->setPosition(-1.0f, 1.0f, 1.0f);

	this->addElement(s5);
}

Frog::~Frog() {

}

void Frog::Up() {
	this->setRotation(0, 0, 0);
	this->addPos(0.0f, 5.0f, 0.0f);
}

void Frog::Down() {
	this->setRotation(0, 0, 180);
	this->addPos(0.0f, -5.0f, 0.0f);
}

void Frog::Left() {
	this->setRotation(0, 0, 90);
	this->addPos(-5.0f, 0.0f, 0.0f);
}

void Frog::Right() {
	this->setRotation(0, 0, -90);
	this->addPos(5.0f, 0.0f, 0.0f);
}

