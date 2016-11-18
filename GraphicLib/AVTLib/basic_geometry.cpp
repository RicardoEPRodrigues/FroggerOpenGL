/* --------------------------------------------------
 Basic Revolution Geometry
 *
 * based on vsResourceLib.cpp from Lighthouse3D
 *
 *
 *
 * Full documentation at 
 * http://www.lighthouse3d.com/very-simple-libs

 Jo�o Madeiras Pereira
 ----------------------------------------------------*/
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <vector>

// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <cmath>
#include "VertexAttrDef.h"
#include "basic_geometry.h"

#include "rectangle.h"
#include "rectanglexy.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

GLuint VboId[2];

void createSphere(float radius, int divisions, MyMesh* mesh) {

    float* p = circularProfile(-3.14159f / 2.0f, 3.14159f / 2.0f, radius,
                               divisions);
    computeVAO(divisions + 1, p + 2, p, divisions * 2, 0.0f, mesh);
}

void createTorus(float innerRadius, float outerRadius, int rings, int sides,
                 MyMesh* mesh) {

    float tubeRadius = (outerRadius - innerRadius) * 0.5f;
    float* p = circularProfile(-3.14159f, 3.14159f, tubeRadius, sides,
                               innerRadius + tubeRadius);
    computeVAO(sides + 1, p + 2, p, rings, 0.0f, mesh);
}

void createCylinder(float height, float radius, int sides, MyMesh* mesh) {

    float p[] = {-radius, -height * 0.5f, 0.0f, -height * 0.5f, radius, -height
                                                                        * 0.5f, radius, height * 0.5f, 0.0f,
                 height * 0.5f, -radius, height
                                         * 0.5f};

    computeVAO(4, p + 2, p, sides, 0.0f, mesh);
}

void createCone(float height, float baseRadius, int sides, MyMesh* mesh) {

    float v[2];
    v[0] = -baseRadius;
    v[1] = height;

    std::vector<float> p;

    p.push_back(-baseRadius);
    p.push_back(0.0f);
    p.push_back(0.0f);
    p.push_back(0.0f);
    p.push_back(baseRadius);
    p.push_back(0.0f);
    int max = (int) (1 + height / (baseRadius * 2 * 3.14159 / sides));
    for (int i = 0; i < max; ++i) {

        p.push_back(baseRadius - i * baseRadius / max);
        p.push_back(i * height / max);
    }
    p.push_back(0.0f);
    p.push_back(height);
    p.push_back(-baseRadius);
    p.push_back(height * 2.0f);
    //float p[(sides+3)*2] = {
    //		-baseRadius,	0.0,
    //		0.0f,			0.0,
    //		baseRadius,		0.0f,
    //		baseRadius + v[0] * 0.1,		v[1] * 0.1,
    //		baseRadius + v[0] * 0.2,		v[1] * 0.2,
    //		baseRadius + v[0] * 0.3,		v[1] * 0.3,
    //		baseRadius + v[0] * 0.4,		v[1] * 0.4,
    //		baseRadius + v[0] * 0.5,		v[1] * 0.5,
    //		baseRadius + v[0] * 0.6,		v[1] * 0.6,
    //		baseRadius + v[0] * 0.7,		v[1] * 0.7,
    //		baseRadius + v[0] * 0.8,		v[1] * 0.8,
    //		baseRadius + v[0] * 0.9,		v[1] * 0.9,
    //		0.0f,			height,
    //		-baseRadius,	height*2.0f,
    //	};

    computeVAO((p.size() - 4) / 2, &(p[2]), &(p[0]), sides, 0.0f, mesh);
}

