#include "Tickable.h"
#include "UpdateManager.h"

Tickable::Tickable() 
{
    updateManager = UpdateManager::getInstance();
    updateManager->addObject(this);
}

Tickable::~Tickable()
{
    updateManager->removeObject(this);
}