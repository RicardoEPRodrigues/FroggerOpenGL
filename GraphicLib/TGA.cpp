#include "TGA.h"

//extern GLuint TextureArray[2];
using namespace std;

void TGA_Texture(unsigned int* textureArray, const char* strFileName, int ID) {
    tImageTGA* pBitMap;
    int textureType;
    if (!strFileName) return;

    pBitMap = Load_TGA(strFileName);

    if (pBitMap == nullptr) {
        exit(0);
//        return;
    }


    //Objecto textura a ser preenchido
    glBindTexture(GL_TEXTURE_2D, textureArray[ID]);

    textureType = GL_RGB;
    if (pBitMap->channels == 4) textureType = GL_RGBA;

    //ATENCAO:N�o funciona usar no parametro internal format da funcao o numero de canais. Tem de ser uma cont simbolica: GL_RGB ou GL_RGBA
    //glTexImage2D(GL_TEXTURE_2D,0, pBitMap->channels, pBitMap->size_x, pBitMap->size_y, 0,textureType, GL_UNSIGNED_BYTE, pBitMap->data);

    glTexImage2D(GL_TEXTURE_2D, 0, textureType, pBitMap->size_x, pBitMap->size_y, 0, textureType, GL_UNSIGNED_BYTE,
                 pBitMap->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    if (pBitMap->data) {
        free(pBitMap->data);
    }
    free(pBitMap);
}

void loadTexture(unsigned int* textureArray, const char* bitmap_file, int ID) {

    glbmp_t bitmap;

    if (!glbmp_LoadBitmap(bitmap_file, 0, &bitmap)) {
        fprintf(stderr, "Error loading bitmap file: %s\n", bitmap_file);
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, textureArray[ID]);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.width, bitmap.height,
                 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.rgb_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glbmp_FreeBitmap(&bitmap);
}


tImageTGA* Load_TGA(const char* strfilename) {
    //tImageTGA *pImgData	= NULL;
    //	FILE *pFile			= NULL;
    tImageTGA* pImgData;
    FILE* pFile;
    WORD width = 0;
    WORD height = 0;
    byte length = 0;
    byte imgType = 0;
    byte bits = 0;
    int channels = 0;
    int stride = 0;

    if ((pFile = fopen(strfilename, "rb")) == NULL) {
        printf("Error loading tga file.\n");
        return NULL;
    }

    pImgData = (tImageTGA*) malloc(sizeof(tImageTGA));

    fread(&length, sizeof(byte), 1, pFile);

    fseek(pFile, 1, SEEK_CUR);

    fread(&imgType, sizeof(byte), 1, pFile);

    fseek(pFile, 9, SEEK_CUR);

    fread(&width, sizeof(WORD), 1, pFile);
    fread(&height, sizeof(WORD), 1, pFile);
    fread(&bits, sizeof(byte), 1, pFile);

    fseek(pFile, length + 1, SEEK_CUR);
    //printf("bits=%d\n",bits);

    if (imgType != TGA_RLE) {
        // Check for 24 or 32 Bit
        if (bits == 24 || bits == 32) {

            channels = bits / 8;
            stride = channels * width;
            pImgData->data = new unsigned char[stride * height];

            for (int y = 0; y < height; y++) {
                unsigned char* pLine = &(pImgData->data[stride * y]);

                fread(pLine, stride, 1, pFile);

                for (int i = 0; i < stride; i += channels) {
                    int temp = pLine[i];
                    pLine[i] = pLine[i + 2];
                    pLine[i + 2] = temp;
                }
            }
        }

            // Check for 16 Bit
        else if (bits == 16) {
            unsigned short pixels = 0;
            int r = 0, g = 0, b = 0;

            channels = 3;
            stride = channels * width;
            pImgData->data = new unsigned char[stride * height];

            for (int i = 0; i < width * height; i++) {
                fread(&pixels, sizeof(unsigned short), 1, pFile);

                b = (pixels & 0x1f) << 3;
                g = ((pixels >> 5) & 0x1f) << 3;
                r = ((pixels >> 10) & 0x1f) << 3;

                pImgData->data[i * 3 + 0] = r;
                pImgData->data[i * 3 + 1] = g;
                pImgData->data[i * 3 + 2] = b;
            }
        } else {
            return NULL;
        }
    } else {

        byte rleID = 0;
        int colorsRead = 0;
        channels = bits / 8;
        stride = channels * width;

        pImgData->data = new unsigned char[stride * height];
        byte* pColors = new byte[channels];

        int i = 0;
        while (i < width * height) {

            fread(&rleID, sizeof(byte), 1, pFile);


            if (rleID < 128) {
                rleID++;

                while (rleID) {
                    fread(pColors, sizeof(byte) * channels, 1, pFile);

                    pImgData->data[colorsRead + 0] = pColors[2];
                    pImgData->data[colorsRead + 1] = pColors[1];
                    pImgData->data[colorsRead + 2] = pColors[0];

                    if (bits == 32) pImgData->data[colorsRead + 3] = pColors[3];

                    i++;
                    rleID--;
                    colorsRead += channels;
                }
            } else {
                rleID -= 127;

                fread(pColors, sizeof(byte) * channels, 1, pFile);

                while (rleID) {
                    pImgData->data[colorsRead + 0] = pColors[2];
                    pImgData->data[colorsRead + 1] = pColors[1];
                    pImgData->data[colorsRead + 2] = pColors[0];

                    if (bits == 32) pImgData->data[colorsRead + 3] = pColors[3];

                    i++;
                    rleID--;
                    colorsRead += channels;
                }
            }
        }
        delete[] pColors;
    }

    fclose(pFile);


    pImgData->channels = channels;
    pImgData->size_x = width;
    pImgData->size_y = height;

    return pImgData;
} // End of Load_TGA function

void loadRawTextures(unsigned int* textureArray, const char* filename, int textureId) {
    FILE* f = fopen(filename, "rb");
    int nBytes;

    int height = 0;
    int width = 0;
    void* pixels = NULL;
    unsigned char* memory = NULL;

    if (f) {
        int j;
        unsigned char* ppix;

        // Find file length by seeking to end of file.
        fseek(f, 0, SEEK_END);
        nBytes = ftell(f);
        fseek(f, 0, SEEK_SET);

        memory = (unsigned char*) malloc(nBytes);
        fread(memory, 1, nBytes, f);
        fclose(f);

        // Read little-endian texture sizes in machine-independent way.
        width = (memory[1] << 8) | (memory[0]);
        height = (memory[3] << 8) | (memory[2]);
        pixels = memory + 4;

        // Fix ARGB --> RGBA pixel byte order to suit OpenGL pixel format.
        j = width * height;
        ppix = (unsigned char*) pixels;
        while (j--) {
            unsigned char b = ppix[0];
            unsigned char g = ppix[1];
            unsigned char r = ppix[2];
            unsigned char a = ppix[3];

            ppix[0] = r;
            ppix[1] = g;
            ppix[2] = b;
            ppix[3] = a;

            ppix += 4;
        }

        glBindTexture(GL_TEXTURE_2D, textureArray[textureId]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, memory);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
}