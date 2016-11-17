/*
 * StaticObject.h
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_

#include "GameObject.h"

class StaticObject : public virtual GameObject {
public:
	StaticObject();
	virtual ~StaticObject();

	void update(double delta_t);
};

#endif /* STATICOBJECT_H_ */
