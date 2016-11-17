/*
 * Vector.h
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
protected:
	double _x, _y, _z;
public:
	Vector3();
	Vector3(double x, double y, double z);
	virtual ~Vector3();
	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	Vector3 operator=(const Vector3& vec);
	Vector3 operator*(double num);
	Vector3 operator+(const Vector3& vec);
	Vector3 operator-(const Vector3& vec);
};

#endif /* VECTOR3_H_ */
