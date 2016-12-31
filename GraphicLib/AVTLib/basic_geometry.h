
#ifndef BASIC_GEOMETRY_H_
#define BASIC_GEOMETRY_H_

#include <cassert>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <GL/glew.h>

#define MAX_TEXTURES 4

struct Material {
    float diffuse[4];
    float ambient[4];
    float specular[4];
    float emissive[4];
    float shininess;
    int texCount;
};
// A model can be made of many meshes. Each is stored  in the following structure
struct MyMesh {
    GLuint vao;
    GLuint texUnits[MAX_TEXTURES];
    GLuint texTypes[MAX_TEXTURES];
    float transform[16];
    int numIndexes;
    unsigned int type;
    struct Material mat;
};

void createSphere(float radius, int divisions, MyMesh* mesh);

void createTorus(float innerRadius, float outerRadius, int rings, int sides, MyMesh* mesh);

void createCylinder(float height, float radius, int sides, MyMesh* mesh);

void createCone(float height, float baseRadius, int sides, MyMesh* mesh);

void computeVAO(int numP, float* p, float* pfloatoints, int sides, float smoothCos, MyMesh* mesh);

int revSmoothNormal2(float* p, float* nx, float* ny, float smoothCos, int beginEnd);

float*
circularProfile(float minAngle, float maxAngle, float radius, int divisions, float transX = 0.0f, float transY = 0.0f);

void createCube(float size, MyMesh* mesh);

void computeVAOCube(int numP, float* p, float* pfloatoints, int sides, float smoothCos, MyMesh* mesh);

void createRectangle(MyMesh* mesh);

void createRectangleXY(MyMesh* mesh);

void createVAO(float* vertex, float* normal, float* textco, unsigned int* indexes, int vertexCount, int numIndexes,
               MyMesh* mesh);

#endif // BASIC_GEOMETRY_H_
