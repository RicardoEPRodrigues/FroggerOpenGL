/*
 * Riverside.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#include "Riverside.h"

#include "../SimpleObjects/Sphere.h"
#include "../SimpleObjects/Cube.h"
#include "../SimpleObjects/Cylinder.h"
#include "../SimpleObjects/Torus.h"

#include <cstring>

Riverside::Riverside() : StaticObject(){
	MyMesh * mesh = new MyMesh();

	float bg_scale = 5.0f;
	float bg_wide = 95.0f;


	float amb[] = { 0.0f, 0.1f, 0.0f, 1.0f };
	float diff[] = { 0.0f, 0.3f, 0.0f, 1.0f };
	float spec[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 50.0f;
	int texcount = 6;

	memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
	memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
	memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
	memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
	(*mesh).mat.shininess = shininess;
	(*mesh).mat.texCount = texcount;

	Cube *c = new Cube(mesh);
	c->setScale(bg_wide*1.0f, bg_scale*3.0f, 1.0f);
	c->setPosition(0.0f, 0.0f, -2.0f);

	this->addElement(c);
	
}

Riverside::~Riverside() {

}


