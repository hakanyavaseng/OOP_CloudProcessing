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
    // DepthCamera sýnýfý için constructor
    DepthCamera();
    // DepthCamera sýnýfý için destructor
    ~DepthCamera() {}
    // Bu fonksiyon, dosya adini fileName degiskenine set eder.
    void setFileName(string camName);
    // Bu fonksiyon fileName degiskenini return eder.
    string getFileName();
    // bu fonksiyon dosyayý açar okur ve her bir noktayý x y z þeklinde pointclouda set eder
   virtual PointCloud capture();
    /*capture ile baþlangýçta ayný þeyleri yapar sonrasýnda nokta bulutu, üyesi
    olan transform nesnesi ile dönüþtürüldükten sonra döndürülecektir. */
   virtual PointCloud captureFor();
};