void computeVAO(int numP, float* p, float* points, int sides, float smoothCos,
                MyMesh* mesh) {
    // Compute and store vertices

    int numSides = sides;
    int numPoints = numP + 2;

    float* vertex = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));
    float* normal = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));
    float* textco = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));

    float inc = 2 * 3.14159f / (numSides);
    float nx, ny;
    float delta;
    int smooth;
    std::vector<int> smoothness;
    int k = 0;
    for (int i = 0; i < numP; i++) {
        revSmoothNormal2(points + (i * 2), &nx, &ny, smoothCos, 0);
        for (int j = 0; j <= numSides; j++) {

            if ((i == 0 && p[0] == 0.0f)
                || (i == numP - 1 && p[(i + 1) * 2] == 0.0))
                delta = inc * 0.5f;
            else
                delta = 0.0f;

            normal[((k) * (numSides + 1) + j) * 4] = nx * cos(j * inc + delta);
            normal[((k) * (numSides + 1) + j) * 4 + 1] = ny;
            normal[((k) * (numSides + 1) + j) * 4 + 2] = nx
                                                         * sin(-j * inc + delta);
            normal[((k) * (numSides + 1) + j) * 4 + 3] = 0.0f;

            vertex[((k) * (numSides + 1) + j) * 4] = p[i * 2] * cos(j * inc);
            vertex[((k) * (numSides + 1) + j) * 4 + 1] = p[(i * 2) + 1];
            vertex[((k) * (numSides + 1) + j) * 4 + 2] = p[i * 2]
                                                         * sin(-j * inc);
            vertex[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;

            textco[((k) * (numSides + 1) + j) * 4] = ((j + 0.0f) / numSides);
            textco[((k) * (numSides + 1) + j) * 4 + 1] = (i + 0.0f)
                                                         / (numP - 1);
            textco[((k) * (numSides + 1) + j) * 4 + 2] = 0;
            textco[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;
        }
        k++;
        if (i < numP - 1) {
            smooth = revSmoothNormal2(points + ((i + 1) * 2), &nx, &ny,
                                      smoothCos, 1);

            if (!smooth) {
                smoothness.push_back(1);
                for (int j = 0; j <= numSides; j++) {

                    normal[((k) * (numSides + 1) + j) * 4] = nx * cos(j * inc);
                    normal[((k) * (numSides + 1) + j) * 4 + 1] = ny;
                    normal[((k) * (numSides + 1) + j) * 4 + 2] = nx
                                                                 * sin(-j * inc);
                    normal[((k) * (numSides + 1) + j) * 4 + 3] = 0.0f;

                    vertex[((k) * (numSides + 1) + j) * 4] = p[(i + 1) * 2]
                                                             * cos(j * inc);
                    vertex[((k) * (numSides + 1) + j) * 4 + 1] = p[((i + 1) * 2)
                                                                   + 1];
                    vertex[((k) * (numSides + 1) + j) * 4 + 2] = p[(i + 1) * 2]
                                                                 * sin(-j * inc);
                    vertex[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;

                    textco[((k) * (numSides + 1) + j) * 4] = ((j + 0.0f)
                                                              / numSides);
                    textco[((k) * (numSides + 1) + j) * 4 + 1] = (i + 1 + 0.0f)
                                                                 / (numP - 1);
                    textco[((k) * (numSides + 1) + j) * 4 + 2] = 0;
                    textco[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;
                }
                k++;
            } else
                smoothness.push_back(0);
        }
    }

    unsigned int* faceIndex = (unsigned int*) malloc(
            sizeof(unsigned int) * (numP - 1) * (numSides + 1) * 6);
    unsigned int count = 0;
    k = 0;
    for (int i = 0; i < numP - 1; ++i) {
        for (int j = 0; j < numSides; ++j) {

            /*if (i != 0 || p[0] != 0.0)*/{
                faceIndex[count++] = k * (numSides + 1) + j;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j + 1;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j;
            }
            /*if (i != numP-2 || p[(numP-1)*2] != 0.0)*/{
                faceIndex[count++] = k * (numSides + 1) + j;
                faceIndex[count++] = k * (numSides + 1) + j + 1;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j + 1;
            }

        }
        k++;
        k += smoothness[i];
    }

    int numVertices = numP * 2 * (numSides + 1);
    mesh->numIndexes = count;

    glGenVertexArrays(1, &(mesh->vao));
    glBindVertexArray(mesh->vao);

    //Implementation with glBufferSubData just for learning purposes

    glGenBuffers(2, VboId);
    glBindBuffer(GL_ARRAY_BUFFER, VboId[0]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4 * 3, NULL,
                 GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, numVertices * sizeof(float) * 4,
                    vertex);
    glBufferSubData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4,
                    numVertices * sizeof(float) * 4, normal);
    glBufferSubData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4 * 2,
                    numVertices * sizeof(float) * 4, textco);

    glEnableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glVertexAttribPointer(VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);
    glEnableVertexAttribArray(NORMAL_ATTRIB);
    glVertexAttribPointer(NORMAL_ATTRIB, 4, GL_FLOAT, 0, 0,
                          (void*) (numVertices * sizeof(float) * 4));
    glEnableVertexAttribArray(TEXTURE_COORD_ATTRIB);
    glVertexAttribPointer(TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0,
                          (void*) (numVertices * sizeof(float) * 4 * 2));

    //index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(unsigned int) * mesh->numIndexes, faceIndex, GL_STATIC_DRAW);

// unbind the VAO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glDisableVertexAttribArray(NORMAL_ATTRIB);
    glDisableVertexAttribArray(TEXTURE_COORD_ATTRIB);

    mesh->type = GL_TRIANGLES;
}

int revSmoothNormal2(float* p, float* nx, float* ny, float smoothCos,
                     int beginEnd) {

    float v1x, v1y, v2x, v2y, x, y, norm;
    float auxX, auxY, angle;

    auxX = p[0] - p[2];
    auxY = p[1] - p[3];
    v1x = -auxY;
    v1y = auxX;
    norm = sqrt((v1x * v1x) + (v1y * v1y));
    v1x /= norm;
    v1y /= norm;

    auxX = p[2] - p[4];
    auxY = p[3] - p[5];
    v2x = -auxY;
    v2y = auxX;
    norm = sqrt((v2x * v2x) + (v2y * v2y));
    v2x /= norm;
    v2y /= norm;

    angle = v1x * v2x + v1y * v2y;

    if (angle > smoothCos) {
        x = v1x + v2x;
        y = v1y + v2y;
    } else if (beginEnd == 0) {
        x = v2x;
        y = v2y;
    } else {
        x = v1x;
        y = v1y;

    }

    norm = sqrt(x * x + y * y);

    assert(norm != 0);
    x /= norm;
    y /= norm;

    *nx = x;
    *ny = y;
    if (angle > smoothCos)
        return 1;
    else
        return 0;
}

float* circularProfile(float minAngle, float maxAngle, float radius,
                       int divisions, float transX, float transY) {

    float* p = (float*) malloc(sizeof(float) * 2 * (divisions + 3));
    float step = (maxAngle - minAngle) / divisions;

    for (int i = 0, k = -1; i < divisions + 3; ++i, ++k) {

        p[i * 2] = radius * cos(minAngle + k * step) + transX;
        p[i * 2 + 1] = radius * sin(minAngle + k * step) + transY;
//		printf("%f %f\n", p[i*2], p[i * 2 + 1]);
    }
    return p;
}

void createCube(float size, MyMesh* mesh) {

    float p[] = {-size / sqrt(2.0f), -size * 0.5f, 0.0f, -size * 0.5f, size
                                                                       / sqrt(2.0f), -size * 0.5f, size / sqrt(2.0f),
                 size * 0.5f, 0.0f,
                 size * 0.5f, -size / sqrt(2.0f), size * 0.5f};

    computeVAOCube(4, p + 2, p, 4, 0.0f, mesh);
}

void computeVAOCube(int numP, float* p, float* points, int sides,
                    float smoothCos, MyMesh* mesh) {
    // Compute and store vertices

    int numSides = sides;

    float* vertex = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));
    float* normal = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));
    float* textco = (float*) malloc(
            sizeof(float) * numP * 2 * 4 * (numSides + 1));

    float inc = 2 * 3.14159f / (numSides);
    float inc2 = 3.14159f / 4;
    float nx, ny;
    float delta;
    int smooth;
    std::vector<int> smoothness;
    int k = 0;
    for (int i = 0; i < numP; i++) {
        revSmoothNormal2(points + (i * 2), &nx, &ny, smoothCos, 0);
        for (int j = 0; j <= numSides; j++) {

            if ((i == 0 && p[0] == 0.0f)
                || (i == numP - 1 && p[(i + 1) * 2] == 0.0))
                delta = inc * 0.5f;
            else
                delta = 0.0f;

            normal[((k) * (numSides + 1) + j) * 4] = nx
                                                     * cos(j * inc + delta + inc2);
            normal[((k) * (numSides + 1) + j) * 4 + 1] = ny;
            normal[((k) * (numSides + 1) + j) * 4 + 2] = nx
                                                         * sin(-j * inc + delta - inc2);
            normal[((k) * (numSides + 1) + j) * 4 + 3] = 0.0f;

            vertex[((k) * (numSides + 1) + j) * 4] = p[i * 2]
                                                     * cos(j * inc + inc2);
            vertex[((k) * (numSides + 1) + j) * 4 + 1] = p[(i * 2) + 1];
            vertex[((k) * (numSides + 1) + j) * 4 + 2] = p[i * 2]
                                                         * sin(-j * inc - inc2);
            vertex[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;

            textco[((k) * (numSides + 1) + j) * 4] = ((j + 0.0f) / numSides);
            textco[((k) * (numSides + 1) + j) * 4 + 1] = (i + 0.0f)
                                                         / (numP - 1);
            textco[((k) * (numSides + 1) + j) * 4 + 2] = 0;
            textco[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;
        }
        k++;
        if (i < numP - 1) {
            smooth = revSmoothNormal2(points + ((i + 1) * 2), &nx, &ny,
                                      smoothCos, 1);

            if (!smooth) {
                smoothness.push_back(1);
                for (int j = 0; j <= numSides; j++) {

                    normal[((k) * (numSides + 1) + j) * 4] = nx
                                                             * cos(j * inc + inc2);
                    normal[((k) * (numSides + 1) + j) * 4 + 1] = ny;
                    normal[((k) * (numSides + 1) + j) * 4 + 2] = nx
                                                                 * sin(-j * inc - inc2);
                    normal[((k) * (numSides + 1) + j) * 4 + 3] = 0.0f;

                    vertex[((k) * (numSides + 1) + j) * 4] = p[(i + 1) * 2]
                                                             * cos(j * inc + inc2);
                    vertex[((k) * (numSides + 1) + j) * 4 + 1] = p[((i + 1) * 2)
                                                                   + 1];
                    vertex[((k) * (numSides + 1) + j) * 4 + 2] = p[(i + 1) * 2]
                                                                 * sin(-j * inc - inc2);
                    vertex[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;

                    textco[((k) * (numSides + 1) + j) * 4] = ((j + 0.0f)
                                                              / numSides);
                    textco[((k) * (numSides + 1) + j) * 4 + 1] = (i + 1 + 0.0f)
                                                                 / (numP - 1);
                    textco[((k) * (numSides + 1) + j) * 4 + 2] = 0;
                    textco[((k) * (numSides + 1) + j) * 4 + 3] = 1.0f;
                }
                k++;
            } else
                smoothness.push_back(0);
        }
    }

    unsigned int* faceIndex = (unsigned int*) malloc(
            sizeof(unsigned int) * (numP - 1) * (numSides + 1) * 6);
    unsigned int count = 0;
    k = 0;
    for (int i = 0; i < numP - 1; ++i) {
        for (int j = 0; j < numSides; ++j) {

            /*if (i != 0 || p[0] != 0.0)*/{
                faceIndex[count++] = k * (numSides + 1) + j;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j + 1;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j;
            }
            /*if (i != numP-2 || p[(numP-1)*2] != 0.0)*/{
                faceIndex[count++] = k * (numSides + 1) + j;
                faceIndex[count++] = k * (numSides + 1) + j + 1;
                faceIndex[count++] = (k + 1) * (numSides + 1) + j + 1;
            }

        }
        k++;
        k += smoothness[i];
    }

    int numVertices = numP * 2 * (numSides + 1);
    mesh->numIndexes = count;

    glGenVertexArrays(1, &(mesh->vao));
    glBindVertexArray(mesh->vao);

    //Implementation with glBufferSubData just for learning purposes

    glGenBuffers(2, VboId);
    glBindBuffer(GL_ARRAY_BUFFER, VboId[0]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4 * 3, NULL,
                 GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, numVertices * sizeof(float) * 4,
                    vertex);
    glBufferSubData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4,
                    numVertices * sizeof(float) * 4, normal);
    glBufferSubData(GL_ARRAY_BUFFER, numVertices * sizeof(float) * 4 * 2,
                    numVertices * sizeof(float) * 4, textco);

    glEnableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glVertexAttribPointer(VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);
    glEnableVertexAttribArray(NORMAL_ATTRIB);
    glVertexAttribPointer(NORMAL_ATTRIB, 4, GL_FLOAT, 0, 0,
                          (void*) (numVertices * sizeof(float) * 4));
    glEnableVertexAttribArray(TEXTURE_COORD_ATTRIB);
    glVertexAttribPointer(TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0,
                          (void*) (numVertices * sizeof(float) * 4 * 2));

    //index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(unsigned int) * mesh->numIndexes, faceIndex, GL_STATIC_DRAW);

// unbind the VAO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glDisableVertexAttribArray(NORMAL_ATTRIB);
    glDisableVertexAttribArray(TEXTURE_COORD_ATTRIB);

    mesh->type = GL_TRIANGLES;
}

void createRectangle(MyMesh* mesh) {
    createVAO(RectangleInfo::vertices, RectangleInfo::normals, RectangleInfo::texCoords,
              RectangleInfo::faceIndex, RectangleInfo::verticeCount, RectangleInfo::faceCount,
              mesh);
}

void createRectangleXY(MyMesh* mesh) {
    createVAO(RectangleXYInfo::vertices, RectangleXYInfo::normals, RectangleXYInfo::texCoords,
              RectangleXYInfo::faceIndex, RectangleXYInfo::verticeCount, RectangleXYInfo::faceCount,
              mesh);
}

void createVAO(float* vertex, float* normal, float* textco,
               unsigned int* indexes, int vertexCount, int faceCount, MyMesh* mesh) {
    glGenVertexArrays(1, &(mesh->vao));
    glBindVertexArray(mesh->vao);

    int vertexArraySize = vertexCount * sizeof(float) * 4;
    int normalArraySize = vertexCount * sizeof(float) * 3;
    int textcoArraySize = vertexCount * sizeof(float) * 2;

    glGenBuffers(2, VboId);
    glBindBuffer(GL_ARRAY_BUFFER, VboId[0]);
    glBufferData(GL_ARRAY_BUFFER,
                 vertexArraySize + normalArraySize + textcoArraySize, NULL,
                 GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, vertexArraySize, vertex);

    glBufferSubData(GL_ARRAY_BUFFER, vertexArraySize, normalArraySize, normal);

    glBufferSubData(GL_ARRAY_BUFFER, vertexArraySize + normalArraySize,
                    textcoArraySize, textco);

    glEnableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glVertexAttribPointer(VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

    glEnableVertexAttribArray(NORMAL_ATTRIB);
    glVertexAttribPointer(NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0,
                          BUFFER_OFFSET(vertexArraySize));

    glEnableVertexAttribArray(TEXTURE_COORD_ATTRIB);
    glVertexAttribPointer(TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0,
                          BUFFER_OFFSET(vertexArraySize + normalArraySize));

    //index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faceCount * 3 * sizeof(unsigned int), indexes,
                 GL_STATIC_DRAW);

    // unbind the VAO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(VERTEX_COORD_ATTRIB);
    glDisableVertexAttribArray(NORMAL_ATTRIB);
    glDisableVertexAttribArray(TEXTURE_COORD_ATTRIB);

    mesh->numIndexes = faceCount * 3;

    mesh->type = GL_TRIANGLES;
}
