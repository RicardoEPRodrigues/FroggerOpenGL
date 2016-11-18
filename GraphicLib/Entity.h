/*
 * Entity.h
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Vector3.h"

class Entity {
    protected:
        Vector3 _position;
    public:
        Entity();

        virtual ~Entity();

        Vector3* setPosition(double x, double y, double z);

        Vector3* setPosition(const Vector3& p);

        Vector3* getPosition();
};

#endif /* ENTITY_H_ */
