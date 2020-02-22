#ifndef __TICKABLE_H__
#define __TICKABLE_H__


class Tickable {
public: 
    Tickable();
    ~Tickable();
    virtual void update(float delta) = 0;

private: 
    class UpdateManager* updateManager;
};

#endif // __TICKABLE_H__