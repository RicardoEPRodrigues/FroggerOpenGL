/*
 * HitableObject.h
 *
 *  Created on: Oct 30, 2014
 *      Author: ricardo
 */

#ifndef HITABLEOBJECT_H_
#define HITABLEOBJECT_H_

#include "../../GraphicLib/GameObjects/GameObject.h"

class HitableObject: public virtual GameObject {
protected:
	Vector3 _min_bounds, _max_bounds;

	// True if the objects collide.
	static bool hitAux(Vector3 firstMinBounds, Vector3 firstMaxBounds,
			Vector3 secondMinBounds, Vector3 secondMaxBounds, bool compareZ);
public:
	HitableObject(Vector3 minBounds, Vector3 maxBounds);
	virtual ~HitableObject();

	// true if the objects collide.
	bool isHit(HitableObject * object, bool compareZ);

	const Vector3& getMaxBounds() const {
		return _max_bounds;
	}

	const Vector3& getMinBounds() const {
		return _min_bounds;
	}
};

#endif /* HITABLEOBJECT_H_ */
