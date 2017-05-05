/*
 * GameObject.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#include "GameObject.h"

GameObject::GameObject() :
        Entity() {

    this->setRotation(0, 0, 0);
    this->setScale(1, 1, 1);

    this->_alive = true;
}

GameObject::~GameObject() {

}

void GameObject::draw(Engine engine) {
    AVTMatrixModule* module = engine.matrixModule;

    module->pushMatrix(MODEL);
    module->translate(MODEL, this->_position.getX(), this->_position.getY(),
                      this->_position.getZ());
    module->rotate(MODEL, this->_rotation.getX(), 1, 0, 0);
    module->rotate(MODEL, this->_rotation.getY(), 0, 1, 0);
    module->rotate(MODEL, this->_rotation.getZ(), 0, 0, 1);
    module->scale(MODEL, this->_scale.getX(), this->_scale.getY(), this->_scale.getZ());

    engine.recomputeMatrices();

    this->drawInside(engine);

    module->popMatrix(MODEL);
}

void GameObject::setRotation(float x, float y, float z) {
    this->_rotation.set(x, y, z);
}

void GameObject::setScale(float x, float y, float z) {
    this->_scale.set(x, y, z);
}

void GameObject::addPos(float x, float y, float z) {
    this->_position.set(
            this->_position.getX() + x,
            this->_position.getY() + y,
            this->_position.getZ() + z
    );
}

void GameObject::addRotation(float x, float y, float z) {
    this->_rotation = this->_rotation + Vector3(x, y, z);
}

void GameObject::addScale(float x, float y, float z) {
    this->_scale = this->_scale + Vector3(x, y, z);
}
