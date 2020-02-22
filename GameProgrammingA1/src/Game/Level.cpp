#include "Level.h"
#include "Random.h"
#include "Hill.h"
#include "Valley.h"
#include "EngineMath.h"
#include "Cloud.h"
#include <stdio.h>

Level::Level(int ceiling, int floor, int hillCount, int valleyCount, int cloudCount)
{
    viewCeiling = ceiling;
    viewFloor = floor;
    hillDensity = hillCount;
    valleyDensity = valleyCount;
    cloudDensity = cloudCount;
    playerBase = nullptr;
    enemyBase = nullptr;
    pBaseColour = GREY;
    eBaseColour = RED;
}

Level::~Level()
{
    delete playerBase;
    delete enemyBase;
}

void Level::generateTerrain()
{

    //printf("Generating Terrain as such\n");
    //printf("View Ceiling = %d, View Floor = %d, Hill Density = %d, Valley Density = %d\n",
    viewCeiling, viewFloor, hillDensity, valleyDensity);
    for(int x = 0; x < WORLDX; x++)
        for(int z = 0; z < WORLDZ; z++)
            for(int y = 0; y <= viewFloor; y++) {
                if(y == viewFloor)
                    world[x][viewFloor][z] = GRASS_GREEN;
                else
                    world[x][y][z] = BROWN;
            }

    // add bases
    //printf("Placing bases ...\n");
    Random rand;
    bool suitableDistance = false;
    int pBaseX, pBaseZ, eBaseX, eBaseZ;
    int edgeOffset = 5;
    while(!suitableDistance){
        pBaseX = rand.getInt(edgeOffset, WORLDX - edgeOffset - Base::defaultSize);
        pBaseZ = rand.getInt(edgeOffset, WORLDZ - edgeOffset - Base::defaultSize);

        eBaseX = rand.getInt(edgeOffset, WORLDZ - edgeOffset - Base::defaultSize);
        eBaseZ = rand.getInt(edgeOffset, WORLDZ - edgeOffset - Base::defaultSize);
        double dist = distance2d(pBaseX, pBaseZ, eBaseX, eBaseZ);

        if(dist > 50 && dist < 100)
            suitableDistance = true;
    }
    playerBase = new Base(pBaseX, viewFloor, pBaseZ, pBaseColour);
    enemyBase = new Base(eBaseX, viewFloor, eBaseZ, eBaseColour);

    playerBase->draw();
    enemyBase->draw();

     // add hills
    printf("Generating hills ... \n");
    for(int i = 0; i < hillDensity; i++){
        Hill* hill = new Hill(viewFloor, pBaseColour, eBaseColour);
        hills.push_back(hill);
        while(!hill->generateCoordinates()) ;
        hill->generateTerrain();
        
    }
    // add valleys  
    //printf("Generating valleys ... \n");
    for(int i = 0; i < valleyDensity; i++){
        Valley* valley = new Valley(viewFloor, pBaseColour, eBaseColour);
        valleys.push_back(valley);
        while (!valley->generateCoordinates()) ;
        valley->generateTerrain();
    }

    // add clouds
    //printf("Generating clouds ... \n");
    for(int i = 0; i < cloudDensity; i++){
        int cloudHeight;
        int speed;
        if(i % 2){
            cloudHeight = rand.getInt(47, 49);
            speed = rand.getFloat(1, 1.5);
        }
        else{
            cloudHeight = rand.getInt(38, 41);
            speed = rand.getFloat(2, 3.5);
        }
        Cloud* cloud = new Cloud(speed, cloudHeight);
        clouds.push_back(cloud);
        while(!cloud->generateModel()) ;
        cloud->draw();
    }
}

void Level::update(float delta)
{
    //reload terrain and bases
    for(int x = 0; x < WORLDX; x++)
        for(int z = 0; z < WORLDZ; z++)
            for(int y = 0; y <= viewFloor; y++) {
                if(y == viewFloor)
                    world[x][viewFloor][z] = GRASS_GREEN;
                else
                    world[x][y][z] = BROWN;
            }

    playerBase->draw();
    enemyBase->draw();

    for(std::list<Hill*>::iterator it = hills.begin(); it != hills.end(); it++)
        (*it)->generateTerrain();

    for(std::list<Valley*>::iterator it = valleys.begin(); it != valleys.end(); it++)
        (*it)->generateTerrain();


}
