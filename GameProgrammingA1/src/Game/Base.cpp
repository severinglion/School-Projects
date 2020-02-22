#include "Base.h"
#include "Random.h"
#include "gfxBindings.h"

Base::Base(int x, int y, int z, int colourID)
{
    this->x = x;
    this->y = y;
    this->z = z;

    length = width = height = 5;

    colour = colourID;

    //printf("Base: Location (%d, %d, %d)\n", x, y, z);
}

Base::~Base()
{

}

void Base::draw()
{
    for(int i = x; i < x + length; i++)
        for(int j = z; j < z + width; j++)
            world[i][y][j] = colour;

    for(int i = x + 1; i < x + length -1; i++)
        for(int j = z + 1; j < z + width -1; j++)
            for(int k = y + 1; k < y + height - 1; k++)
                world[i][k][j] = colour;
}

