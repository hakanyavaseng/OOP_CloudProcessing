#pragma once
#include "Map.h"
#include "Point.h"
#include "PointCloud.h"
using namespace std;

class ThreeDGridMap :
    public Map
{
private:
    bool* map;
    float gridSize;
    int depth;

public:
    // Bu fonksiyon ThreeDGripMap için constructor fonksiyonu
    ThreeDGridMap();
    // Bu fonksiyon ThreeDGripMap için constructor fonksiyonu
    ThreeDGridMap(int depth);
    // Bu fonksiyon ThreeDGripMap için destructor fonksiyonu
    ~ThreeDGridMap();
    // Depthe uygun bir 3dgrid amp set ettik.
    void setThreeDGridMap(float gridSize, int depth);
    // bu fonksiyonda gridSize ve depth alýnýr.
    void getThreeDGridMap(float& gridSize, int& depth);
    // bu fonksiyon noktalarýmýzý true yapar
    void insertPoint(Point& p);
    // bu fonksiyon nokta bulutlarýný true yapar
    void insertPointCloud(PointCloud& pc);
    // getGrid fonksiyonu ilgili grid için deðer döndürmektedir.
    bool getGrid(int x, int y, int z) const;
    //
    bool loadMap(string fileName);
    bool saveMap(string fileName);
};

