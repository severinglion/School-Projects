#include "App.h"
#include <stdio.h>
#include <cmath>

App::App()
{
    level = new Level();
    updateManager = UpdateManager::getInstance();
}

App::~App()
{
    delete level;
}

void App::init()
{
    //set user generated colour
    setUserColour(BROWN, 0.32, 0.18, 0.06, 0, 0.32, 0.18, 0.06, 0);
    setUserColour(GREY, 0.5, 0.5, 0.5, 0, 0.55, 0.55, 0.55, 0);
    setUserColour(CLOUD_WHITE, 1, 1, 1, 1, 1, 1, 1, 1);
    setUserColour(CLOUD_GREY, 1, 1, 1, 0.5, 0.8, 0.8, 0.8, 0.5);
    setUserColour(GRASS_GREEN, 0.07, 0.68, 0.03, 1, 0.07, 0.37, 0.03, 1);


    //Generate level
    level->generateTerrain();

    setViewPosition(-1, -10, -1);
}

void App::handleCollision()
{
    float viewx, viewy, viewz;
    float oldx, oldy, oldz;
    float diffx, diffy, diffz;
    float nextx, nexty, nextz;
    float deadzone = 2.5; 

    getViewPosition(&viewx, &viewy, &viewz);
    getOldViewPosition(&oldx, &oldy, &oldz);

    diffx = deadzone * (viewx - oldx);
    diffy = deadzone * (viewy - oldy);
    diffz = deadzone * (viewz - oldz);

    nextx = viewx + diffx;
    nexty = viewy + diffy;
    nextz = viewz + diffz;
    
    //keep vp in playable area
    if(viewx > 0 || viewx < XLIM || viewy > YMIN || viewy < YLIM || viewz > 0 || viewz < ZLIM){
        //bound view position x axis to world space
        if(viewx > 0){
            viewx = 0.f;
        } 
        else if (viewx < XLIM){
            viewx = XLIM;
        }

        //bind view position y axis to playable space
        if(viewy < YLIM){
            viewy = YLIM;
        }
        else if (viewy > YMIN){
            viewy = YMIN;
        }

        //bind view position z axis to world space
        if (viewz > 0)
            viewz = 0;
        else if (viewz < ZLIM)
            viewz = ZLIM;

        setViewPosition(viewx, viewy, viewz);
    }

    //ensure vp doesn't occupy another occupied space
    float cubex = fabs(nextx);
    float cubey = fabs(nexty);
    float cubez = fabs(nextz);
    
    if(world[(int)cubex][(int)cubey][(int)cubez] != 0){
        //printf("VP = (%.2f, %.2f, %.2f), checking cube (%.f, %.f, %.f)\n", viewx, viewy, viewz, cubex, cubey, cubez);
        float oldCubeX = fabs(oldx);
        float oldCubeY = fabs(oldy);
        float oldCubeZ = fabs(oldz);

        //printf("VP = (%.2f, %.2f, %.2f), checking cube (%.f, %.f, %.f)\n", viewx, viewy, viewz, cubex, oldCubeY, oldCubeZ);
        //check facing walls
        if(world[(int)cubex][(int)oldCubeY][(int)oldCubeZ] != 0)
            viewx = oldx;

        //printf("VP = (%.2f, %.2f, %.2f), checking cube (%.f, %.f, %.f)\n", viewx, viewy, viewz, oldCubeX, cubey, oldCubeZ);
        if(world[(int)oldCubeX][(int)cubey][(int)oldCubeZ] != 0)
            viewy = oldy;

        //printf("VP = (%.2f, %.2f, %.2f), checking cube (%.f, %.f, %.f)\n\n", viewx, viewy, viewz, oldCubeX, oldCubeY, cubez);
        if(world[(int)oldCubeX][(int)oldCubeY][(int)cubez] != 0)
            viewz = oldz;
        
        setViewPosition(viewx, viewy, viewz);        
    }      
/*         if(world[(int)cubex][(int)cubey][(int)cubez] != 0){
        float oldCubeX = fabs(oldx);
        float oldCubeY = fabs(oldy);
        float oldCubeZ = fabs(oldz);
        
        float subx = cubex - floor(cubex);
        float suby = cubey - floor(cubey);
        float subz = cubez - floor(cubez);

        if((subx > 0.99 || subx < 0.099) && world[(int)cubex][(int)oldCubeY][(int)oldCubeZ] != 0)
            viewx = oldx;
        
        if((suby > 0.99 || suby < 0.099) && world[(int)oldCubeX][(int)cubey][(int)oldCubeZ] != 0)
            viewy = oldy;
        
        if((subz > 0.99 || subz < 0.099) && world[(int)oldCubeX][(int)oldCubeY][(int)cubez] != 0)
            viewz = oldz;

        setViewPosition(oldx, oldy, oldz);        
    }     */

}

void App::update(float delta)
{
    //clear the world array 
    for(int x = 0; x < WORLDX; x++)
        for(int z = 0; z < WORLDZ; z++)
            for(int y = 0; y < WORLDY; y++) 
                world[x][y][z] = 0; 
                
    //update world array with current positions
    updateManager->updateObjects(delta);
}

void App::mouse(int button, int state, int x, int y)
{

}

void App::draw2D()
{

}