#include "UpdateManager.h"
#include "Tickable.h"

UpdateManager* UpdateManager::getInstance()
{
    if(!instance)
        instance = new UpdateManager();
    return instance;
}

void UpdateManager::addObject(Tickable* obj)
{
    objs.push_back(obj);
}

void UpdateManager::removeObject(Tickable* obj)
{
    objs.remove(obj);
}

void UpdateManager::updateObjects(float delta)
{
    for(std::list<Tickable*>::iterator it = objs.begin(); it != objs.end(); it++){
        (*it)->update(delta);
    }
}