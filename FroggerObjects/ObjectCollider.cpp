/*
 * ObjectCollider.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: ricardo
 */

#include "ObjectCollider.h"

ObjectCollider::ObjectCollider() {
    this->_player = NULL;
    this->_river = NULL;
    this->_friendly_objects = new std::list<HitableObject*>();
    this->_enemy_objects = new std::list<HitableObject*>();
}

ObjectCollider::~ObjectCollider() {
}

bool ObjectCollider::DetectCollisions() {
    if (this->_player == NULL || this->_river == NULL)
        return false;

    std::list<HitableObject*>::iterator hitableIterator;

    for (hitableIterator = this->_friendly_objects->begin();
         hitableIterator != this->_friendly_objects->end(); hitableIterator++) {
        if (this->_player->isHit((*hitableIterator), false)) {
            this->_player->setPosition((*hitableIterator)->getPosition()->getX(), this->_player->getPosition()->getY(),
                                       this->_player->getPosition()->getZ());
            return false;
        }
        if (this->_player->getPosition()->getX() > 40 || this->_player->getPosition()->getX() < -40) {
            this->_player->die();
            return true;
        }
    }

    for (hitableIterator = this->_enemy_objects->begin();
         hitableIterator != this->_enemy_objects->end(); hitableIterator++) {
        if (this->_player->isHit((*hitableIterator), false)) {
            this->_player->die();
            return true;
        }
    }

    if (this->_player->isHit(this->_river, false)) {
        for (hitableIterator = this->_friendly_objects->begin();
             hitableIterator != this->_friendly_objects->end();
             hitableIterator++) {
            if (this->_player->isHit((*hitableIterator), false)) {
                return false;
            }
        }
        this->_player->die();
        return true;
        //return false;
    }
    return false;
}

void ObjectCollider::addFriendlyObject(HitableObject* friendly) {
    this->_friendly_objects->push_back(friendly);
}

void ObjectCollider::addEnemyObject(HitableObject* enemy) {
    this->_enemy_objects->push_back(enemy);
}
