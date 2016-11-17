/*
 * Flare.h
 *
 *  Created on: Nov 19, 2014
 *      Author: ricardo
 */

#ifndef FLARE_H_
#define FLARE_H_

#include "SimpleObject.h"

class Flare: public SimpleObject {
private:
	float fDistance;        // Distance along ray from source (0.0-1.0)
	float fSize;            // Size relative to flare envelope (0.0-1.0)
public:
	Flare();
	virtual ~Flare();
	virtual void init();
	virtual void update(double delta_t);

	float getDistance()  {
		return fDistance;
	}

	void setDistance(float distance) {
		fDistance = distance;
	}

	float getSize()  {
		return fSize;
	}

	void setSize(float size) {
		fSize = size;
	}

	void setRGBA(float r, float b, float g, float a);

	void setTexture(int textureId);
};

#endif /* FLARE_H_ */
