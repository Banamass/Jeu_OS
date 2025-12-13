#include "Game/Map.h"

Map::Map() 
    : firstObject(nullptr), lastObject(nullptr)
{}
Map::~Map(){
    
}

void Map::Update(){
    
}
void Map::Render(){

}

void Map::AddObject(IntRect r){
    ObjectCell* newO = new ObjectCell(r, nullptr);
    if(firstObject == nullptr){
        firstObject = newO;
        lastObject = newO;
    }
    else{
        lastObject->nextObject = newO;
        lastObject = newO;
    }
}