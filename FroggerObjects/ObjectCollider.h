/*
 * ObjectCollider.h
 *
 *  Created on: Oct 30, 2014
 *      Author: ricardo
 */

#ifndef OBJECTCOLLIDER_H_
#define OBJECTCOLLIDER_H_

#include "Utilities/HitableObject.h"
#include "ComplexObjects/Frog.h"
#include "list"

class ObjectCollider {
        Frog* _player;
        HitableObject* _river;
        std::list<HitableObject*>* _friendly_objects, * _enemy_objects;
    public:
        ObjectCollider();

        virtual ~ObjectCollider();

        // True if the frog has died
        bool DetectCollisions();

        void addFriendlyObject(HitableObject* friendly);

        void addEnemyObject(HitableObject* enemy);

        void setPlayer(Frog* player) {
            this->_player = player;
        }

        void setRiver(HitableObject* river) {
            this->_river = river;
        }
};

#endif /* OBJECTCOLLIDER_H_ */
