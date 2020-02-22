#include "Random.h"

Random::Random(): eng {std::mt19937(rd())}
{
    
}

Random::~Random()
{

}

int Random::getInt(int min, int max)
{
    std::uniform_int_distribution<int> distro(min, max);
    return distro(eng);
}

float Random::getFloat(float min, float max)
{
    std::uniform_real_distribution<float> distro(min, max);
    return distro(eng);
}