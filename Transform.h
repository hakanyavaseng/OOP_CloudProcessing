#pragma once
#include <iostream>
#include <Eigen/Dense>
#include "Point.h"
#include "PointCloud.h"


using namespace std;




class Transform {
private:
    // acilari tutan vector
    Eigen::Vector3d *angles;
    // orijinler aras�ndaki uzakl�k fark�n�n kordinatlar�n� veren vekt�r
    Eigen::Vector3d *trans;
    // transformation matrixi
    Eigen::Matrix4d *transMatrix;
    // rotasyon matrisi
    Eigen::Matrix3d *rotationMatrix;

public:
    // Transform s�n�f�n�n constructor fonksiyonu
    Transform() {
        angles = new Eigen::Vector3d;
        trans = new Eigen::Vector3d;
        transMatrix = new Eigen::Matrix4d;
        rotationMatrix = new Eigen::Matrix3d;
    }
    // Transform s�n�f�n�n destructor fonksiyonu
    ~Transform();
    // Bu fonnksiyon alinan aci degerlerini set eder.
    void setAngles(double, double, double);
    // Bu fonksiyon al�nan a�� de�erlerini g�rd���m�z fonksiyon.
    double* getAngles();
    // Bu fonksiyon iki kordinat d�zleminin orijinleri aras�ndaki uzakl�klar� trans arraye de�i�ken olarak atar.
    void setTrans(double, double, double);
    // Burada iki kordinat d�zlemi aras�nda uzakl�k de�erlerini veren x y z de�erlerini d�nd�r�r.
    double* getTrans();
    // Bu fonksiyon set edilen angle degerlerini kullanarak rotation matrix i doldurur
    void setRotation(double ang[3]);
    // Bu fonksiyon bize verilen rotasyon matrisini rotationmatrixe set eder .
    void setRotation(Eigen::Matrix3d ang);

    void setTranslation(double tr[3]);

    void setTranslation(Eigen::Vector3d tr);
    // bu fonksiyon 4x4 transform matrisini olu�turur bunun i�in rotasyonmatrix ve trans nesnesinin x y z sini kullan�r
   
    Point doTransform(Point p);
    // bu fonksiyon nokta bulutunu d�n��t�r�r, d�n��t�r�lm�� nokta bulutunu d�nd�r�r
    PointCloud doTransform(PointCloud& pc);

    list<Point> doTransform(list<Point> lp);

};

