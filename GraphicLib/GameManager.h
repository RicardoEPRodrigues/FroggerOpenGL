/*
 * GameManager.h
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#ifndef GLLIBS_H_
#define GLLIBS_H_
// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>
#endif //GLLIBS_H_

#include <list>
#include <vector>
#include <string>

#include "Engine.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Billboard.h"
#include "LightObjects/LightSource.h"
#include "CameraObjects/Camera.h"
#include "TGA.h"
#include "FlareManager.h"

class GameManager {
private:
	std::list<GameObject *> * _opaque_game_objects;
	std::list<Billboard *> * _billboard_game_objects;
	std::list<GameObject *> * _translucent_game_objects;
	std::list<GameObject *> * _firework_game_objects;
protected:
	int _frame_count;
	int WindowHandle;
	Vector3 _camPos;
	Engine * _engine;
	double _ratio;
	int WinX , WinY;
	std::vector<LightSource *> * _light_sources;
	std::vector<Camera *> * _cameras;
	Camera * _selected_camera;
	int _fps;
	bool _gamestate;
	std::string _title;
	int _update_speed;
	//Texture Variables
	GLuint TextureArray[13];

	FlareManager * flareManager;
	int     xFlare;
	int     yFlare;

	virtual void applyStencil();

	void addOpaqueGameObject(GameObject * gameObject);
	void addTranslucentGameObject(GameObject * gameObject);
	void addBillboardGameObject(Billboard* gameObject);
	void addFireworkGameObject(GameObject * gameObject);
public:
	// Fixed
	GameManager(int numberCameras);
	virtual ~GameManager();
	void display();
	void reshape(GLsizei w, GLsizei h);
	void refresh();
	unsigned int setupShaders();

	int getFps() const {
		return _fps;
	}

	void setFps(int fps) {
		this->_fps = fps;
	}

	bool getGameState(){
		return _gamestate;
	}
	
	void setGameState(bool gamestate){
		this->_gamestate = gamestate;
	}

	int getUpdateSpeed() const {
		return _update_speed;
	}

	const Engine * getEngine() const {
		return _engine;
	}

	void setEngine(Engine* engine) {
		_engine = engine;
	}

	void setWindowHandle(int windowHandle) {
		WindowHandle = windowHandle;
	}

	int getWinX() const {
		return WinX;
	}

	int getWinY() const {
		return WinY;
	}

	const std::string& getTitle() const {
		return _title;
	}

	// Modifiable
	virtual void onTimer();
	virtual void update();
	virtual void init();
	// Abstract
	virtual void keyPressed(unsigned char key, int xx, int yy) = 0;
	virtual void processMouseButtons(int button, int state, int xx, int yy) = 0;
	virtual void processMouseMotion(int xx, int yy) = 0;
	virtual void mouseWheel(int wheel, int direction, int x, int y) = 0;
};

#endif /* GAMEMANAGER_H_ */
