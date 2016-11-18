/*
 * FlareManager.h
 *
 *  Created on: Nov 19, 2014
 *      Author: ricardo
 */

#ifndef FLAREMANAGER_H_
#define FLAREMANAGER_H_

#include "GameObjects/Flare.h"
#include <list>

class FlareManager {
    private:
        float fScale;  // Scale factor for adjusting overall size of flare elements.
        float fMaxSize; // Max size of largest element, as proportion of screen width (0.0-1.0)

        std::list<Flare*>* elements;

        Engine* engine;

        void loadFlareFile(char* filename);

    public:
        FlareManager(Engine* engine);

        virtual ~FlareManager();

        void renderFlare(int lx, int ly, int cx, int cy, float SCREENheight,
                         float SCREENwidth);

        void init();

        Engine* getEngine() {
            return engine;
        }

        void setEngine(Engine* engine) {
            this->engine = engine;
        }


};

#endif /* FLAREMANAGER_H_ */
