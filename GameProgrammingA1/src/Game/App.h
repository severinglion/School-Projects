#ifndef __APP_H__
#define __APP_H__

#include "gfxBindings.h"
#include "Level.h"
#include "UpdateManager.h"

#define XLIM -99.9
#define YLIM -25
#define YMIN -3 
#define ZLIM -99.9

class App {
public:
    App();
    ~App();

    /*Initialize any game related objects here*/
    void init();

    /*Collision handling related function*/
    void handleCollision();
    
    /*Update callback function*/
    void update(float delta);

    /*Mouse event function*/
    void mouse(int button, int state, int x, int y);

    /*Interface function*/
    void draw2D();

private:
    //Game related storage should happen here
    Level* level;
    UpdateManager* updateManager;

};

#endif // __APP_H__