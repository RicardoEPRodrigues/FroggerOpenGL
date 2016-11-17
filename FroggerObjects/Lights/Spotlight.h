
#ifndef SPOTLIGHT_H_
#define SPOTLIGHT_H_
#include "../../GraphicLib/LightObjects/LightSource.h"
#include "../../GraphicLib/GameObjects/GameObject.h"
class Spotlight : public LightSource {
private:
	GameObject * _player;
public:
	Spotlight(GameObject * player);
	~Spotlight(void);
	void update();
};

#endif /* SPOTLIGHT_H_ */
