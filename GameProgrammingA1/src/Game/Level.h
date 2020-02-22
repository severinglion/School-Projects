#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <list>
#include "gfxBindings.h"
#include "Base.h"
#include "Tickable.h"
class Hill;
class Valley;
class Cloud;

class Level : public Tickable {
public:
    Level(int ceiling = 20, int floor = 5, int hillCount = 25, int valleyCount = 25, int cloudDensity = 60);
    ~Level();

    void generateTerrain();

    void update(float delta) override;

    //getters
    int getViewCeiling() {return viewCeiling;}
    int getViewFloor() {return viewFloor;}
    int getHillDensity() {return hillDensity;}
    int getValleyDensity() {return valleyDensity;}

private:
    int viewCeiling;
    int viewFloor;
    int hillDensity;
    int valleyDensity;
    int cloudDensity;
    Base *playerBase, *enemyBase;
    int pBaseColour, eBaseColour;
    std::list<Hill*> hills;
    std::list<Valley*> valleys;
    std::list<Cloud*> clouds;
};


#endif //__LEVEL_H__