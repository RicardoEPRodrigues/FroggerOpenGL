/*
 * FroggerGameManager.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: ricardo
 */

#include "FroggerGameManager.h"

#include "Cameras/TopOrthoCamera.h"
#include "Cameras/TopPerspCamera.h"
#include "Cameras/FpsPerspCamera.h"

#include "Lights/Daylight.h"
#include "Lights/Nightlight.h"
#include "Lights/Spotlight.h"

#include <math.h>

#include <cstring>

#include <iostream>
#include <sstream>

FroggerGameManager::FroggerGameManager() :
        GameManager(10) {

    this->_resetables = new std::list<ResetableObject*>();
    this->_factory = new ObjectFactory();
    this->_collider = new ObjectCollider();
    for (int i = 0; i < 4; i++) {
        this->particle[i] = new Particle();
    }
    this->_lives = 5;

    // TITLE INITIALIZATION
    this->_title = "Frogger";

    this->_movementEngine = new MovementEngine(this->_resetables,
                                               -38.0f - 10.0f, 38.0f + 10.0f, -30.0f - 10.0f, 30.0f + 10.0f,
                                               -10.0f, 10.0f);

    //WINDOW INITIALIZATION
//	camX = camY = camZ = 0;
    startX = startY = tracking = 0;
    alpha = 39.0f;
    beta = 51.0f;
    r = 10.0f;

    //GAME OBJECTS INITIALIZATION

    this->_dificulty = 0;

    this->_bounderies = this->_factory->getBounderies();

    this->_player = this->_factory->getFrog();
    this->addOpaqueGameObject(this->_player);
    this->_collider->setPlayer(this->_player);

    Car* car1 = this->_factory->getCar(-25.0f);
    this->addOpaqueGameObject(car1);
    this->_resetables->push_front(car1);
    this->_collider->addEnemyObject(car1);

    Bus* bus1 = this->_factory->getBus(-20.0f);
    this->addOpaqueGameObject(bus1);
    this->_resetables->push_front(bus1);
    this->_collider->addEnemyObject(bus1);

    bus1 = this->_factory->getBus(-10.0f);
    this->addOpaqueGameObject(bus1);
    this->_resetables->push_front(bus1);
    this->_collider->addEnemyObject(bus1);

    Car* car2 = this->_factory->getCar(-15.0f);
    this->addOpaqueGameObject(car2);
    this->_resetables->push_front(car2);
    this->_collider->addEnemyObject(car2);

    car2 = this->_factory->getCar(-5.0f);
    this->addOpaqueGameObject(car2);
    this->_resetables->push_front(car2);
    this->_collider->addEnemyObject(car2);

    Timberlog* timber1 = this->_factory->getTimberlog(10.0f);
    this->addOpaqueGameObject(timber1);
    this->_resetables->push_front(timber1);
    this->_collider->addFriendlyObject(timber1);

    Timberlog* timber2 = this->_factory->getTimberlog(20.0f);
    this->addOpaqueGameObject(timber2);
    this->_resetables->push_front(timber2);
    this->_collider->addFriendlyObject(timber2);

    Turtle* turtle1 = this->_factory->getTurtle(5.0f);
    this->addOpaqueGameObject(turtle1);
    this->_resetables->push_front(turtle1);
    this->_collider->addFriendlyObject(turtle1);

    Turtle* turtle2 = this->_factory->getTurtle(15.0f);
    this->addOpaqueGameObject(turtle2);
    this->_resetables->push_front(turtle2);
    this->_collider->addFriendlyObject(turtle2);

    // BACKGROUND INITIALIZATION

//	float bg_wide = 95.0f;

    GameObject* element2;

    element2 = this->_factory->getBelowRiver();
    this->addOpaqueGameObject(element2);

    element2 = this->_factory->getRiverside();
    this->addOpaqueGameObject(element2);

    element2 = this->_factory->getRoad();
    this->addOpaqueGameObject(element2);

    element2 = this->_factory->getBetweenRoadside();
    this->addOpaqueGameObject(element2);

    element2 = this->_factory->getRoadside();
    this->addOpaqueGameObject(element2);

    this->particle[0] = this->_factory->getParticleNorth();
    this->addFireworkGameObject(particle[0]);

    this->particle[1] = this->_factory->getParticleSouth();
    this->addFireworkGameObject(particle[1]);

    this->particle[2] = this->_factory->getParticleEast();
    this->addFireworkGameObject(particle[2]);

    this->particle[3] = this->_factory->getParticleWest();
    this->addFireworkGameObject(particle[3]);

    River* river = this->_factory->getRiver();
    this->addTranslucentGameObject(river);
    this->_collider->setRiver(river);

    Billboard* billboard;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 40; i++) {
            billboard = this->_factory->getBillboard();
            billboard->setPosition(-40 + (2 * i), 28 + (2 * j), -1.5);
            this->addBillboardGameObject(billboard);
        }
    }

    // END BACKGROUND INITIALIZATION

    //CAMERA INITIALIZATION
    Camera* camera1 = new TopOrthoCamera();
    (*this->_cameras)[0] = camera1;
    this->_selected_camera = camera1;

    camera1 = new TopPerspCamera();
    (*this->_cameras)[1] = camera1;

    camera1 = new FpsPerspCamera(this->_player);
    (*this->_cameras)[2] = camera1;

    //LIGHT INITIALIZATION

    LightSource* light = new Daylight();
    light->setState(true);
    (*this->_light_sources)[0] = light;

    LightSource* light1 = new Spotlight(_player);
    light1->setState(false);
    (*this->_light_sources)[1] = light1;

    LightSource* light2 = new Nightlight(0, 0);
    light2->setState(false);
    (*this->_light_sources)[2] = light2;

    LightSource* light3 = new Nightlight(0, -27);
    light3->setState(false);
    (*this->_light_sources)[3] = light3;

    LightSource* light4 = new Nightlight(40, 0);
    light4->setState(false);
    (*this->_light_sources)[4] = light4;

    LightSource* light5 = new Nightlight(40, -27);
    light5->setState(false);
    (*this->_light_sources)[5] = light5;

    LightSource* light6 = new Nightlight(-40, 0);
    light6->setState(false);
    (*this->_light_sources)[6] = light6;

    LightSource* light7 = new Nightlight(-40, -27);
    light7->setState(false);
    (*this->_light_sources)[7] = light7;

}

