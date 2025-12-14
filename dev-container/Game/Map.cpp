#include "Game/Map.h"

bool GetSceneCollisions(int x, int y, int sx, int sy){
    vec2 v(x, y);
    for(int i = 0; i < NB_OBJECTS; i++)
    {    
        int ind = 4 * (i % 4);
        vec2 pos(objects_sprite[ind + 0] * 1000, objects_sprite[ind + 1] * 1000);
        vec2 size(objects_sprite[ind + 2] * 1000, objects_sprite[ind + 3] * 1000);

        if(!(pos.x >= x + sx || x >= pos.x + size.x
            || pos.y >= y + sy || y >= pos.y + sy))
            return true;
    }
    return false;
}

bool GetSceneCollisions(int x, int y){
    vec2 v(x, y);
    for(int i = 0; i < NB_OBJECTS; i++)
    {    
        int ind = 4 * (i % 4);
        vec2 pos(objects_sprite[ind + 0] * 1000, objects_sprite[ind + 1] * 1000);
        vec2 size(objects_sprite[ind + 2] * 1000, objects_sprite[ind + 3] * 1000);

        if(v.x >= pos.x && v.x < pos.x + size.x
            && v.y >= pos.y && v.y < pos.y + size.y)
            return true;
    }
    return false;
}