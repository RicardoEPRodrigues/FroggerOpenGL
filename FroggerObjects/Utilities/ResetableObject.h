/*
 * ResetableObject.h
 *
 *  Created on: Oct 29, 2014
 *      Author: ricardo
 */

#ifndef RESETABLEOBJECT_H_
#define RESETABLEOBJECT_H_

#include "../../GraphicLib/GameObjects/DynamicObject.h"

class ResetableObject : public DynamicObject {
private:
	int _resetTime;
	Vector3 _resetPosition;
public:
	ResetableObject();
	virtual ~ResetableObject();

	void setResetPosition(float x, float y, float z ) {
		this->_resetPosition.set(x,y,z);
	}

	void resetPosition();

	void die();
	void respawn();

	int getResetTime() const {
		return _resetTime;
	}

	void updateResetTime();
};

#endif /* RESETABLEOBJECT_H_ */
