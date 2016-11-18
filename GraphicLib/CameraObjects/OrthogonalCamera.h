/*
 * OrthogonalCamera.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef ORTHOGONALCAMERA_H_
#define ORTHOGONALCAMERA_H_

#include "Camera.h"

class OrthogonalCamera : public Camera {
    private:
        double _left;
        double _right;
        double _bottom;
        double _top;
    public:
        OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);

        virtual ~OrthogonalCamera();

        void computeProjectionMatrix(Engine* engine, float ratio);

        virtual void update(float camX, float camY, float camZ);
};

#endif /* ORTHOGONALCAMERA_H_ */
