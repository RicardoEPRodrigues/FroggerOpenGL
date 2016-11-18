/*
 * FpsPerspCamera.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#include "FpsPerspCamera.h"

FpsPerspCamera::FpsPerspCamera(GameObject* player) :
        PerspectiveCamera(53.13f, 0.1f, 1000.0f) {
    this->_player = player;
    this->_up.set(0, 0, 1);
}

FpsPerspCamera::~FpsPerspCamera() {
    // TODO Auto-generated destructor stub
}

void FpsPerspCamera::update(float camX, float camY, float camZ) {
    if (this->_player != NULL) {

        int distance = 10;
        int above = 5;

        Vector3 position = *this->_player->getPosition();
        Vector3 gameObjectRotation(this->_player->getRotation());
        int zRotation = (int) gameObjectRotation.getZ();
        switch (zRotation) {
            case 180: //Down
                this->_position.set(position.getX(), position.getY() + distance,
                                    position.getZ() + above);
                break;
            case 90: //Left
                this->_position.set(position.getX() + distance, position.getY(),
                                    position.getZ() + above);
                break;
            case -90: //Right
                this->_position.set(position.getX() - distance, position.getY(),
                                    position.getZ() + above);
                break;
            case 0: //Up
                // Fall Through
            default:
                this->_position.set(position.getX(), position.getY() - distance,
                                    position.getZ() + above);
                break;
        }
//		this->_position.set(position.getX() + camX, position.getY() - camY,
//				position.getZ() + camZ);
        this->_at.set(position.getX(), position.getY(), position.getZ());
    }
}
