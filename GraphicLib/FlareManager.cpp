/*
 * FlareManager.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: ricardo
 */

#include "FlareManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <cstring>

// Get height from width, assuming certain aspect ratio.
#define HEIGHTFROMWIDTH(w, SCREENheight, SCREENwidth)  ((320*(w)*SCREENheight)/(240*SCREENwidth))

#define SCALECOLORTO01(color) (color/255.0f)
#define SCALECOLORTO255(color) (color*255.0f)

#define isqrt(x)        (int)((double)(x))

FlareManager::FlareManager(Engine* engine) {
	this->fMaxSize = 1;
	this->fScale = 1;
	this->elements = new std::list<Flare *>();
	this->engine = engine;
	this->loadFlareFile("GraphicLib/flare.txt");
}

FlareManager::~FlareManager() {
	// TODO Auto-generated destructor stub
}

int getTextureId(char * name) {
	if (strncmp(name, "crcl", strlen(name)) == 0) {
		return 8;
	}
	if (strncmp(name, "hxgn", strlen(name)) == 0) {
		return 10;
	}
	if (strncmp(name, "ring", strlen(name)) == 0) {
		return 11;
	}
	if (strncmp(name, "flar", strlen(name)) == 0) {
		return 9;
	}
	if (strncmp(name, "sun", strlen(name)) == 0) {
		return 12;
	}
	return 0;
}

void FlareManager::loadFlareFile(char* filename) {
	FILE *f;
	char buf[256];

	f = fopen(filename, "r");
	if (f) {
		fgets(buf, sizeof(buf), f);
		float scale, maxSize;
		sscanf(buf, "%f %f", &scale, &maxSize);
		this->fScale = scale;
		this->fMaxSize = maxSize;

		while (!feof(f)) {
			char name[8] = { '\0', };
			double dDist = 0.0, dSize = 0.0;
			unsigned int a = 0, r = 0, g = 0, b = 0;

			fgets(buf, sizeof(buf), f);
			if (sscanf(buf, "%s %lf %lf ( %d %d %d %d )", name, &dDist, &dSize,
					&a, &r, &g, &b)) {

				Flare * flare = new Flare();
				flare->setDistance((float) dDist);
				flare->setSize((float) dSize);
				flare->setRGBA(SCALECOLORTO01(r), SCALECOLORTO01(g), SCALECOLORTO01(b), SCALECOLORTO01(a));
				flare->setTexture(getTextureId(name));

				this->elements->push_back(flare);
			}
		}

		fclose(f);
	}
}

void FlareManager::renderFlare(int lx, int ly, int cx, int cy,
		float SCREENheight, float SCREENwidth) {

	this->engine->lights(false);
	this->engine->fog(false);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	float dx, dy;          // Screen coordinates of "destination"
	float px, py;          // Screen coordinates of flare element
	float maxflaredist, flaredist, flaremaxsize, flarescale,flaredistscale;
	float width, height, alpha;    // Piece parameters;

	// Compute how far off-center the flare source is.
	maxflaredist = isqrt(cx * cx + cy * cy);
	flaredist = isqrt((lx - cx) * (lx - cx) + (ly - cy) * (ly - cy));
	flaredistscale = (maxflaredist - flaredist)/maxflaredist;
	flaremaxsize = (float) (SCREENwidth * this->fMaxSize);
	flarescale = (float) (SCREENwidth * this->fScale);

	// Destination is opposite side of centre from source
	dx = cx + (cx - lx);
	dy = cy + (cy - ly);

	// Render each element.
	std::list<Flare *>::iterator flareIt;
	for (flareIt = this->elements->begin(); flareIt != this->elements->end();
			++flareIt) {
		Flare * element = (*flareIt);

		// Position is interpolated along line between start and destination.
		px = ((1.0f - element->getDistance()) * lx + element->getDistance() * dx);
		py = ((1.0f - element->getDistance()) * ly + element->getDistance() * dy);

		// Piece size are 0 to 1; flare size is proportion of
		// screen width; scale by flaredist/maxflaredist.
		width = flaredistscale * flarescale * element->getSize() ;

		// Width gets clamped, to allows the off-axis flares
		// to keep a good size without letting the elements get
		// too big when centered.
		if (width > flaremaxsize) {
			width = flaremaxsize;
		}

		// Flare elements are square (round) so height is just
		// width scaled by aspect ratio.
		height = HEIGHTFROMWIDTH(width, SCREENheight, SCREENwidth);

		MyMesh * mesh = element->getMesh();

		alpha = flaredistscale * SCALECOLORTO255(mesh->mat.diffuse[3]);

		if (width > 1) {
			float backup = mesh->mat.diffuse[3];
			float diff[] = { mesh->mat.diffuse[0], mesh->mat.diffuse[1],
					mesh->mat.diffuse[2], SCALECOLORTO01(alpha) };
					//SCALECOLORTO01(alpha) };
			memcpy(mesh->mat.diffuse, diff, 4 * sizeof(float));

			element->setPosition(px - width / 2, py - height / 2, 0);
			element->setScale(width, height, 1);
			//Flare flary = (*element);
			element->draw(*this->engine);
			
			diff[3] = backup;
			memcpy(mesh->mat.diffuse, diff, 4 * sizeof(float));
		}
	}
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	this->engine->lights(true);
	this->engine->fog(true);
}

void FlareManager::init() {
	std::list<Flare *>::iterator flareIt;
	for (flareIt = this->elements->begin(); flareIt != this->elements->end(); ++flareIt) {
		(*flareIt)->init();
	}
}
