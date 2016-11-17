/*
 * ObjectFactory.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: ricardo
 */

#include "ObjectFactory.h"

#include <cstring>

ObjectFactory::ObjectFactory() {

}

ObjectFactory::~ObjectFactory() {
}

Frog* ObjectFactory::getFrog() {
	Frog * frog = new Frog();

	frog->setPosition(0.0, -30.0, -2.0);
	frog->setResetPosition(0.0, -30.0, -2.0);
	frog->setAlive(true);

	return frog;
}

Car* ObjectFactory::getCar(float laneY) {
	Car * car = new Car();

	car->setPosition(-40.0f, laneY, -2.0f);
	car->setResetPosition(-40.0f, laneY, -2.0f);
	car->setSpeed(3, 0, 0);

	return car;
}

Bus* ObjectFactory::getBus(float laneY) {
	Bus * bus = new Bus();

	bus->setPosition(40.0f, laneY, -2.0f);
	bus->setResetPosition(40.0f, laneY, -2.0f);
	bus->setRotation(0.0f, 0.0f, 180.0f);
	bus->setSpeed(-2, 0, 0);

	return bus;
}

Timberlog* ObjectFactory::getTimberlog(float laneY) {
	Timberlog * timberlog = new Timberlog();

	timberlog->setPosition(-40.0f, laneY, -3.0f);
	timberlog->setResetPosition(-40.0f, laneY, -3.0f);
	timberlog->setSpeed(3, 0, 0);

	return timberlog;
}

Turtle* ObjectFactory::getTurtle(float laneY) {
	Turtle * turtle = new Turtle();

	turtle->setPosition(40.0f, laneY, -3.0f);
	turtle->setResetPosition(40.0f, laneY, -3.0f);
	turtle->setSpeed(-2, 0, 0);

	return turtle;
}

River* ObjectFactory::getRiver() {
	River * river = new River();

	float bg_scale = 4.0f;
	river->setPosition(0.0f, bg_scale * 2.5f + 2.5f, -2.0f);

	return river;
}

Riverside* ObjectFactory::getRiverside() {
	Riverside * riverside = new Riverside();

	float bg_scale = 5.0f;
	riverside->setPosition(0.0f, bg_scale * 6.0f, -2.0f);

	return riverside;
}

Road* ObjectFactory::getRoad() {
	Road * road = new Road();

	float bg_scale = 5.0f;
	road->setPosition(0.0f, bg_scale * 0.0f, -2.0f);

	return road;
}

Roadside* ObjectFactory::getRoadside() {
	Roadside * roadside = new Roadside();

	float bg_scale = 5.0f;
	roadside->setPosition(0.0f, -bg_scale * 6.0f, -2.0f);

	return roadside;
}

Roadside* ObjectFactory::getBetweenRoadside() {
	Roadside * roadside = new Roadside();

	roadside->setPosition(0.0f, 0.0f, -2.0f);

	return roadside;
}

GameObject * ObjectFactory::getBelowRiver() {
	GameObject * ground = new BelowRiver();

	float bg_scale = 4.0f;
	ground->setPosition(0.0f, bg_scale * 2.5f + 2.5f, -4.0f);

	return ground;
}

Cube* ObjectFactory::getBounderies() {
	MyMesh * mesh = new MyMesh();

	float amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float diff[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spec[] = { 2.0f, 0.2f, 2.0f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 100.0f;
	int texcount = 0;

	memcpy((*mesh).mat.ambient, amb, 4 * sizeof(float));
	memcpy((*mesh).mat.diffuse, diff, 4 * sizeof(float));
	memcpy((*mesh).mat.specular, spec, 4 * sizeof(float));
	memcpy((*mesh).mat.emissive, emissive, 4 * sizeof(float));
	(*mesh).mat.shininess = shininess;
	(*mesh).mat.texCount = texcount;

	Cube * bounderies = new Cube(mesh);

	bounderies->setScale(70, 100, 4);
	bounderies->setPosition(0.0, 0.0, 0.0);

	return bounderies;
}

Tree * ObjectFactory::getBillboard() {
	Tree * billboard = new Tree();

	return billboard;
}

Particle* ObjectFactory::getParticleNorth() {
	Particle * particle = new Particle();

	particle->setPosition(0.0f, 20.0f, 10.0f);

	return particle;
}

Particle* ObjectFactory::getParticleWest() {
	Particle * particle = new Particle();

	particle->setPosition(-30.0f, 0.0f, 10.0f);

	return particle;
}

Particle* ObjectFactory::getParticleSouth() {
	Particle * particle = new Particle();

	particle->setPosition(0.0f, -20.0f, 10.0f);

	return particle;
}

Particle* ObjectFactory::getParticleEast() {
	Particle * particle = new Particle();

	particle->setPosition(30.0f, 0.0f, 10.0f);

	return particle;
}
