#pragma once
#include "PointCloudGenerator.h"
#include <iostream>
#include <fstream>
#include <string>
#include "PointCloud.h"
using namespace std;

class DepthCamera : public PointCloudGenerator
{

private:
    string fileName;

public:
    // DepthCamera s�n�f� i�in constructor
    DepthCamera();
    // DepthCamera s�n�f� i�in destructor
    ~DepthCamera() {}
    // Bu fonksiyon, dosya adini fileName degiskenine set eder.
    void setFileName(string camName);
    // Bu fonksiyon fileName degiskenini return eder.
    string getFileName();
    // bu fonksiyon dosyay� a�ar okur ve her bir noktay� x y z �eklinde pointclouda set eder
   virtual PointCloud capture();
    /*capture ile ba�lang��ta ayn� �eyleri yapar sonras�nda nokta bulutu, �yesi
    olan transform nesnesi ile d�n��t�r�ld�kten sonra d�nd�r�lecektir. */
   virtual PointCloud captureFor();
};

