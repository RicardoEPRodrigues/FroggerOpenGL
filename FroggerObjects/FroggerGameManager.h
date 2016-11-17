/*
 * FroggerGameManager.h
 *
 *  Created on: Oct 27, 2014
 *      Author: ricardo
 */

#ifndef FROGGERGAMEMANAGER_H_
#define FROGGERGAMEMANAGER_H_

#include "../GraphicLib/GameManager.h"
#include "MovementEngine.h"
#include "ObjectCollider.h"
#include "Utilities/ResetableObject.h"
#include "Utilities/ObjectFactory.h"
#include "ComplexObjects/Frog.h"

class FroggerGameManager: public GameManager {
private:
	int _lives;
	Frog * _player;

	ObjectFactory * _factory;
	MovementEngine * _movementEngine;
	ObjectCollider * _collider;
	Particle * particle[4];
	GameObject * _bounderies;

	std::list<ResetableObject *> * _resetables;

	// Mouse Tracking Variables
	int startX, startY, tracking;

	// Camera Spherical Coordinates
	float alpha, beta;
	float r;

	double _dificulty;

	void detectCollision();

public:
	FroggerGameManager();
	virtual ~FroggerGameManager();
	
	void gravity();
	void update();
	void onTimer();
	void applyStencil();
	void keyPressed(unsigned char key, int xx, int yy);
	void processMouseButtons(int button, int state, int xx, int yy);
	void processMouseMotion(int xx, int yy);
	void mouseWheel(int wheel, int direction, int x, int y);
	void init();

	double getDificulty() const {
		return _dificulty;
	}

	void increaseDificulty() {
		_dificulty++;
	}

	void restart();
};

#endif /* FROGGERGAMEMANAGER_H_ */
