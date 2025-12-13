#ifndef _MAP_H_
#define _MAP_H_

#include "Game/utils.h"

class Map{
public:
    Map();
    ~Map();
    
    void Update();
    void Render();

    //Add a rigid object in the map
    void AddObject(IntRect r);
    /*Test the collision of r with all rigid object of the map
    Return the IntRect of the object, or IntRect(0,0) if there is no collision*/
    IntRect GetCollision(IntRect r){
        ObjectCell* o = firstObject;
        while(o != nullptr){
            if(o->rect.Intersect(r))
                return o->rect;
            o = o->nextObject;
        }
        return IntRect(vec2(0, 0), vec2(0,0));
    }

    IntRect Test(){
        return IntRect();
    }

private:
    struct ObjectCell{
        ObjectCell(IntRect r, ObjectCell* n)
            : rect(r), nextObject(n){}

        IntRect rect;
        ObjectCell* nextObject;
    };

    ObjectCell* firstObject;
    ObjectCell* lastObject;
};

#endif