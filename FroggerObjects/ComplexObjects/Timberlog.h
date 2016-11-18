/*
 * Timberlog.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef TIMBERLOG_H_
#define TIMBERLOG_H_

#include "../Utilities/ResetableObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Timberlog : public HitableObject, public ResetableObject, public ComposedObject {
    public:
        Timberlog();

        virtual ~Timberlog();
};

#endif /* TIMBERLOG_H_ */
