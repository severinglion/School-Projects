#ifndef __HILL_H__
#define __HILL_H__


/*Class to generate hills ontop of a plane*/
class Hill {
public:
    Hill(int floorHeight, int playerBaseColourID, int enemyBaseColourID);
    ~Hill();
    bool generateCoordinates();
    void generateTerrain();

private:
    int length, width, height, x, z;
    int floorHeight;
    int pBaseColour, eBaseColour;
};


#endif // __HILL_H__