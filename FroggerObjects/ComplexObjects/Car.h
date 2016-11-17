/*
 * Car.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef CAR_H_
#define CAR_H_

#include "../Utilities/ResetableObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Car : public HitableObject, public ResetableObject, public ComposedObject {
public:
	Car();
	virtual ~Car();
};

#endif /* CAR_H_ */
