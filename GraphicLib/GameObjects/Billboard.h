/*
 * Billboard.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ricardo
 */

#ifndef BILLBOARD_H_
#define BILLBOARD_H_

#include "GameObject.h"

class Billboard : public GameObject {
    private:
        float size;
        MyMesh* mesh;
        Entity* lookAtEntity;

        void calculateLookAt(AVTMatrixModule* module, float* res);

    protected:
        virtual void drawInside(Engine engine);

    public:
        Billboard();

        virtual ~Billboard();

        virtual void init();

        virtual void update(double delta_t);

        void setMesh(MyMesh* mesh) {
            this->mesh = mesh;
        }

        Entity* getLookAtEntity() {
            return lookAtEntity;
        }

        void setLookAtEntity(Entity* lookAtEntity) {
            this->lookAtEntity = lookAtEntity;
        }
};

#endif /* BILLBOARD_H_ */
