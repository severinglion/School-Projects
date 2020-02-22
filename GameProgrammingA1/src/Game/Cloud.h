#ifndef __CLOUD_H__
#define __CLOUD_H__

#include "Tickable.h"

class Cloud : public Tickable {
public: 
    Cloud(float speed, int y);
    ~Cloud();

    void update(float delta) override;
    bool generateModel();
    void draw();

private:


    int x, y, z; //length height width of cloud box
    float dx, dy, dz;
    float speed;
    float pooledTime;
    float poolLimit;
    int colour;
};

#endif //__CLOUD_H__