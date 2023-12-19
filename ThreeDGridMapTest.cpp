#include<iostream>
#include"Point.h"
#include "ThreeDGridMap.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
using namespace std;

void GridMapTest()
{
	cout << "\n 3D GRID MAP TEST" << endl;
	cout << " -----------------------------------------------" << endl;
	ThreeDGridMap tgm(10);
	PointCloud pc;
	PointCloudRecorder rec;
	DepthCamera dc;
	tgm.setThreeDGridMap(1, 10);
	cout << " ";
	tgm.loadMap("ThreeDGridMapTest.txt");
	tgm.saveMap("MAP_ThreeDGridMapTest.txt");
	cout << " -----------------------------------------------" << endl;
}
