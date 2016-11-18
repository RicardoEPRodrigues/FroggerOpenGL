/*
 * FpsPerspCamera.h
 *
 *  Created on: Oct 28, 2014
 *      Author: ricardo
 */

#ifndef FPSPERSPCAMERA_H_
#define FPSPERSPCAMERA_H_

#include "../../GraphicLib/CameraObjects/PerspectiveCamera.h"
#include "../../GraphicLib/GameObjects/GameObject.h"

class FpsPerspCamera : public PerspectiveCamera {
    private:
        GameObject* _player;
    public:
        FpsPerspCamera(GameObject* player);

        virtual ~FpsPerspCamera();

        void update(float camX, float camY, float camZ);
};

#endif /* FPSPERSPCAMERA_H_ */
