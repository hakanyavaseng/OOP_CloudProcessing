#pragma once
#include "Point.h"
#include <list>
using namespace std;
class Point;

class PointCloud
{
private:
    list<Point> points;

public:
    // PointCloud s�n�f� i�in constructor
    PointCloud();
    // PointVloud s�n�f� i�in destructor.
    ~PointCloud();
    // pointclouda bir liste şeklinde point ekler
    void setPointCloud(list<Point>plist);
    // pointclouda bir point ekler.
    void setPointCloud(Point&p);
    // point listesini d�nd�r�r
    list<Point> getPointCloud() const;
    // point dizisinin boyutunu d�nd�r�r
    int getPointNumber() const;
    // PointCloudlar� birle�tirir
    PointCloud operator+(const PointCloud& firstObject);
    // bir PointCloudu di�erine e�itler
    const PointCloud& operator=(const PointCloud& firstObject);
};