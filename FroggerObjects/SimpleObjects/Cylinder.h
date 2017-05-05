/*
 * Cylinder.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Cylinder : public SimpleObject, public StaticObject {
    public:
        Cylinder(MyMesh* mesh);

        virtual ~Cylinder();

        void init();
};

#endif /* CYLINDER_H_ */
