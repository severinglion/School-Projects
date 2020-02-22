#include "Valley.h"
#include "Random.h"
#include "gfxBindings.h"

Valley::Valley(int floorHeight, int playerBaseColourID, int enemyBaseColourID)
{
    this->floorHeight = floorHeight;
    x = z = width = length = height = 0;
    pBaseColour = playerBaseColourID;
    eBaseColour = enemyBaseColourID;
    Random rand;
    keepDirt = rand.getInt(0, 1);
}

Valley::~Valley()
{

}

bool Valley::generateCoordinates()
{
    Random rand;
    length = rand.getInt(5, WORLDX/3);
    width = rand.getInt(5, WORLDZ/3);
    height = rand.getInt(-3, -1);
    x = rand.getInt(1, WORLDX - length - 1);
    z = rand.getInt(1, WORLDZ - width - 1);
    int safezone = 1; //leave a single space between a hill and valley
    for(int i = x - safezone; i <= x + length + safezone; i++)
        for(int j = z - safezone; j < z + width + safezone; j++) {
            if(world[i][floorHeight + 1][j] != 0 || world[i][floorHeight][j] == eBaseColour || world[i][floorHeight][j] == pBaseColour ){
                length = width = height = z = x = 0;
                return false;
            }
        }  
    return true;
}

void Valley::generateTerrain()
{
    //printf("Generating valley at: (%d, %d, %d) for length=%d width=%d height=%d\n", x, floorHeight + 1, z, length, width, height);
    int xx = x;
    int zz = z;
    int offset = 0;

    for(int k = floorHeight; k > floorHeight + height; k--, offset++) {
        xx = x + offset;
        zz = z + offset;
        for(int i = xx; i < x + length - (offset); i++)
            for(int j = zz; j < z + width - (offset); j++)
                world[i][k][j] = 0;
            
    }
    
    //cover top facing cubes with grass
    if(!keepDirt){
        for(int k = floorHeight; k > floorHeight + height - 1; k--)
            for(int i = x; i < x + length; i++)
                for(int j = z; j < z + width; j++){
                    if(world[i][k][j] != 0 && world[i][k+1][j] == 0)
                        world[i][k][j] = GRASS_GREEN;
                }
    }
}