#ifndef __BASE_H__
#define __BASE_H__

class Base{
public:
    Base(int x, int y, int z, int colour);
    ~Base();

    void draw();
    static const int defaultSize = 6;
    
private:
    int x, y, z;
    int length, width, height;
    int colour;
};


#endif //__BASE_H__