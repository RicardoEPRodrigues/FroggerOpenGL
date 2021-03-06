/*
 * AVTMatrixModule.h
 *
 *  Created on: Oct 15, 2014
 *      Author: ricardo
 */

#ifndef AVTMATRIXMODULE_H_
#define AVTMATRIXMODULE_H_

#include <vector>
#include <string>
#include <GL/glew.h>
#include <cmath>
#include <stdlib.h>
#include <string.h>

/// number of settable matrices
#define COUNT_MATRICES 3
/// number of derived matrices
#define COUNT_COMPUTED_MATRICES 2

/// Enumeration of the matrix types
enum MatrixTypes {
    MODEL, VIEW, PROJECTION
};
/// Enumeration of derived matrices
enum ComputedMatrixTypes {
    VIEW_MODEL, PROJ_VIEW_MODEL
};

class AVTMatrixModule {
    public:

        /// The storage for matrices
        float mMatrix[COUNT_MATRICES][16];
        float mCompMatrix[COUNT_COMPUTED_MATRICES][16];
        /// Matrix stacks for all matrix types
        std::vector<float*> mMatrixStack[COUNT_MATRICES];

        /// The normal matrix
        float mNormal3x3[9];

        AVTMatrixModule();

        virtual ~AVTMatrixModule();

        /** Similar to glTranslate*.
         *
         * \param aType any value from MatrixTypes
         * \param x,y,z vector to perform the translation
         */
        void translate(MatrixTypes aType, float x, float y, float z);

        /** Similar to glScale*.
         *
         * \param aType any value from MatrixTypes
         * \param x,y,z scale factors
         */
        void scale(MatrixTypes aType, float x, float y, float z);

        /** Similar to glTotate*.
         *
         * \param aType any value from MatrixTypes
         * \param angle rotation angle in degrees
         * \param x,y,z rotation axis in degrees
         */
        void rotate(MatrixTypes aType, float angle, float x, float y, float z);

        /** Similar to glLoadIdentity.
         *
         * \param aType any value from MatrixTypes
         */
        void loadIdentity(MatrixTypes aType);

        void resetMatrix(MatrixTypes aType, bool x = true, bool y = true, bool z = true);

        /** Similar to glMultMatrix.
         *
         * \param aType any value from MatrixTypes
         * \param aMatrix matrix in column major order data, float[16]
         */
        void multMatrix(MatrixTypes aType, float* aMatrix);

        //resMatrix = resMatrix * aMatrix
        void multMatrix(float* resMatrix, float* aMatrix);

        /** Similar to gLoadMatrix.
         *
         * \param aType any value from MatrixTypes
         * \param aMatrix matrix in column major order data, float[16]
         */

        void loadMatrix(MatrixTypes aType, float* aMatrix);

        /** Similar to glPushMatrix
         *
         * \param aType any value from MatrixTypes
         */
        void pushMatrix(MatrixTypes aType);

        /** Similar to glPopMatrix
         *
         * \param aType any value from MatrixTypes
         */
        void popMatrix(MatrixTypes aType);

        /** Similar to gluLookAt
         *
         * \param xPos, yPos, zPos camera position
         * \param xLook, yLook, zLook point to aim the camera at
         * \param xUp, yUp, zUp camera's up vector
         */
        void lookAt(float xPos, float yPos, float zPos, float xLook, float yLook,
                    float zLook, float xUp, float yUp, float zUp);

        /** Similar to gluPerspective
         *
         * \param fov vertical field of view
         * \param ratio aspect ratio of the viewport or window
         * \param nearp,farp distance to the near and far planes
         */
        void perspective(float fov, float ratio, float nearp, float farp);

        /** Similar to glOrtho and gluOrtho2D (just leave the
         * last two params blank).
         *
         * \param left,right coordinates for the left and right vertical
         * clipping planes
         * \param bottom,top coordinates for the bottom and top horizontal
         * clipping planes
         * \param nearp,farp distance to the near and far planes
         */
        void ortho(float left, float right, float bottom, float top, float nearp =
        -1.0f, float farp = 1.0f);

        /** Similar to glFrustum
         *
         * \param left,right coordinates for the left and right vertical
         * clipping planes
         * \param bottom,top coordinates for the bottom and top horizontal
         * clipping planes
         * \param nearp,farp distance to the near and far planes
         */
        void frustum(float left, float right, float bottom, float top, float nearp,
                     float farp);

        /** Similar to glGet
         *
         * \param aType any value from MatrixTypes
         * \returns pointer to the matrix (float[16])
         */
        float* get(MatrixTypes aType);

        void multMatrixPoint(MatrixTypes aType, float* point, float* res);

        /** Computes the multiplication of a computed matrix and a point
         *
         * \param aType any value from ComputedMatrixTypes
         * \param point a float[4] representing a point
         * \param res a float[4] res = M * point
         */
//        void multMatrixPoint(ComputedMatrixTypes aType, float* point, float* res);

        /** vector cross product res = a x b
         * Note: memory for the result must be allocatted by the caller
         *
         * \param a,b the two input float[3]
         * \param res the ouput result, a float[3]
         */
        static void crossProduct(float* a, float* b, float* res);

        /** vector dot product
         *
         * \param a,b the two input float[3]
         * \returns the dot product a.b
         */
        static float dotProduct(float* a, float* b);

        /// normalize a vec3
        static void normalize(float* a);

        /// vector subtraction res = b - a
        static void subtract(float* a, float* b, float* res);

        /// vector addition res = a + b
        static void add(float* a, float* b, float* res);

        /// vector length
        static float length(float* a);

        /** Set a float* to an identity matrix
         *
         * \param a float array with the matrix contents
         * \param size the order of the matrix
         */
        void setIdentityMatrix(float* mat, int size = 4);

        void setResetMatrix(float* mat, bool x, bool y, bool z);

        /// Computes the 3x3 normal matrix for use with glUniform
        void computeNormalMatrix3x3();

        /// Computes Derived Matrices (4x4)
        void computeDerivedMatrix(ComputedMatrixTypes aType);
};

#endif /* AVTMATRIXMODULE_H_ */
