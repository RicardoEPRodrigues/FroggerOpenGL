#include "Particle.h"

#include <cstring>

using namespace std;

Particle::Particle() {
    for (int i = 0; i < MAX_PARTICULAS; i++) {
        particula[i].mesh = new MyMesh();
        v = 0.8 * frand() + 0.2;
        h = 0.295f;
        phi = frand() * M_PI;
        theta = 2.0 * frand() * M_PI;
        particula[i].x = 0.0f;
        particula[i].y = 0.0f;
        particula[i].z = 0.0f;
        particula[i].vx = v * cos(theta) * sin(phi);
        particula[i].vy = v * cos(phi);
        particula[i].vz = v * sin(theta) * sin(phi);
        particula[i].ax = 0.1f;
        particula[i].ay = -0.15f;
        particula[i].az = 0.0f;

        particula[i].r = 0.882f;
        particula[i].g = 0.552f;
        particula[i].b = 0.211f;

        particula[i].life = 1.0f;
        particula[i].fade = 0.01f;

        float amb[] = {particula[i].r, particula[i].g, particula[i].b, particula[i].life};
        float diff[] = {0.5f, 0.5f, 0.5f, 1.0f};
        float spec[] = {0.2f, 0.2f, 0.2f, 1.0f};
        float emissive[] = {0.0f, 0.0f, 0.0f, 0.0f};
        float shininess = 50.0f;
        int texcount = 4;

        memcpy((*(particula[i].mesh)).mat.ambient, amb, 4 * sizeof(float));
        memcpy((*(particula[i].mesh)).mat.diffuse, diff, 4 * sizeof(float));
        memcpy((*(particula[i].mesh)).mat.specular, spec, 4 * sizeof(float));
        memcpy((*(particula[i].mesh)).mat.emissive, emissive, 4 * sizeof(float));
        (*(particula[i].mesh)).mat.shininess = shininess;
        (*(particula[i].mesh)).mat.texCount = texcount;

        particula[i].s = new Sphere(particula[i].mesh);
        particula[i].s->setScale(1.0f, 1.0f, 1.0f);
        particula[i].s->setPosition(particula[i].x, particula[i].y, particula[i].z);
        this->addElement(particula[i].s);
    }
}

Particle::~Particle() {

}

void Particle::update() {

    for (int i = 0; i < MAX_PARTICULAS; i++) {
        if (particula[i].life > 0.0f) {

            particula[i].x += (h * particula[i].vx);
            particula[i].y += (h * particula[i].vy);
            particula[i].z += (h * particula[i].vz);
            particula[i].vx += (h * particula[i].ax);
            particula[i].vy += (h * particula[i].ay);
            particula[i].vz += (h * particula[i].az);
            particula[i].life -= particula[i].fade;

            float amb[] = {particula[i].r, particula[i].g, particula[i].b, particula[i].life};
            memcpy((*particula[i].mesh).mat.ambient, amb, 4 * sizeof(float));


            particula[i].s->setPosition(particula[i].x, particula[i].y, particula[i].z);
        } else {
            this->setAlive(false);
        }

    }
}

void Particle::reset() {
    this->setAlive(true);
    for (int i = 0; i < MAX_PARTICULAS; i++) {
        particula[i].mesh = new MyMesh();
        v = 0.8 * frand() + 0.2;
        phi = frand() * M_PI;
        theta = 2.0 * frand() * M_PI;
        particula[i].x = 0.0f;
        particula[i].y = 0.0f;
        particula[i].z = 0.0f;

        particula[i].vx = v * cos(theta) * sin(phi);
        particula[i].vy = v * cos(phi);
        particula[i].vz = v * sin(theta) * sin(phi);

        particula[i].life = 1.0f;

        float amb[] = {particula[i].r, particula[i].g, particula[i].b, particula[i].life};

        memcpy((*(particula[i].mesh)).mat.ambient, amb, 4 * sizeof(float));

        particula[i].s->setPosition(particula[i].x, particula[i].y, particula[i].z);
    }
}
