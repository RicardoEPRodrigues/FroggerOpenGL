/*
 * Engine.h
 *
 *  Created on: Oct 15, 2014
 *      Author: ricardo
 */

#ifndef ENGINE_H_
#define ENGINE_H_

// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>

// Use Very Simple Libs
#include "AVTLib/vsShaderLib.h"
#include "AVTLib/AVTMatrixModule.h"
#include "AVTLib/VertexAttrDef.h"
#include "AVTLib/basic_geometry.h"

enum CameraType {
    TOPORTHO,
    TOPPERSPECTIVE,
    FPSPERSPECTIVE
};

class Engine {
    private:
        CameraType camera;
    public:
        Engine();

        VSShaderLib shader;

        AVTMatrixModule* matrixModule;

        GLint texMode_uniformId;
        GLint tex_loc1;
        GLint tex_loc2;
        GLint tex_loc3;
        GLint tex_loc4;
        GLint tex_loc5;
        GLint tex_loc6;
        GLint tex_loc7;
        GLint tex_loc8;
        GLint tex_loc9;
        GLint tex_loc10;
        GLint tex_loc11;
        GLint tex_loc12;
        GLint tex_loc13;
        GLint lightsActive;
        GLint fogActive;
        GLint pvm_uniformId;
        GLint vm_uniformId;
        GLint normal_uniformId;
        GLint lPos_uniformId[10];
        GLint sDir_uniformId;

        void recomputeMatrices();

        GLuint setupShaders();

        void lights(bool active);

        void fog(bool active);

};

#endif /* ENGINE_H_ */
