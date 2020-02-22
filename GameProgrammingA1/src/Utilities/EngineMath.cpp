#include "EngineMath.h"

double distance2d(int x1, int y1, int x2, int y2)
{
    int diffx = x2 - x1;
    int diffy = y2 - y1;

    return sqrt((double) (diffx * diffx) + (diffy * diffy));
}