/*
 * Nightlight.h
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#ifndef NIGHTLIGHT_H_
#define NIGHTLIGHT_H_

#include "../../GraphicLib/LightObjects/LightSource.h"

class Nightlight : public LightSource {
    public:
        Nightlight(float x, float y);

        virtual ~Nightlight();

        virtual void update();
};

#endif /* NIGHTLIGHT_H_ */
