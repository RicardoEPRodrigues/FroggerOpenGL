/*
 * Particle.h
 *
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <cstdlib>
#include <cmath>

#include "../SimpleObjects/Sphere.h"
#include "../../GraphicLib/GameObjects/ComposedObject.h"
#include "../../GraphicLib/GameObjects/DynamicObject.h"

class Particle : public DynamicObject, public ComposedObject {

    public:
#define frand()            ((float)std::rand()/RAND_MAX)
#define M_PI            3.14159265
#define MAX_PARTICULAS  50

        typedef struct {
            float life;        // vida
            float fade;        // fade
            float r, g, b;    // color
            GLfloat x, y, z;    // pos
            GLfloat vx, vy, vz; // velocidade
            GLfloat ax, ay, az; // aceleracao
            MyMesh* mesh;
            Sphere* s;
        } Particulas;
    private:
        Particulas particula[MAX_PARTICULAS];
        GLfloat v, theta, phi;
        MyMesh* mesh;
        float h;
    public:

        Particle();

        virtual ~Particle();

        void update();

        void reset();
};

#endif /* PARTICLE_H_ */
