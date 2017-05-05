/*
 * GameManager.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "GameManager.h"

#include <iostream>
#include <sstream>

GameManager::GameManager(int numberCameras) {
    this->_engine = new Engine();
    this->_opaque_game_objects = new std::list<GameObject*>();
    this->_billboard_game_objects = new std::list<Billboard*>();
    this->_translucent_game_objects = new std::list<GameObject*>();
    this->_firework_game_objects = new std::list<GameObject*>();
    this->_cameras = new std::vector<Camera*>(numberCameras);
    this->_selected_camera = NULL;
    this->_light_sources = new std::vector<LightSource*>(10);
    this->_fps = 60;
    this->_gamestate = false;

    this->_title = "NoTitle";

    this->_update_speed = 750;

    this->_ratio = 0;
    this->_frame_count = 0;

    this->WinX = 640;
    this->WinY = 480;

    this->WindowHandle = WindowHandle;

    this->_camPos.set(0, 0, 0);

    this->xFlare = 10;
    this->yFlare = WinY - 10;
    this->flareManager = new FlareManager(this->_engine);
}

GameManager::~GameManager() {
    free(this->_opaque_game_objects);
    free(this->_billboard_game_objects);
    free(this->_translucent_game_objects);
    free(this->_firework_game_objects);
    free(this->_cameras);
    free(this->_light_sources);
}

float lightPos[4] = {4.0f, 6.0f, 2.0f, 0.0f};

void GameManager::display() {
    _frame_count++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // load identity matrices
    _engine->matrixModule->loadIdentity(MODEL);
    //Select Camera
    if (this->_selected_camera != NULL) {
        this->_selected_camera->update(this->_camPos.getX(),
                                       this->_camPos.getY(), this->_camPos.getZ());
        this->_selected_camera->computeVisualizationMatrix(this->_engine);
    }

// use our shader
    glUseProgram(_engine->shader.getProgramIndex());

    //send the light position in eye coordinates
    //SEND LIGHTS

    for (unsigned int i = 0; i < this->_light_sources->size(); i++) {
        if ((*this->_light_sources)[i] != NULL) {
            (*this->_light_sources)[i]->draw(this->_engine, i);
        }
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TextureArray[0]);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, TextureArray[1]);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, TextureArray[2]);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, TextureArray[3]);

    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, TextureArray[4]);

    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, TextureArray[5]);

    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, TextureArray[6]);

    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, TextureArray[7]);

    glActiveTexture(GL_TEXTURE8);
    glBindTexture(GL_TEXTURE_2D, TextureArray[8]);

    glActiveTexture(GL_TEXTURE9);
    glBindTexture(GL_TEXTURE_2D, TextureArray[9]);

    glActiveTexture(GL_TEXTURE10);
    glBindTexture(GL_TEXTURE_2D, TextureArray[10]);

    glActiveTexture(GL_TEXTURE11);
    glBindTexture(GL_TEXTURE_2D, TextureArray[11]);

    glActiveTexture(GL_TEXTURE12);
    glBindTexture(GL_TEXTURE_2D, TextureArray[12]);

    glUniform1i(this->_engine->tex_loc1, 0);
    glUniform1i(this->_engine->tex_loc2, 1);
    glUniform1i(this->_engine->tex_loc3, 2);
    glUniform1i(this->_engine->tex_loc4, 3);
    glUniform1i(this->_engine->tex_loc5, 4);
    glUniform1i(this->_engine->tex_loc6, 5);
    glUniform1i(this->_engine->tex_loc7, 6);
    glUniform1i(this->_engine->tex_loc8, 7);
    glUniform1i(this->_engine->tex_loc9, 8);
    glUniform1i(this->_engine->tex_loc10, 9);
    glUniform1i(this->_engine->tex_loc11, 10);
    glUniform1i(this->_engine->tex_loc12, 11);
    glUniform1i(this->_engine->tex_loc13, 12);

    this->applyStencil();

    //DRAW OBJECTS
    std::list<GameObject*>::iterator gobjit;

    for (gobjit = this->_opaque_game_objects->begin();
         gobjit != this->_opaque_game_objects->end(); gobjit++) {
        if ((*gobjit)->isAlive()) {
            (*gobjit)->draw(*this->_engine);
        }
    }


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (this->getGameState()) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        for (gobjit = this->_firework_game_objects->begin();
             gobjit != this->_firework_game_objects->end(); gobjit++) {
            if ((*gobjit)->isAlive()) {
                (*gobjit)->draw(*this->_engine);
            }
        }
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    glDepthMask(GL_FALSE);

    for (gobjit = this->_translucent_game_objects->begin();
         gobjit != this->_translucent_game_objects->end(); gobjit++) {
        if ((*gobjit)->isAlive()) {
            (*gobjit)->draw(*this->_engine);
        }
    }

    std::list<Billboard*>::iterator billboardit;
    for (billboardit = this->_billboard_game_objects->begin();
         billboardit != this->_billboard_game_objects->end();
         billboardit++) {
        if ((*billboardit)->isAlive()) {
            (*billboardit)->setLookAtEntity(this->_selected_camera);
            (*billboardit)->draw(*this->_engine);
        }
    }
    glDepthMask(GL_TRUE);
    //glDisable(GL_BLEND);

    this->_engine->matrixModule->pushMatrix(PROJECTION);
    this->_engine->matrixModule->loadIdentity(PROJECTION);
    this->_engine->matrixModule->ortho(0, this->WinX, 0, this->WinY, -1, 1);

    this->_engine->matrixModule->pushMatrix(VIEW);
    this->_engine->matrixModule->loadIdentity(VIEW);
    this->_engine->matrixModule->lookAt(0, 0, 1, 0, 0, -1, 0, 1, 0);

    flareManager->renderFlare(xFlare, yFlare, this->WinX / 2.0f, this->WinY / 2.0f, this->WinY, this->WinX);

    this->_engine->matrixModule->popMatrix(VIEW);
    this->_engine->matrixModule->popMatrix(PROJECTION);

    glDisable(GL_BLEND);

    glBindTexture(GL_TEXTURE_2D, 0);
    glutSwapBuffers();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
    // Prevent a divide by zero, when window is too short
    if (h == 0)
        h = 1;
    // set the viewport to be the entire window
    glViewport(0, 0, w, h);
    this->WinX = w;
    this->WinY = h;
    // set the projection matrix
    this->_ratio = (1.0f * w) / h;
    if (this->_selected_camera != NULL) {
        this->_selected_camera->computeProjectionMatrix(this->_engine,
                                                        this->_ratio);
    }
}

void GameManager::onTimer() {
    std::ostringstream oss;
    oss << this->_title << ": " << this->_frame_count << " FPS @ (" << WinX
        << "x" << WinY << ")";
    std::string s = oss.str();
    glutSetWindow(this->WindowHandle);
    glutSetWindowTitle(s.c_str());
    _frame_count = 0;
}

void GameManager::refresh() {
    glutPostRedisplay();
}

unsigned int GameManager::setupShaders() {
    return this->_engine->setupShaders();
}

void GameManager::update() {
    std::list<GameObject*>::iterator gobjit;
    for (gobjit = this->_opaque_game_objects->begin();
         gobjit != this->_opaque_game_objects->end(); gobjit++) {
        (*gobjit)->update(0);
    }

    for (gobjit = this->_translucent_game_objects->begin();
         gobjit != this->_translucent_game_objects->end(); gobjit++) {
        (*gobjit)->update(0);
    }
}

void GameManager::applyStencil() {
}

void GameManager::addOpaqueGameObject(GameObject* gameObject) {
    this->_opaque_game_objects->push_front(gameObject);
}

void GameManager::addTranslucentGameObject(GameObject* gameObject) {
    this->_translucent_game_objects->push_front(gameObject);
}

void GameManager::addBillboardGameObject(Billboard* gameObject) {
    this->_billboard_game_objects->push_front(gameObject);
}

void GameManager::addFireworkGameObject(GameObject* gameObject) {
    this->_firework_game_objects->push_front(gameObject);
}

void GameManager::init() {

    std::list<GameObject*>::iterator it;
    for (it = this->_opaque_game_objects->begin();
         it != this->_opaque_game_objects->end(); it++) {
        (*it)->init();
    }

    for (it = this->_translucent_game_objects->begin();
         it != this->_translucent_game_objects->end(); it++) {
        (*it)->init();
    }

    std::list<Billboard*>::iterator billboardit;
    for (billboardit = this->_billboard_game_objects->begin();
         billboardit != this->_billboard_game_objects->end();
         billboardit++) {
        (*billboardit)->init();
    }

    for (it = this->_firework_game_objects->begin();
         it != this->_firework_game_objects->end(); it++) {
        (*it)->init();
    }

    this->flareManager->init();

    this->_engine->lights(true);

    // some GL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glClearStencil(0x0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
