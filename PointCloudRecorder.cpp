#include "PointCloudRecorder.h"
#include <iterator>
#include <string>
#include <list>
PointCloudRecorder::PointCloudRecorder()
{
	// bu fonksiyon PointCloudRecorder sýnýfýnýn constructoru
}

PointCloudRecorder::~PointCloudRecorder()
{
	// bu fonksiyon PointCloudRecorder sýnýfýnýn destructoru
}

void PointCloudRecorder::setFileName(string camName)
{
	//Bu fonksiyon, dosya adini fileName degiskenine set eder.
	this->fileName = camName;
}

string PointCloudRecorder::getFileName()
{
	//Bu fonksiyon fileName degiskenini return eder.
	return fileName;
}

bool PointCloudRecorder::save(const PointCloud& pc)
{
	list<Point> pointList;
	pointList = pc.getPointCloud();
	// bu fonksiyon nokta bulutlarýný dosyaya kaydeder
	string outputFileName = getFileName();
	outputFileName = "processed_" + outputFileName;

	ofstream outputFile(outputFileName);

	cout << "Dosya: " << getFileName() << " isleniyor..." << endl;

	if (outputFile.is_open())
	{
		int size = pc.getPointNumber();
		Point p;
		outputFile << "X	Y	Z" << endl;
		outputFile << size << endl;

		list<Point>::iterator it;

		for (it = pointList.begin(); it != pointList.end(); it++)
		{
			outputFile << it->getX() << " " << it->getY() << " " << it->getZ() << endl;
		}
		cout << "Dosya islendi. " << outputFileName << " olarak proje klasorune kaydedildi." << endl;

		outputFile.close();
	}



	return true;
}
