#include "Cloud.h"
#include "gfxBindings.h"
#include "Random.h"

Cloud::Cloud(float speed, int cloudHeight)
{
    Random rand;
    this->speed = speed;
    pooledTime = 0;
    poolLimit = 1;
    dy = cloudHeight;
    x = rand.getInt(3, 6);
    y = rand.getInt(3, 4);
    z = rand.getInt(3, 6);
    colour = rand.getInt(CLOUD_WHITE, CLOUD_GREY);
}

Cloud::~Cloud()
{

}

void Cloud::update(float delta)
{
    pooledTime += delta;
    if( pooledTime >= poolLimit ){
        dz += delta * speed;
        if(dz > 99)
            dz -= 99;
        draw();
    }

}

bool Cloud::generateModel()
{
    Random rand;
    dx = rand.getInt(0, WORLDX);
    dz = rand.getInt(0, WORLDZ);
    for(int i = (int)dx; i < x + dx; i++)
        for(int j = (int)dz; j < z + dz; j++)
            for(int k = (int)dy; k > dy - y; k--){
                if(world[i][k][j] != 0)
                    return false;
            }
    return true;
}

void Cloud::draw()
{
    //draw rectangular prism
    for(int i = (int)dx; i < x + dx; i++)
        for(int j = (int)dz; j < z + dz; j++)
            for(int k = (int)dy; k > dy - y; k--){
                world[i][k][j] = colour;
            }

    //remove the 8 corners
    world[(int)dx][(int)dy][(int)dz] = 0;
    world[(int)dx][(int)dy - y + 1][(int)dz] = 0;
    world[(int)dx + x - 1][(int)dy][(int)dz] = 0;
    world[(int)dx + x - 1][(int)dy - y + 1][(int)dz] = 0;

    world[(int)dx][(int)dy][((int)dz + z )] = 0;
    world[(int)dx][(int)dy - y + 1][(int)dz + z] = 0;
    world[(int)dx + x - 1][(int)dy][(int)dz + z] = 0;
    world[(int)dx + x - 1][(int)dy - y + 1][(int)dz + z] = 0;
    
}