/*
 * PerspectiveCamera.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef PERSPECTIVECAMERA_H_
#define PERSPECTIVECAMERA_H_

#include "Camera.h"

class PerspectiveCamera : public Camera {
    private:
        double _fovy;
    public:
        PerspectiveCamera(double fovy, double zNear, double zFar);

        virtual ~PerspectiveCamera();

        virtual void update(float camX, float camY, float camZ);

        void computeProjectionMatrix(Engine* engine, float ratio);
};

#endif /* PERSPECTIVECAMERA_H_ */
