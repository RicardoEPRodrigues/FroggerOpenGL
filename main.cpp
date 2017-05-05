//
// AVT demo light 
// based on demos from GLSL Core Tutorial in Lighthouse3D.com   
//

#include <iostream>

#include "FroggerObjects/FroggerGameManager.h"
// include GLEW to access OpenGL 3.3 functions

// GLUT is the toolkit to interface with the OS

FroggerGameManager* manager;

void timer(int value) {
    manager->onTimer();
    glutTimerFunc(1000, timer, 0);
}

void refresh(int value) {
    manager->refresh();
    glutTimerFunc((unsigned int) int(1000.0f / 60.0f), refresh, 0);
}

void update(int value) {
    manager->update();
    glutTimerFunc(750, update, 0);
}

void dificulty(int value) {
    manager->increaseDificulty();
    glutTimerFunc(1000 * 30, dificulty, 0);
}

void gravity(int value) {
    manager->gravity();
    glutTimerFunc(33, gravity, 1);
}

// ------------------------------------------------------------
//
// Reshape Callback Function
//

void changeSize(int w, int h) {
    manager->reshape(w, h);
}

// ------------------------------------------------------------
//
// Render stufff
//

void renderScene(void) {
    manager->display();
}

// ------------------------------------------------------------
//
// Events from the Keyboard
//

void processKeys(unsigned char key, int xx, int yy) {
    manager->keyPressed(key, xx, yy);
}

// ------------------------------------------------------------
//
// Mouse Events
//

void processMouseButtons(int button, int state, int xx, int yy) {
    manager->processMouseButtons(button, state, xx, yy);
}

// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy) {
    manager->processMouseMotion(xx, yy);
}

void mouseWheel(int wheel, int direction, int x, int y) {
    manager->mouseWheel(wheel, direction, x, y);
}

// ------------------------------------------------------------
//
// Model loading and OpenGL setup
//

void init() {
    manager->init();
}

// ------------------------------------------------------------
//
// Main function
//

int main(int argc, char** argv) {
    manager = new FroggerGameManager();
//  GLUT initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(
            GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE |
            GLUT_STENCIL);

    glutInitContextVersion(4, 5);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(manager->getWinX(), manager->getWinY());
//	glutInitWindowSize(WinX, WinY);
    int WindowHandle = glutCreateWindow(manager->getTitle().c_str());
//	WindowHandle = glutCreateWindow(CAPTION);

    manager->setWindowHandle(WindowHandle);

//  Callback Registration
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

//	Mouse and Keyboard Callbacks
    glutKeyboardFunc(processKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);
    glutMouseWheelFunc(mouseWheel);
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, refresh, 0);

    glutTimerFunc(1000 * 30, dificulty, 0);

    glutTimerFunc(0, update, 0);

    glutTimerFunc(33, gravity, 1);

    //	return from main loop
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                  GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    //	Init GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));
    printf("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    if (!manager->setupShaders())
        return (1);

    init();

    //  GLUT main loop
    glutMainLoop();

    return (0);

}
