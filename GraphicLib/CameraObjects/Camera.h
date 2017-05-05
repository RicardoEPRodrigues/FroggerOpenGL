/*
 * Camera.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Entity.h"
#include "../Engine.h"

class Camera : public Entity {
    protected:
        Vector3 _up;
        Vector3 _at;
        double _near;
        double _far;
    public:
        Camera(double znear, double zfar);

        virtual ~Camera();

        virtual void update(float camX, float camY, float camZ) = 0;

        virtual void computeProjectionMatrix(Engine* engine, float ratio) = 0;

        void computeVisualizationMatrix(Engine* engine);
};

#endif /* CAMERA_H_ */
