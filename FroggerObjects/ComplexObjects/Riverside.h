/*
 * Riverside.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef RIVERSIDE_H_
#define RIVERSIDE_H_

#include "../../GraphicLib/GameObjects/StaticObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Riverside : public StaticObject, public ComposedObject {
public:
	Riverside();
	virtual ~Riverside();
};

#endif /* RIVERSIDE_H_ */
