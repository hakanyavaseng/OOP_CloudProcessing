#include "ThreeDGridMap.h"
#include "DepthCamera.h"

ThreeDGridMap::ThreeDGridMap()
{
	// Bu fonksiyon ThreeDGripMap i�in constructor fonksiyonu
}

ThreeDGridMap::ThreeDGridMap(int depth)
{
	// Bu fonksiyon ThreeDGripMap i�in constructor fonksiyonu
	// Depth x,y ve z ekseni do�rultular�ndaki k�p say�s�n� belirtmektedir.
	// bu k�pleri map temsil etmektedir istersek map[3][3] �eklinde de tan�mlayabiliriz 
	map = new bool[depth * depth * depth];
	for (int i = 0; i < depth * depth * depth; i++)
	{
		*(map + i) = false;
	}
}

ThreeDGridMap::~ThreeDGridMap()
{
	// Bu fonksiyon ThreeDGripMap i�in destructor fonksiyonu
}

void ThreeDGridMap::setThreeDGridMap(float gridSize, int depth)
{
	// bu fonksiyon 3d �zgara i�in depth ile x y z eksenlerindeki k�p say�s�n�,
	// gridSize ile k�pleri kenar uzunlu�unu belirtmekte ve set etmektedir.
	// ve depthe g�re bir map olu�turup i�inin bo� oldu�unu belirtmek i�in false ile doldurduk.
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
	// bu fonksiyonda gridSize ve depth al�n�r.
	gridSize = this->gridSize;
	depth = this->depth;
}

void ThreeDGridMap::insertPoint(Point& p)
{
	// bu fonksiyonda gridmap de noktalar�m�z false durumundan true durumuna getirilir
	// yani grid mapimizdeki noktalar bo�ken doldurulur.
	//insert fonksiyonlar� ile, her bir noktan�n hangi k�p�n i�inde kald���n� belirlenip, o k�p�n de�erini true yapmaktad�r
	double x, y, z;
	x = p.getX();
	y = p.getY();
	z = p.getZ();
	int index = ((int)(((z + 3) / gridSize)) * depth * depth + (int)(((y + 3) / gridSize)) * depth + (int)((x + 3) / gridSize));
	map[(int)index] = true;
}

void ThreeDGridMap::insertPointCloud(PointCloud& pc)
{
	// bu fonksiyonda nokta bulutlar� noktalar halinde insertpointe g�nderilir yani tek tek true yap�l�r 
	// nokta bulutlar� true d�nd�r�r gridmapimiz doldurulur 
	// insert fonksiyonlar� ile, her bir noktan�n hangi k�p�n i�inde kald���n� belirlenip, o k�p�n de�erini true yapmaktad�r
	std::list<Point> p;
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		/*p = pc.getPointCloud();
		insertPoint(p);*/
	}
}

bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
	//getGrid fonksiyonu ilgili grid i�in de�er d�nd�rmektedir.
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