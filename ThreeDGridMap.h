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
    // Bu fonksiyon ThreeDGripMap i�in constructor fonksiyonu
    ThreeDGridMap();
    // Bu fonksiyon ThreeDGripMap i�in constructor fonksiyonu
    ThreeDGridMap(int depth);
    // Bu fonksiyon ThreeDGripMap i�in destructor fonksiyonu
    ~ThreeDGridMap();
    // Depthe uygun bir 3dgrid amp set ettik.
    void setThreeDGridMap(float gridSize, int depth);
    // bu fonksiyonda gridSize ve depth al�n�r.
    void getThreeDGridMap(float& gridSize, int& depth);
    // bu fonksiyon noktalar�m�z� true yapar
    void insertPoint(Point& p);
    // bu fonksiyon nokta bulutlar�n� true yapar
    void insertPointCloud(PointCloud& pc);
    // getGrid fonksiyonu ilgili grid i�in de�er d�nd�rmektedir.
    bool getGrid(int x, int y, int z) const;
    //
    bool loadMap(string fileName);
    bool saveMap(string fileName);
};

