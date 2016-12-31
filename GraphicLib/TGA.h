

#ifndef TGA_H_
#define TGA_H_

#include <string>
#include <cstdlib>
#include <GL/glew.h>
#include <malloc.h>
#include "glbmp.h"

//#define TGA_RGB        2
//#define TGA_A        3
#define TGA_RLE        10

typedef GLushort WORD;
typedef GLubyte byte;

typedef struct tImageTGA {
    int channels;
    int size_x;
    int size_y;
    unsigned char* data;
} tImageTGA;


void TGA_Texture(unsigned int* textureArray, const char* strFileName, int ID);

void loadTexture(unsigned int* textureArray, const char* bitmap_file, int ID);

tImageTGA* Load_TGA(const char* filename);

void loadRawTextures(unsigned int* textureArray, const char* filename, int textureId);

// www.morrowland.com
// apron@morrowland.com

#endif /* TGA_H_ */