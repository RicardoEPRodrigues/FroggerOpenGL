/*
 * Sphere.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Sphere : public SimpleObject, public StaticObject {
    public:
        Sphere(MyMesh* mesh);

        virtual ~Sphere();

        void init();
};

#endif /* SPHERE_H_ */
