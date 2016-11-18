/*
 * Sphere.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "../../GraphicLib/GameObjects/SimpleObject.h"
#include "../../GraphicLib/GameObjects/StaticObject.h"

class Rectangle : public SimpleObject, public StaticObject {
    private:
        float size;
    public:
        Rectangle(MyMesh* mesh);

        virtual ~Rectangle();

        void init();
};

#endif /* RECTANGLE_H_ */
