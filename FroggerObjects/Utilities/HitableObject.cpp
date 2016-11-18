/*
 * HitableObject.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: ricardo
 */

#include "HitableObject.h"

HitableObject::HitableObject(Vector3 minBounds, Vector3 maxBounds) {
    this->_min_bounds = minBounds;
    this->_max_bounds = maxBounds;
}

HitableObject::~HitableObject() {
}

bool HitableObject::hitAux(Vector3 firstMinBounds, Vector3 firstMaxBounds,
                           Vector3 secondMinBounds, Vector3 secondMaxBounds, bool compareZ) {
    bool isXCollision = ((firstMinBounds.getX() >= secondMinBounds.getX()
                          && firstMinBounds.getX() <= secondMaxBounds.getX())
                         || (firstMaxBounds.getX() >= secondMinBounds.getX()
                             && firstMaxBounds.getX() <= secondMaxBounds.getX()));
    bool isYCollision = ((firstMinBounds.getY() >= secondMinBounds.getY()
                          && firstMinBounds.getY() <= secondMaxBounds.getY())
                         || (firstMaxBounds.getY() >= secondMinBounds.getY()
                             && firstMaxBounds.getY() <= secondMaxBounds.getY()));
    // if compareZ is not active then the comparison if isZCollision is always true.
    bool isZCollision =
            !compareZ ?
            true :
            ((firstMinBounds.getZ() >= secondMinBounds.getZ()
              && firstMinBounds.getZ() <= secondMaxBounds.getZ())
             || (firstMaxBounds.getZ() >= secondMinBounds.getZ()
                 && firstMaxBounds.getZ()
                    <= secondMaxBounds.getZ()));
    return isXCollision && isYCollision && isZCollision;
}

bool HitableObject::isHit(HitableObject* object, bool compareZ) {
    Vector3 thisPosMin = (*this->getPosition()) + this->_min_bounds;
    Vector3 thisPosMax = (*this->getPosition()) + this->_max_bounds;
    Vector3 objPosMin = (*object->getPosition()) + object->getMinBounds();
    Vector3 objPosMax = (*object->getPosition()) + object->getMaxBounds();
    return hitAux(thisPosMin, thisPosMax, objPosMin, objPosMax, compareZ) ||
           hitAux(objPosMin, objPosMax, thisPosMin, thisPosMax, compareZ);
}

