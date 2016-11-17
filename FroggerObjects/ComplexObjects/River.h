/*
 * River.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef RIVER_H_
#define RIVER_H_

#include "../../GraphicLib/GameObjects/StaticObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class River : public HitableObject, public StaticObject, public ComposedObject {
public:
	River();
	virtual ~River();
};

#endif /* RIVER_H_ */
