#include "ThreeDGridMap.h"
#include "DepthCamera.h"

ThreeDGridMap::ThreeDGridMap()
{
	// Bu fonksiyon ThreeDGripMap için constructor fonksiyonu
}

ThreeDGridMap::ThreeDGridMap(int depth)
{
	// Bu fonksiyon ThreeDGripMap için constructor fonksiyonu
	// Depth x,y ve z ekseni doðrultularýndaki küp sayýsýný belirtmektedir.
	// bu küpleri map temsil etmektedir istersek map[3][3] þeklinde de tanýmlayabiliriz 
	map = new bool[depth * depth * depth];
	for (int i = 0; i < depth * depth * depth; i++)
	{
		*(map + i) = false;
	}
}

ThreeDGridMap::~ThreeDGridMap()
{
	// Bu fonksiyon ThreeDGripMap için destructor fonksiyonu
}

void ThreeDGridMap::setThreeDGridMap(float gridSize, int depth)
{
	// bu fonksiyon 3d ýzgara için depth ile x y z eksenlerindeki küp sayýsýný,
	// gridSize ile küpleri kenar uzunluðunu belirtmekte ve set etmektedir.
	// ve depthe göre bir map oluþturup içinin boþ olduðunu belirtmek için false ile doldurduk.
	this->gridSize = gridSize;
	this->depth = depth;
	map = new bool[depth * depth * depth];
	for (int i = 0; i < depth * depth * depth; i++)
	{
		*(map + i) = false;
	}
}

void ThreeDGridMap::getThreeDGridMap(float& gridSize, int& depth)
{
	// bu fonksiyonda gridSize ve depth alýnýr.
	gridSize = this->gridSize;
	depth = this->depth;
}

void ThreeDGridMap::insertPoint(Point& p)
{
	// bu fonksiyonda gridmap de noktalarýmýz false durumundan true durumuna getirilir
	// yani grid mapimizdeki noktalar boþken doldurulur.
	//insert fonksiyonlarý ile, her bir noktanýn hangi küpün içinde kaldýðýný belirlenip, o küpün deðerini true yapmaktadýr
	double x, y, z;
	x = p.getX();
	y = p.getY();
	z = p.getZ();
	int index = ((int)(((z + 3) / gridSize)) * depth * depth + (int)(((y + 3) / gridSize)) * depth + (int)((x + 3) / gridSize));
	map[(int)index] = true;
}

void ThreeDGridMap::insertPointCloud(PointCloud& pc)
{
	// bu fonksiyonda nokta bulutlarý noktalar halinde insertpointe gönderilir yani tek tek true yapýlýr 
	// nokta bulutlarý true döndürür gridmapimiz doldurulur 
	// insert fonksiyonlarý ile, her bir noktanýn hangi küpün içinde kaldýðýný belirlenip, o küpün deðerini true yapmaktadýr
	std::list<Point> p;
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		/*p = pc.getPointCloud();
		insertPoint(p);*/
	}
}

bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
	//getGrid fonksiyonu ilgili grid için deðer döndürmektedir.
	int index = ((int)(((z + 3) / gridSize)) * depth * depth + (int)(((y + 3) / gridSize)) * depth + (int)((x + 3) / gridSize));
	return this->map[index];
}

bool ThreeDGridMap::loadMap(string fileName)
{
	DepthCamera dC;
	dC.setFileName(fileName);
	PointCloud pC = dC.capture();
	insertPointCloud(pC);
	return true;
}

bool ThreeDGridMap::saveMap(string fileName)
{
	std::fstream file(fileName, std::ios::app);
	string tmp;
	double x, y, z;
	if (file.is_open()) {
		for (int i = 0; i < depth * depth * depth; ++i) {
			if (*(map + i)) {
				x = i % depth;
				y = (i % (depth * depth) - x) / depth;
				z = (i - (y * depth + x)) / (depth * depth);
				file << x << " " << y << " " << z << endl;
			}
		}
		return true;
	}
	else {
		cout << "file cannot opened!" << endl;
	} return false;

}