#include "DepthCamera.h"


DepthCamera::DepthCamera()
{
	//DepthCamera sýnýfý için constructor
}

void DepthCamera::setFileName(string camName)
{
	//Bu fonksiyon, dosya adini fileName degiskenine set eder.
	this->fileName = camName;
}

string DepthCamera::getFileName()
{
	//Bu fonksiyon fileName degiskenini return eder.
	return fileName;
}

PointCloud DepthCamera::capture()
{
	//Bu fonksiyon koordinat dosyasini acar ve her bir noktayi
	//x, y ve z seklinde set eder.
	double** cloud;
	string line;
	string txt = DepthCamera::getFileName();
	ifstream inputFile(txt);
	int noOfPoints = 0;

	while (getline(inputFile, line))
		noOfPoints++;

	noOfPoints = noOfPoints - 2;

	PointCloud pc;
	list<Point> pcl(noOfPoints);
	pc.setPointCloud(pcl);

	cout << "Dosya: " << getFileName() << ", Nokta sayisi: " << noOfPoints << endl;



	//New operatoru ile cloud adýnda bir dinamik array olusturma
	cloud = new double* [noOfPoints];

	for (int i = 0; i < noOfPoints; i++) {
		cloud[i] = new double[3];
	}


	ifstream inputFile2(txt);

	string skipLine;
	char ignoreRGB[100];

	inputFile2.getline(ignoreRGB, 100);
	inputFile2.getline(ignoreRGB, 100);

	Point tmp;
	list<Point> pointList;
	for (int i = 0; i < noOfPoints; i++)
	{


		for (int j = 0; j < 3; j++)
		{
			inputFile2 >> cloud[i][j];
		}

		tmp.setPoint(cloud[i][0], cloud[i][1], cloud[i][2]);
		pointList.push_back(tmp);

	}

	pc.setPointCloud(pointList);

	for (int i = 0; i < noOfPoints; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cloud[i][j] = 0;
		}
	}

	


	return pc;
}

// Bu fonksiyon camera(sayi).txt dosyalarinin icerisindeki noktalari okur ve bir Point nesnesinin icerisine atar.Daha sonra 
// filtrelerden gecirir, transform eder ve yeni degerleri PointCloud nesnesinin icerisine atar ve o PointCloud nesnesini dondurur.
PointCloud DepthCamera::captureFor()
{
	PointCloud temp1 = this->capture();
	PointCloud temp2;
	Transform T = PointCloudGenerator::getTransform();


	temp2 = T.doTransform(temp1);

	
	
	return temp2;
}
//PointCloud DepthCamera::captureFor()
//{
//	return 
//
//}