FroggerGameManager::~FroggerGameManager() {
    free(this->_player);
}

void FroggerGameManager::onTimer() {
    if (this->_lives > 0) {
        std::ostringstream oss;
        oss << this->_title << " : " << "Lives = " << this->_lives << " : "
            << this->_frame_count << " FPS @ (" << WinX << "x" << WinY
            << ")";
        std::string s = oss.str();
        glutSetWindow(this->WindowHandle);
        glutSetWindowTitle(s.c_str());
        _frame_count = 0;
    } else {
        std::ostringstream oss;
        std::string gameover = "GAME OVER : press 'R' to restart the game";
        oss << gameover << ": " << this->_frame_count << " FPS @ (" << WinX
            << "x" << WinY << ")";
        std::string s = oss.str();
        glutSetWindow(this->WindowHandle);
        glutSetWindowTitle(s.c_str());
        _frame_count = 0;
    }

    if (this->_player->getPosition()->getY() == 25) {
        this->setGameState(true);
        std::ostringstream oss;
        std::string gamewon = "You Won!! : press 'R' to restart the game";
        oss << gamewon << ": " << this->_frame_count << " FPS @ (" << WinX
            << "x" << WinY << ")";
        std::string s = oss.str();
        glutSetWindow(this->WindowHandle);
        glutSetWindowTitle(s.c_str());
        _frame_count = 0;
    }
}

