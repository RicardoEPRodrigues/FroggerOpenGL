/*
 * Torus.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef TORUS_H_
#define TORUS_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Torus: public SimpleObject, public StaticObject  {
public:
	Torus(MyMesh* mesh);
	virtual ~Torus();
	void init();
};

#endif /* TORUS_H_ */
