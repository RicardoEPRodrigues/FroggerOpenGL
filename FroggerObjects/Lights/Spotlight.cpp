#include "Spotlight.h"

Spotlight::Spotlight(GameObject* player) {
    this->_player = player;
//	Vector4 position(4.0f, 6.0f, 2.0f, 1.0f);
    Vector4 position(this->_player->getPosition()->getX(),
                     this->_player->getPosition()->getY(),
                     this->_player->getPosition()->getZ() + 1, 1.0f);
    Vector3 direction(0.0f, 1.0f, 0.0f); //ATENTION - POINT WHERE IS AIMING
    Vector4 ambient(0.3f, 0.3f, 0.3f, 1.0f);
    Vector4 diffuse(0.7f, 0.7f, 0.7f, 1.0f);
    Vector4 specular(1.0f, 1.0f, 1.0f, 1.0f);
    this->setPosition(position);
    this->setDirection(direction);
    this->setAmbient(ambient);
    this->setDiffuse(diffuse);
    this->setSpecular(specular);
    this->setCutOff(0.3);
    this->setIsSpot(true);
    this->setAtt(0.2f, 0.2f, 0.2f);
    this->setExponent(1.0f);
    //this->setState(true);

}

Spotlight::~Spotlight() {
}

void Spotlight::update() {
    Vector4 position(this->_player->getPosition()->getX(),
                     this->_player->getPosition()->getY(),
                     this->_player->getPosition()->getZ() + 1, 1.0);
    this->setPosition(position);

    Vector3 gameObjectRotation(this->_player->getRotation());
    int zRotation = (int) gameObjectRotation.getZ();
    Vector3 direction;
    switch (zRotation) {
        case 180: //Down
            direction.set(0, -1, 0);
            break;
        case 90: //Left
            direction.set(-1, 0, 0);
            break;
        case -90: //Right
            direction.set(1, 0, 0);
            break;
        case 0: //Up
            // Fall Through
        default:
            direction.set(0, 1, 0);
            break;
    }
    this->setDirection(direction);
}
