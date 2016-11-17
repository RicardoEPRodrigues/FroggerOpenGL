/*
 * Road.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef ROAD_H_
#define ROAD_H_

#include "../../GraphicLib/GameObjects/StaticObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Road : public StaticObject, public ComposedObject {
public:
	Road();
	virtual ~Road();
};

#endif /* ROAD_H_ */
