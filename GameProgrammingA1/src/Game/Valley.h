#ifndef __VALLEY_H__
#define __VALLEY_H__

class Valley{
public:
    Valley(int floorHeight, int playerBaseColourID, int enemyBaseColourID);
    ~Valley();

    bool generateCoordinates();
    void generateTerrain();

private:
    int x, z, floorHeight, length, width, height;
    int pBaseColour, eBaseColour;
    int keepDirt;
};

#endif // __VALLEY_H__