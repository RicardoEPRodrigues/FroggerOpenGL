/*
 * SimpleElement.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef SIMPLEOBJECT_H_
#define SIMPLEOBJECT_H_

#include "GameObject.h"

class SimpleObject: public virtual GameObject {
protected:
	MyMesh* mesh;
	void drawInside(Engine engine);
public:
	SimpleObject();
	SimpleObject(MyMesh * mesh);
	virtual ~SimpleObject();

	MyMesh* getMesh() {
		return mesh;
	}
};

#endif /* SIMPLEOBJECT_H_ */