void FroggerGameManager::restart() {
    if (this->_lives <= 0 || this->_player->getPosition()->getY() == 25) {
        this->_lives = 5;
        this->_dificulty = 0;
        this->_player->respawn();
        (*this->_light_sources)[1]->update();
        for (int i = 0; i < 4; i++) {
            this->particle[i]->reset();
        }
        this->setGameState(false);
    }
}

void FroggerGameManager::keyPressed(unsigned char key, int xx, int yy) {
    switch (key) {

        case 27: //ESC
            glutLeaveMainLoop();
            break;

        case 'o':
            if (this->_player->isAlive()
                && this->_player->getPosition()->getX() > -38.0f
                && this->getGameState() == false) {
                this->_player->Left();
                (*this->_light_sources)[1]->update();
                this->detectCollision();
            }
            break;

        case 'p':
            if (this->_player->isAlive()
                && this->_player->getPosition()->getX() < 38.0f
                && this->getGameState() == false) {
                this->_player->Right();
                (*this->_light_sources)[1]->update();
                this->detectCollision();
            }
            break;

        case 'q':
            if (this->_player->isAlive()
                && this->_player->getPosition()->getY() < 30.0f
                && this->getGameState() == false) {
                this->_player->Up();
                (*this->_light_sources)[1]->update();
                this->detectCollision();
            }
            break;

        case 'a':
            if (this->_player->isAlive()
                && this->_player->getPosition()->getY() > -30.0f
                && this->getGameState() == false) {
                this->_player->Down();
                (*this->_light_sources)[1]->update();
                this->detectCollision();
            }
            break;

        case 'r':
            restart();
            break;

        case 'n':
            if ((*this->_light_sources)[0]->isState()) {
                (*this->_light_sources)[0]->setState(false);
                (*this->_light_sources)[1]->setState(true);
            } else {
                (*this->_light_sources)[0]->setState(true);
                (*this->_light_sources)[1]->setState(false);
            }
            break;

        case 'c':
            if ((*this->_light_sources)[2]->isState()) {
                for (int i = 2; i <= 7; i++) {
                    (*this->_light_sources)[i]->setState(false);
                }
            } else {
                for (int i = 2; i <= 7; i++) {
                    (*this->_light_sources)[i]->setState(true);
                }
            }
            break;

        case '1':
            this->_selected_camera = (*this->_cameras)[0];
            this->_selected_camera->computeProjectionMatrix(this->_engine,
                                                            this->_ratio);
            break;
        case '2':
            this->_selected_camera = (*this->_cameras)[1];
            this->_selected_camera->computeProjectionMatrix(this->_engine,
                                                            this->_ratio);
            break;
        case '3':
            this->_selected_camera = (*this->_cameras)[2];
            this->_selected_camera->computeProjectionMatrix(this->_engine,
                                                            this->_ratio);
            break;
    }
}

void FroggerGameManager::detectCollision() {
    if (this->_collider->DetectCollisions()) {
        this->_lives--;
        if (this->_lives > 0) {
            this->_player->respawn();
            (*this->_light_sources)[1]->update();
        }
    }
}

void FroggerGameManager::gravity() {
    if (this->getGameState() == true) {
        for (int i = 0; i < 4; i++) {
            this->particle[i]->update();
        }
    }
}

void FroggerGameManager::update() {
    this->_movementEngine->update(this->_dificulty);
    this->detectCollision();
    (*this->_light_sources)[1]->update();
    this->_movementEngine->reset();
}

