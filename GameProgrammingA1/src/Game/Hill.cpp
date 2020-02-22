#include "Hill.h"
#include "Random.h"
#include "gfxBindings.h"

Hill::Hill(int floorHeight, int playerBaseColourID, int enemyBaseColourID)
{
    this->floorHeight = floorHeight;
    length = width = height = z = x = 0;
    pBaseColour = playerBaseColourID;
    eBaseColour = enemyBaseColourID;
}

Hill::~Hill()
{

}

bool Hill::generateCoordinates()
{
    Random rand;
    length = rand.getInt(5, WORLDX/3);
    width = rand.getInt(5, WORLDZ/3);
    height = rand.getInt(1, 3);
    z = rand.getInt(1, WORLDZ - width - 1);
    x = rand.getInt(1, WORLDX - length - 1);

    //check if base occupies this spot
    for(int i = x; i < x + length; i++)
        for(int j = z; j < z + width; j++) {
            if(world[i][floorHeight][j] == eBaseColour || world[i][floorHeight][j] == pBaseColour){
                length = width = height = z = x = 0;
                return false;
            }
    }   
    return true;
}

void Hill::generateTerrain()
{
    //printf("Generating hill at: (%d, %d, %d) for length=%d width=%d height=%d\n", x, floorHeight + 1, z, length, width, height);
    int xx = x;
    int zz = z;
    int offset = 0;
    for(int k = floorHeight + 1; k < floorHeight + 1 + height; k++, offset++) {
        xx = x + offset;
        zz = z + offset;
        for(int i = xx; i < x + length - (offset); i++)
            for(int j = zz; j < z + width - (offset); j++)
                world[i][k][j] = GRASS_GREEN; 
            
    }    
}