/*
 * ObjectFactory.h
 *
 *  Created on: Oct 29, 2014
 *      Author: ricardo
 */

#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_

#include "../SimpleObjects/Cube.h"
#include "../ComplexObjects/Frog.h"
#include "../ComplexObjects/Car.h"
#include "../ComplexObjects/Bus.h"
#include "../ComplexObjects/Timberlog.h"
#include "../ComplexObjects/Turtle.h"
#include "../ComplexObjects/River.h"
#include "../ComplexObjects/Riverside.h"
#include "../ComplexObjects/Road.h"
#include "../ComplexObjects/Roadside.h"
#include "../ComplexObjects/BelowRiver.h"
#include "../ComplexObjects/Tree.h"
#include "../ComplexObjects/Particle.h"

class ObjectFactory {
public:
	ObjectFactory();
	virtual ~ObjectFactory();

	Cube* getBounderies();
	Frog* getFrog();

	Car * getCar(float laneY);
	Bus * getBus(float laneY);
	Timberlog * getTimberlog(float laneY);
	Turtle * getTurtle(float laneY);

	River * getRiver();
	Riverside * getRiverside();
	Road * getRoad();
	Roadside * getRoadside();
	GameObject * getBelowRiver();
	Roadside * getBetweenRoadside();
	Tree * getBillboard();
	Particle * getParticleNorth();
	Particle * getParticleSouth();
	Particle * getParticleEast();
	Particle * getParticleWest();

};

#endif /* OBJECTFACTORY_H_ */
