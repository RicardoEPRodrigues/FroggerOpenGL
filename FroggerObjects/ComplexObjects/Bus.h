/*
 * Bus.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef BUS_H_
#define BUS_H_

#include "../Utilities/ResetableObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Bus : public HitableObject, public ResetableObject, public ComposedObject {
public:
	Bus();
	virtual ~Bus();
};

#endif /* BUS_H_ */
