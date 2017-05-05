/*
 * MovementEngine.h
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#ifndef MOVEMENTENGINE_H_
#define MOVEMENTENGINE_H_

#include "Utilities/ResetableObject.h"
#include <list>

class MovementEngine {
    private:
        float xMin, xMax;
        float yMin, yMax;
        float zMin, zMax;
        std::list<ResetableObject*>* _resetables;
    public:
        MovementEngine(std::list<ResetableObject*>* resetables, float xMin, float xMax, float yMin, float yMax,
                       float zMin, float zMax);

        virtual ~MovementEngine();

        void update(double delta);

        void reset();
};

#endif /* MOVEMENTENGINE_H_ */
