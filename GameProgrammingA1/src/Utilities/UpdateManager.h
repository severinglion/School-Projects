#ifndef __UPDATEMANAGER_H__
#define __UPDATEMANAGER_H__

class Tickable;
#include<list>

class UpdateManager{
public:
    static UpdateManager* getInstance();
    
    
    UpdateManager(UpdateManager const&) = delete;
    void operator=(UpdateManager const&) = delete;

    void addObject(Tickable* obj);
    void removeObject(Tickable* obj);
    void updateObjects(float delta);

private:
    UpdateManager() {}
    std::list<Tickable*> objs;
};

static UpdateManager* instance;

#endif // __UPDATEMANAGER_H__