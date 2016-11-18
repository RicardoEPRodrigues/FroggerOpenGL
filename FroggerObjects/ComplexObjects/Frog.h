/*
 * Frog.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ian
 */

#ifndef FROG_H_
#define FROG_H_

#include "../Utilities/ResetableObject.h"
#include "../Utilities/HitableObject.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"

class Frog : public HitableObject, public ResetableObject, public ComposedObject {
    public:
        Frog();

        virtual ~Frog();

        void Up();

        void Down();

        void Left();

        void Right();
};

#endif /* FROG_H_ */
