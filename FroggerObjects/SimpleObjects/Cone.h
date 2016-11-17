/*
 * Sphere.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef CONE_H_
#define CONE_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Cone: public SimpleObject, public StaticObject {
public:
	Cone(MyMesh* mesh);
	virtual ~Cone();
	void init();
};

#endif /* CONE_H_ */
