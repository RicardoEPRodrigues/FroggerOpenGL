/*
 * River.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef BELOWRIVER_H_
#define BELOWRIVER_H_

#include "../../GraphicLib/GameObjects/StaticObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class BelowRiver : public StaticObject, public ComposedObject {
    public:
        BelowRiver();

        virtual ~BelowRiver();
};

#endif /* BELOWRIVER_H_ */
