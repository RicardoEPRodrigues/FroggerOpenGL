/*
 * Vector4.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef VECTOR4_H_
#define VECTOR4_H_

#include "Vector3.h"

class Vector4: public Vector3 {
private:
	double _w;
public:
	Vector4();
	Vector4(double x, double y, double z, double w);
	virtual ~Vector4();
	double getW();
	void set(double x, double y, double z, double w);
	Vector4 operator=(const Vector4& vec);
	Vector4 operator*(double num);
	Vector4 operator+(const Vector4& vec);
	Vector4 operator-(const Vector4& vec);

};

#endif /* VECTOR4_H_ */
