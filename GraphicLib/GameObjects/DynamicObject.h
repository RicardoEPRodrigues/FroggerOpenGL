/*
 * DynamicObject.h
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#ifndef DYNAMICOBJECT_H_
#define DYNAMICOBJECT_H_

#include "GameObject.h"
#include "../Vector3.h"

class DynamicObject : public virtual GameObject {
private:
	Vector3 _speed;
public:
	DynamicObject();
	virtual ~DynamicObject();
	void update(double delta_t);
	void setSpeed(const Vector3& speed);
	void setSpeed(double x, double y, double z);
	Vector3 getSpeed();
};

#endif /* DYNAMICOBJECT_H_ */
