#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>

class Random{
public:
    Random();
    ~Random();

    int getInt(int min, int max);
    float getFloat(float min, float max);    

private:
    std::random_device rd;
    std::mt19937 eng;
};

#endif //__RANDOM_H__