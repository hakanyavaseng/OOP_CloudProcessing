#pragma once
#include "PointCloud.h"

using namespace std;

class PointCloudRecorder 
{
private:
    string fileName;

public:
    // bu fonksiyon PointCloudRecorder s�n�f�n�n constructoru
    PointCloudRecorder();
    // bu fonksiyon PointCloudRecorder s�n�f�n�n destructoru
    ~PointCloudRecorder();
    // bu fonksiyon
    void setFileName(string);
    // bu fonksiyon
    string getFileName();
    // bu fonksiyon nokta bulutlar�n� dosyaya kaydeder
    bool save(const PointCloud& pc);
};