void FroggerGameManager::init() {

    this->GameManager::init();

    //Texture Object definition

    glGenTextures(13, TextureArray);
    TGA_Texture(TextureArray, "resources/wood.tga", 0);
    TGA_Texture(TextureArray, "resources/water.tga", 1);
    TGA_Texture(TextureArray, "resources/asphalt.tga", 2);
    loadTexture(TextureArray, "resources/particula.bmp", 3);
    TGA_Texture(TextureArray, "resources/tree.tga", 4);
    TGA_Texture(TextureArray, "resources/grass.tga", 5);
    TGA_Texture(TextureArray, "resources/turtle.tga", 6);
    loadRawTextures(TextureArray, "resources/flare_textures/crcl.raw", 7);
    loadRawTextures(TextureArray, "resources/flare_textures/flar.raw", 8);
    loadRawTextures(TextureArray, "resources/flare_textures/hxgn.raw", 9);
    loadRawTextures(TextureArray, "resources/flare_textures/ring.raw", 10);
    loadRawTextures(TextureArray, "resources/flare_textures/sun.raw", 11);
    TGA_Texture(TextureArray, "resources/head.tga", 12);
    this->_bounderies->init();

    this->_camPos.set(
            r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f),
            this->_player->getPosition()->getX()
            - r * sin(beta * 3.14f / 180.0f),
            r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f));
}

int xMouse = 0, yMouse = 0;

void FroggerGameManager::processMouseButtons(int button, int state, int xx,
                                             int yy) {
    // start tracking the mouse
    if (state == GLUT_DOWN) {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON) {
            tracking = 1;
            xMouse = xx;
            yMouse = yy;

            xFlare = xx * this->WinX / glutGet(GLUT_WINDOW_WIDTH);
            yFlare = WinY - yy * this->WinY / glutGet(GLUT_WINDOW_HEIGHT);
        } else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
    }

        //stop tracking the mouse
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha -= (xx - startX);
            beta += (yy - startY);
        } else if (tracking == 2) {
            r += (yy - startY) * 0.01f;
            if (r < 0.1f)
                r = 0.1f;
        }
        tracking = 0;
    }
}

void FroggerGameManager::processMouseMotion(int xx, int yy) {
    int deltaX, deltaY;
    float alphaAux, betaAux;
    float rAux;

    deltaX = -xx + startX;
    deltaY = yy - startY;

    // left mouse button: move camera
    if (tracking == 1) {
        //&& this->_selected_camera == (*this->_cameras)[2]) {

        // Scale mouse coordinates to compensate for window size.
        xFlare = (xx - xMouse) * this->WinX / glutGet(GLUT_WINDOW_WIDTH);
        yFlare = WinY - ((yy - yMouse) * this->WinY / glutGet(GLUT_WINDOW_HEIGHT));

        // Clamping -- wouldn't be needed in fullscreen mode.
        if (xFlare >= this->WinX)
            xFlare = this->WinX - 1;
        if (xFlare < 0)
            xFlare = 0;
        if (yFlare >= this->WinY)
            yFlare = this->WinY - 1;
        if (yFlare < 0)
            yFlare = 0;

        glutPostRedisplay();
    }
        // right mouse button: zoom
    else if (tracking == 2) {

        //		alphaAux = alpha;
        //		betaAux = beta;
        //		rAux = r + (deltaY * 0.01f);
        //		if (rAux < 0.1f)
        //			rAux = 0.1f;
        this->_player->addPos(-0.001 * deltaX, -0.001 * deltaY, 0.0f);
    }
}

void FroggerGameManager::mouseWheel(int wheel, int direction, int x, int y) {
    r += direction * 0.1f;
    if (r < 0.1f)
        r = 0.1f;

    if (this->_selected_camera == (*this->_cameras)[2]) {

        this->_camPos.set(
                r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f),
                r * sin(beta * 3.14f / 180.0f),
                r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f));
    }
}

void FroggerGameManager::applyStencil() {
    glStencilFunc(GL_ALWAYS, 1, 1);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    this->_bounderies->draw(*this->_engine);
    glClear(GL_DEPTH_BUFFER_BIT); // inicializa o z_buffer
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glStencilFunc(GL_EQUAL, 1, 1);
}
