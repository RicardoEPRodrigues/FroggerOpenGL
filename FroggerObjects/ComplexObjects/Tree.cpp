/*
 * Billboard.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: ricardo
 */

#include "Tree.h"

#include <cstring>

Tree::Tree() {
	MyMesh * mesh = new MyMesh();

//	float amb[] = { 1.0f, 0.1f, 0.1f, 1.0f };
	float diff[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	float spec[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 100.0f;
//	int texcount3 = 0;
	int texcount = 5;

	memcpy((*mesh).mat.ambient, diff, 4 * sizeof(float));
	memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
	memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
	memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
	(*mesh).mat.shininess = shininess;
	(*mesh).mat.texCount = texcount;

	this->setMesh(mesh);
	this->setScale(1.5f, 1.5f, 1.5f);
//	this->setRotation(90,0,0);

}

Tree::~Tree() {
}

