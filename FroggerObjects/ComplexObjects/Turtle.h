/*
 * Turtle.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef TURTLE_H_
#define TURTLE_H_

#include "../Utilities/ResetableObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Turtle : public HitableObject, public ResetableObject, public ComposedObject {
public:
	Turtle();
	virtual ~Turtle();
};

#endif /* TURTLE_H_ */
