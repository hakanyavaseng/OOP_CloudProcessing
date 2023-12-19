#pragma once
#include "Point.h"
#include "PointCloud.h"


using namespace std;

class Map 
{
public:
	Map(){}
	void setMap();
	void getMap();
	virtual void insertPointCloud(PointCloud& pc)=0;
	virtual void insertPoint(Point& p)=0;
	virtual bool loadMap(string fileName)=0;
	virtual bool saveMap(string fileName)=0;
};

