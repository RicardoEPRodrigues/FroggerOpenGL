/*
 * LightSource.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#ifndef GLLIBS_H_
#define GLLIBS_H_
// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>
#endif //GLLIBS_H_

#include "../Engine.h"

#include "../Vector3.h"
#include "../Vector4.h"

class LightSource {
private:
	Vector4 _ambient;
	Vector4 _diffuse;
	Vector4 _specular;

	bool _isSpot;
	Vector4 _position;
	Vector3 _direction;

	double _cut_off;
	double _exponent;

	float _constAtt;
	float _lineAtt;
	float _quadAtt;

	bool _state;
public:
	LightSource();
	virtual ~LightSource();

	void setAmbient(const Vector4& ambient) {
		_ambient = ambient;
	}

	void setCutOff(double cutOff) {
		_cut_off = cutOff;
	}

	void setDiffuse(const Vector4& diffuse) {
		_diffuse = diffuse;
	}

	void setDirection(const Vector3& direction) {
		_direction = direction;
	}

	void setExponent(double exponent) {
		_exponent = exponent;
	}

	void setPosition(const Vector4& position) {
		_position = position;
	}

	void setSpecular(const Vector4& specular) {
		_specular = specular;
	}

	bool isState() const {
		return _state;
	}

	void setState(bool state) {
		_state = state;
	}

	void setIsSpot(bool isSpot) {
		_isSpot = isSpot;
	}

	void setAtt(float constAtt, float lineAtt, float quadAtt) {
		_constAtt = constAtt;
		_lineAtt = lineAtt;
		_quadAtt = quadAtt;
	}

	virtual void update() = 0;

	void draw(Engine * engine, int index);
};

#endif /* LIGHTSOURCE_H_ */
