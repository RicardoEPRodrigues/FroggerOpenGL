/*
 * Billboard.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ricardo
 */

#include "Billboard.h"
#include <cmath>

Billboard::Billboard() {
    this->size = size;
    this->mesh = NULL;
    this->lookAtEntity = lookAtEntity;
}

Billboard::~Billboard() {
    free(this->mesh);
}

void Billboard::init() {
    if (this->mesh) {
        createRectangle(this->mesh);
    }
}

void Billboard::drawInside(Engine engine) {
    if (this->mesh) {
        AVTMatrixModule* module = engine.matrixModule;
        GLint loc;
        module->pushMatrix(MODEL);
        module->pushMatrix(VIEW);

        // send the material
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.ambient");
        glUniform4fv(loc, 1, this->mesh->mat.ambient);
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.diffuse");
        glUniform4fv(loc, 1, this->mesh->mat.diffuse);
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.specular");
        glUniform4fv(loc, 1, this->mesh->mat.specular);
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.shininess");
        glUniform1f(loc, this->mesh->mat.shininess);
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.emissive");
        glUniform4fv(loc, 1, this->mesh->mat.emissive);
        loc = glGetUniformLocation(engine.shader.getProgramIndex(),
                                   "mat.texCount");
        glUniform1f(loc, this->mesh->mat.texCount);

//		module->resetMatrix(MODEL);
//		module->resetMatrix(VIEW);

        Vector3 objToCam = *this->lookAtEntity->getPosition()
                           - *this->getPosition();
        float objToCamProj[] = {objToCam.getX(), objToCam.getY(), 0};

        float lookAt[3];
        this->calculateLookAt(module, lookAt);

        module->normalize(objToCamProj);
        float angleCosine = module->dotProduct(lookAt, objToCamProj);
        float upAux[3];
        module->crossProduct(lookAt, objToCamProj, upAux);

        module->rotate(MODEL, acos(angleCosine) * 180 / 3.14, upAux[0],
                       upAux[1], upAux[2]);
//		this->addRotation(acos(angleCosine)*180/3.14, acos(angleCosine)*180/3.14, acos(angleCosine)*180/3.14);

        module->scale(MODEL, this->getScale().getX(), this->getScale().getY(), this->getScale().getZ());

        // send matrices to OGL
        engine.recomputeMatrices();
        glUniform1i(engine.texMode_uniformId, this->mesh->mat.texCount);
        glBindVertexArray(this->mesh->vao);
        glDrawElements(this->mesh->type, this->mesh->numIndexes,
                       GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        module->popMatrix(VIEW);
        module->popMatrix(MODEL);
    }
}

void Billboard::calculateLookAt(AVTMatrixModule* module, float* res) {
    module->pushMatrix(MODEL);
    module->loadIdentity(MODEL);
    float initialLookAt[] = {0, -1, 0, 1};
    module->rotate(MODEL, this->getRotation().getX(), 1, 0, 0);
    module->rotate(MODEL, this->getRotation().getY(), 0, 1, 0);
    module->rotate(MODEL, this->getRotation().getZ(), 0, 0, 1);
    float auxLookAt[4];
    module->multMatrixPoint(MODEL, initialLookAt, auxLookAt);
    for (int k = 0; k < 3; ++k) {
        res[k] = auxLookAt[k];
    }
    module->popMatrix(MODEL);
}

void Billboard::update(double delta_t) {
}
