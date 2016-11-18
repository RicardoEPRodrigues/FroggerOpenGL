/*
 * Roadside.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef ROADSIDE_H_
#define ROADSIDE_H_

#include "../../GraphicLib/GameObjects/StaticObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Roadside : public StaticObject, public ComposedObject {
    public:
        Roadside();

        virtual ~Roadside();
};

#endif /* ROADSIDE_H_ */
