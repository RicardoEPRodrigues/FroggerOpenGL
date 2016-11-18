/*
 * ComposedElement.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ricardo
 */

#ifndef COMPOSEDOBJECT_H_
#define COMPOSEDOBJECT_H_

#include "GameObject.h"

#ifndef LIST_
#define LIST_

#include <list>

#endif // LIST_

class ComposedObject : public virtual GameObject {
    private:
        std::list<GameObject*>* elems;

        void localInit();

    protected:
        void drawInside(Engine engine);

        void addElement(GameObject* element);

    public:
        ComposedObject();

        virtual ~ComposedObject();

        void init();

};

#endif /* COMPOSEDOBJECT_H_ */
