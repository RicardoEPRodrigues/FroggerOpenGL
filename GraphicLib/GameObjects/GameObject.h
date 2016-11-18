/*
 * GameObject.h
 *
 *  Created on: Oct 20, 2014
 *      Author: ian
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../Entity.h"

#include "../Engine.h"

class GameObject : public Entity {
    private:
        bool _alive;
        Vector3 _rotation, _scale;
    protected:
        virtual void drawInside(Engine engine) = 0;

    public:
        GameObject();

        virtual ~GameObject();

        virtual void init() = 0;

        void draw(Engine engine);

        virtual void update(double delta_t) = 0;

        void setRotation(float x, float y, float z);

        void setScale(float x, float y, float z);

        void addPos(float x, float y, float z);

        void addRotation(float x, float y, float z);

        void addScale(float x, float y, float z);

        bool isAlive() const {
            return _alive;
        }

        void setAlive(bool alive) {
            _alive = alive;
        }

        Vector3 getRotation() const {
            return _rotation;
        }

        Vector3 getScale() const {
            return _scale;
        }
};

#endif /* GAMEOBJECT_H_ */
