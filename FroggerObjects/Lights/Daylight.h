/*
 * Daylight.h
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#ifndef DAYLIGHT_H_
#define DAYLIGHT_H_

#include "../../GraphicLib/LightObjects/LightSource.h"

class Daylight : public LightSource {
    public:
        Daylight();

        virtual ~Daylight();

        virtual void update();
};

#endif /* DAYLIGHT_H_ */
