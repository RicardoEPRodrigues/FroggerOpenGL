/*
 * Cube.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Cube: public SimpleObject, public StaticObject  {
public:
	Cube(MyMesh* mesh);
	virtual ~Cube();
	void init();
};

#endif /* Cube_H_ */
